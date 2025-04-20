#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui_mainwindow.h>
#include <fstream>
#include <fileTools.h>
#include <QStandardItemModel>
#include <io.h>
#include <QDirIterator>
using namespace std;

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
    void Add2leftList(FileInfo& info) const;
    void AddVec2LeftList(vector<QString>& s);
    void Add2rightList(const QString& displayText, const QString& filePath) const;
    void saveToJson() const;
    void RemoveAFile(const QString& s);
    void SearchTargetFiles();
    void showListContextMenu(const QPoint& pos);
    void RemoveLAll();
    void RemoveRAll();
    void openAFile(const QModelIndex& index);

public slots:
    void onBrowseButtonClicked();
    void onAddButtonClicked();
    void onClearLButtonClicked();
    void onDeleteSelectedButtonClicked();
    void onClearRButtonClicked();
    void onOpenFileOnExplorerButtonClicked();
    void onSearchButtonClicked();
    void openFileOnExplorer(const QModelIndex& index);
    void onAddTagClicked();

private:
    Ui::MainWindow* ui;
    vector<FileInfo> fileList;
    QMenu* listContextMenu;
    QAction* addTagAction;
    QString currentSelectedPath;

private slots:
    void onLeftSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected) const;
    void onRightSelectionChanged(const QItemSelection& selected, const QItemSelection& deselected) const;

signals:
    void fileFound(QString path);
};

inline bool isUserDataExist()
{
    const QFileInfo fileInfo("USERDATA");
    return fileInfo.exists() && fileInfo.isReadable();
}

inline void getAllFiles(const QString& path, vector<QString>& files) //获取文件的绝对路径
{
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) files.push_back(it.next());
}

#endif // MAINWINDOW_H
