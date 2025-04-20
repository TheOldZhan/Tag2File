#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileTools.h"

#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QProcess>
#include <QDesktopServices>
#include <QThread>
#include <QVector>
#include <QString>
#include <QInputDialog>
#include <QJsonDocument>
#include <QListWidget>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SearchContent->addItems({"搜索名字", "搜索标签"});
    const auto leftModel = new QStandardItemModel(this);
    ui->RecordedFiles->setModel(leftModel);
    const auto filteredModel = new QStandardItemModel(this);
    ui->FilteredFiles->setModel(filteredModel);
    //给按钮添加提示
    ui->BrowseBT->setToolTip("从选定目录添加文件");
    ui->AddBT->setToolTip("选择一个文件添加");
    ui->ClearLBT->setToolTip("清空导入的文件");
    ui->ClearRBT->setToolTip("清空搜索结果");
    ui->OpenFileBT->setToolTip("打开选定的文件所在目录");
    ui->SearchStart->setToolTip("点击搜索");
    listContextMenu = new QMenu(this);
    addTagAction = new QAction("添加标签", this);
    listContextMenu->addAction(addTagAction);
    ui->RecordedFiles->setContextMenuPolicy(Qt::CustomContextMenu);
    //禁用列表的编辑功能
    ui->RecordedFiles->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->FilteredFiles->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //读取数据
    if (isUserDataExist())
    {
        QFile file("USERDATA");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, "错误", "无法打开数据文件");
            return;
        }
        const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonArray jsonArray = doc.array();
        for (const auto& val : jsonArray)
        {
            QJsonObject obj = val.toObject();
            if (QString filePath = obj["path"].toString(); QFileInfo(filePath).exists())
            {
                FileInfo info = FileInfo::fromJson(obj);
                fileList.push_back(info);
                Add2leftList(info);
            }
        }
        file.close();
    }
    //按钮事件连接
    connect(ui->BrowseBT, &QPushButton::clicked, this, &MainWindow::onBrowseButtonClicked);
    connect(ui->AddBT, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(ui->ClearLBT, &QPushButton::clicked, this, &MainWindow::onClearLButtonClicked);
    connect(ui->DeleteSelectedItem, &QPushButton::clicked, this, &MainWindow::onDeleteSelectedButtonClicked);
    connect(ui->ClearRBT, &QPushButton::clicked, this, &MainWindow::onClearRButtonClicked);
    connect(ui->OpenFileBT, QPushButton::clicked, this, &MainWindow::onOpenFileOnExplorerButtonClicked);
    connect(ui->SearchStart, QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    //ListView事件连接
    connect(ui->RecordedFiles, &QListView::doubleClicked, this, &MainWindow::openAFile);
    connect(ui->FilteredFiles, &QListView::doubleClicked, this, &MainWindow::openAFile);
    connect(ui->RecordedFiles->selectionModel(),
            &QItemSelectionModel::selectionChanged, this,
            &MainWindow::onLeftSelectionChanged);
    connect(ui->FilteredFiles->selectionModel(),
            &QItemSelectionModel::selectionChanged, this,
            &MainWindow::onRightSelectionChanged);
    connect(addTagAction, &QAction::triggered, this, &MainWindow::onAddTagClicked);
    connect(ui->RecordedFiles, &QListView::customContextMenuRequested, this, &MainWindow::showListContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Add2leftList(FileInfo& info) const
{
    const QString displayText = QString("%1 (%2)").arg(info.getName()).arg(info.getType());
    const auto item = new QStandardItem(displayText);
    item->setData(info.getPath(), Qt::UserRole);
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    const QString tags = info.getTags().join(", ");
    item->setToolTip(QString("添加时间: %1\n标签: %2").arg(info.getAddedDatetime()).arg(tags));

    if (const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model())) model->appendRow(item);
}

void MainWindow::AddVec2LeftList(vector<QString>& s)
{
    if (const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model()); !model) return;
    for (auto& info : fileList)
    {
        if (std::find(s.begin(), s.end(), info.getPath()) != s.end())
        {
            Add2leftList(info);
        }
    }
}

void MainWindow::Add2rightList(const QString& displayText, const QString& filePath) const
{
    const auto model = qobject_cast<QStandardItemModel*>(ui->FilteredFiles->model());
    if (!model) return;
    const auto item = new QStandardItem(displayText);
    item->setData(filePath, Qt::UserRole);
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    model->appendRow(item);
}

void MainWindow::saveToJson() const
{
    QJsonArray jsonArray;
    for (const auto& info : fileList)
    {
        jsonArray.append(info.toJson());
    }
    QFile file("USERDATA");
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(nullptr, "错误", "无法写入USERDATA文件: " + file.errorString());
        return;
    }
    file.write(QJsonDocument(jsonArray).toJson());
    file.close();
}

