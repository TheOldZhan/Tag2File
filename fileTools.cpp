#include <fileTools.h>
#include <qfileinfo.h>
#include <ctime>
#include <QString>

Datetime::Datetime(bool cond)
{
    if (cond)
    {
        time_t time64 = time(nullptr);
        tm tm_buf;
        localtime_s(&tm_buf, &time64);
        std::ostringstream dateStream;
        dateStream << std::setfill('0')
            << tm_buf.tm_year + 1900 << "-"
            << std::setw(2) << tm_buf.tm_mon + 1 << "-"
            << std::setw(2) << tm_buf.tm_mday;
        date = QString::fromStdString(dateStream.str());
        std::ostringstream timeStream;
        timeStream << std::setfill('0')
            << std::setw(2) << tm_buf.tm_hour << ":"
            << std::setw(2) << tm_buf.tm_min << ":"
            << std::setw(2) << tm_buf.tm_sec;
        t = QString::fromStdString(timeStream.str());
    }
}

QString Datetime::getDate() const
{
    return (this->date);
}

QString Datetime::getTime() const
{
    return this->t;
}

QString Datetime::getAddedDatetime() const
{
    return this->date + " " + this->t;
}

void Datetime::setDateTimeFromString(const QString& datetimeStr)
{
    if (QStringList parts = datetimeStr.split("_"); parts.size() == 2)
    {
        date = parts[0];
        t = parts[1];
    }
}

FileInfo::FileInfo() : Datetime(false) { ; }

FileInfo::FileInfo(const QString& p) : Datetime(true)
{
    const QFileInfo fileInfo(p);
    name = fileInfo.fileName();
    path = fileInfo.absoluteFilePath();
    type = fileInfo.suffix().toUpper() + "文件";
    tag.push_back(fileInfo.suffix());
}

QString FileInfo::getName()
{
    return this->name;
}

QString FileInfo::getPath()
{
    return this->path;
}

QString FileInfo::getType()
{
    return this->type;
}

QList<QString> FileInfo::getTags()
{
    return tag;
}

void FileInfo::addTag(const QString& t)
{
    tag.push_back(t);
}

bool FileInfo::isTagExist(const QString& t)
{
    for (const auto& i : this->tag) if (i == t) return true;
    return false;
}