void MainWindow::RemoveAFile(const QString& s)
{
    if (const QFileInfo fileInfo(s); !fileInfo.exists())
    {
        QMessageBox::warning(this, "错误", "文件不存在：" + s);
        return;
    }
    if (QFile file(s); !file.remove())
    {
        QMessageBox::critical(this, "错误",
                              QString("无法删除文件：%1\n错误：%2")
                              .arg(s)
                              .arg(file.errorString()));
        return;
    }
    if (isUserDataExist())
    {
        vector<QString> remainingPaths;
        ifstream fin("USERDATA");
        string line;
        while (getline(fin, line))
        {
            if (QString currentPath = QString::fromStdString(line).trimmed(); currentPath != s)
            {
                remainingPaths.push_back(currentPath);
            }
        }
        fin.close();
        saveToJson();
    }
    const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model());
    if (!model) return;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        const QStandardItem* item = model->item(i);
        if (item->data(Qt::UserRole).toString() == s)
        {
            model->removeRow(i);
            break;
        }
    }
    for (auto it = fileList.begin(); it != fileList.end();)
    {
        if (it->getPath() == s) it = fileList.erase(it);
        else ++it;
    }
    QMessageBox::information(this, "成功", "文件已删除：" + s);
}

void MainWindow::RemoveLAll()
{
    const int result = QMessageBox::warning(this, "警告",
                                            "该操作将删除全部数据（YesALl包括用户数据）",
                                            QMessageBox::No | QMessageBox::Yes | QMessageBox::YesAll);
    if (result == QMessageBox::Yes || result == QMessageBox::YesAll)
    {
        if (const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model())) model->clear();
        if (result == QMessageBox::Yes)
        {
            QMessageBox::information(this, "提示", "已清空导入的文件");
        }
    }
    if (result == QMessageBox::YesAll)
    {
        remove("USERDATA");
        QMessageBox::information(this, "提示", "已清空导入的文件和用户数据");
    }
}

void MainWindow::RemoveRAll()
{
    const int result = QMessageBox::warning(this, "警告",
                                            "是否清空搜索结果",
                                            QMessageBox::No | QMessageBox::Yes);
    if (result == QMessageBox::Yes)
    {
        if (const auto model = qobject_cast<QStandardItemModel*>(ui->FilteredFiles->model())) model->clear();
    }
}

void MainWindow::openAFile(const QModelIndex& index)
{
    const QString filePath = index.data(Qt::UserRole).toString();
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "错误", "文件路径为空");
        return;
    }
    if (const QFileInfo fileInfo(filePath); !fileInfo.exists())
    {
        QMessageBox::warning(this, "错误", "文件不存在：" + filePath);
        return;
    }
    if (!QDesktopServices::openUrl(QUrl::fromLocalFile(filePath)))
    {
        QMessageBox::warning(this, "错误", "无法打开文件：" + filePath);
    }
}

void MainWindow::openFileOnExplorer(const QModelIndex& index)
{
    const QString filePath = index.data(Qt::UserRole).toString();
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "错误", "文件路径为空");
        return;
    }
    const QString nativePath = QDir::toNativeSeparators(filePath);
    if (const QFileInfo fileInfo(nativePath); !fileInfo.exists())
    {
        QMessageBox::warning(this, "错误", "文件不存在：" + nativePath);
        return;
    }
    QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(nativePath).path()));
}

void MainWindow::SearchTargetFiles()
{
    const QString keyword = ui->SearchTarget->toPlainText().trimmed();
    const bool isFuzzySearch = ui->FuzzySearchMode->isChecked();
    const int searchMode = ui->SearchContent->currentIndex();
    const auto model = qobject_cast<QStandardItemModel*>(ui->FilteredFiles->model());
    if (!model) return;
    model->clear();
    if (keyword.isEmpty())
    {
        QMessageBox::information(this, "提示", "搜索内容不能为空");
        return;
    }
    for (FileInfo& fileInfo : fileList)
    {
        bool match = false;
        if (searchMode == 0) //按文件名搜索
        {
            QString fileName = fileInfo.getName();
            if (isFuzzySearch) match = fileName.contains(keyword, Qt::CaseInsensitive);
            else match = (fileName.compare(keyword, Qt::CaseInsensitive) == 0);
        }
        else
        {
            QList<QString> tags = fileInfo.getTags(); // 按标签搜索
            for (const auto& tag : tags)
            {
                if (isFuzzySearch && tag.contains(keyword, Qt::CaseInsensitive)) //开启模糊搜索（部分匹配）
                {
                    match = true;
                    break;
                }
                if (tag.compare(keyword, Qt::CaseInsensitive) == 0) //关闭模糊搜索（精准匹配）
                {
                    match = true;
                    break;
                }
            }
        }
        if (match)
        {
            QString displayText = QString("%1 (%2)").arg(fileInfo.getName()).arg(fileInfo.getType());
            Add2rightList(displayText, fileInfo.getPath());
        }
    }
    if (model->rowCount() == 0) QMessageBox::information(this, "提示", "未找到匹配结果");
}

void MainWindow::showListContextMenu(const QPoint& pos)
{
    const QModelIndex index = ui->RecordedFiles->indexAt(pos);
    if (!index.isValid()) return;
    currentSelectedPath = index.data(Qt::UserRole).toString();
    listContextMenu->exec(ui->RecordedFiles->viewport()->mapToGlobal(pos));
}

void MainWindow::onBrowseButtonClicked()
{
    const QString dirPath = QFileDialog::getExistingDirectory(this, "选择一个目录导入");
    if (dirPath.isEmpty())
    {
        QMessageBox::warning(this, "提示", "此目录为空");
        return;
    }
    vector<QString> files;
    getAllFiles(dirPath, files);
    for (const auto& file : files)
    {
        bool exists = false;
        for (auto& existingInfo : fileList)
        {
            if (existingInfo.getPath() == file)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            FileInfo fileInfo(file);
            fileList.push_back(fileInfo);
            Add2leftList(fileInfo);
        }
    }
    saveToJson();
    QMessageBox::information(this, "成功", QString("添加了%1个文件").arg(files.size()));
}

void MainWindow::onAddButtonClicked()
{
    const QString filePath =
        QFileDialog::getOpenFileName(this,
                                     "选择一个文件",
                                     "D:\\",
                                     tr("所有文件 (*.*)"));
    if (const QFileInfo fileInfo(filePath); fileInfo.exists())
    {
        bool exists = false;
        for (auto& existingInfo : fileList)
        {
            if (existingInfo.getPath() == filePath)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            FileInfo info(filePath);
            fileList.push_back(info);
            Add2leftList(info);
            saveToJson();
            QMessageBox::information(this, "成功", "成功添加选中文件");
        }
        else
        {
            QMessageBox::warning(this, "提示", "文件已存在");
        }
    }
}

void MainWindow::onClearLButtonClicked()
{
    RemoveLAll();
}

void MainWindow::onDeleteSelectedButtonClicked()
{
    QModelIndexList selectedIndexes = ui->RecordedFiles->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty())
    {
        QMessageBox::warning(this, "提示", "请先选择一个文件");
        return;
    }
    const int result = QMessageBox::question(
        this, "确认删除", "确定要删除选中的文件吗？此操作不可恢复！",
        QMessageBox::Yes | QMessageBox::No
    );
    if (result == QMessageBox::Yes)
    {
        const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model());
        if (!model) return;
        QList<int> rows;
        for (const QModelIndex& index : selectedIndexes)
        {
            rows.prepend(index.row());
        }
        for (const int row : rows)
        {
            const QStandardItem* item = model->item(row);
            QString filePath = item->data(Qt::UserRole).toString();
            auto it = std::remove_if(fileList.begin(), fileList.end(),
                                     [filePath](FileInfo& info) { return info.getPath() == filePath; });
            fileList.erase(it, fileList.end());
            model->removeRow(row);
            QFile::remove(filePath);
        }
        saveToJson();
    }
}

void MainWindow::onClearRButtonClicked()
{
    RemoveRAll();
}

void MainWindow::onOpenFileOnExplorerButtonClicked()
{
    QModelIndexList selectedLIndexes = ui->RecordedFiles->selectionModel()->selectedIndexes();
    QModelIndexList selectedRIndexes = ui->FilteredFiles->selectionModel()->selectedIndexes();
    if (selectedLIndexes.isEmpty() && selectedRIndexes.isEmpty())
    {
        QMessageBox::warning(this, "提示", "请先选择一个文件");
        return;
    }
    openFileOnExplorer(selectedRIndexes.isEmpty() ? selectedLIndexes.first() : selectedRIndexes.first());
}

void MainWindow::onSearchButtonClicked()
{
    SearchTargetFiles();
}

void MainWindow::onAddTagClicked()
{
    QModelIndexList selectedIndexes = ui->RecordedFiles->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) return;
    const QModelIndex index = selectedIndexes.first();
    QString currentSelectedPath = index.data(Qt::UserRole).toString();
    bool ok;
    if (const QString tag = QInputDialog::getText(this, "添加标签", "请输入新标签：", QLineEdit::Normal, "", &ok); ok && !tag.
        isEmpty())
    {
        const auto it = std::find_if(fileList.begin(), fileList.end(),
                                     [currentSelectedPath](FileInfo& info)
                                     {
                                         return info.getPath() == currentSelectedPath;
                                     });
        if (it != fileList.end())
        {
            it->addTag(tag);
            if (const auto model = qobject_cast<QStandardItemModel*>(ui->RecordedFiles->model()))
            {
                QStandardItem* item = model->itemFromIndex(index);
                const QString tags = it->getTags().join(", ");
                item->setToolTip(QString("添加时间: %1\n标签: %2").arg(it->getAddedDatetime()).arg(tags));
            }
            saveToJson();
        }
    }
}

void MainWindow::onLeftSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected) const
{
    Q_UNUSED(deselected);
    if (!selected.isEmpty())
    {
        ui->FilteredFiles->selectionModel()->clearSelection();
    }
}

void MainWindow::onRightSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected) const
{
    Q_UNUSED(deselected);
    if (!selected.isEmpty())
    {
        ui->RecordedFiles->selectionModel()->clearSelection();
    }
}

bool isUserDataExist();
