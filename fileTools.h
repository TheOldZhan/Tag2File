#ifndef FILEINFO_H
#define FILEINFO_H
#include <iostream>
#include <QJsonObject>
#include <QJsonArray>
using namespace std;

class Datetime
{
public:
    QString date, t;
    explicit Datetime(bool cond);
    ~Datetime() = default;
    [[nodiscard]] QString getDate() const;
    [[nodiscard]] QString getTime() const;
    [[nodiscard]] QString getAddedDatetime() const;
    void setDateTimeFromString(const QString& datetimeStr);
};

class FileInfo : public Datetime
{
    QString name, path, type;
    QList<QString> tag;

public:
    FileInfo();
    explicit FileInfo(const QString& p);
    ~FileInfo() = default;
    QString getName();
    QString getPath();
    QString getType();
    QList<QString> getTags();
    void addTag(const QString& t);
    bool isTagExist(const QString& t);

    QJsonObject toJson() const
    {
        QJsonObject obj;
        obj["path"] = path;
        obj["name"] = name;
        obj["type"] = type;
        obj["added_datetime"] = getAddedDatetime();
        QJsonArray tagsArray;
        for (const auto& t : tag) tagsArray.append(t);
        obj["tags"] = tagsArray;
        return obj;
    }

    static FileInfo fromJson(const QJsonObject& json)
    {
        FileInfo info;
        info.path = json["path"].toString();
        info.name = json["name"].toString();
        info.type = json["type"].toString();
        const QString datetimeStr = json["added_datetime"].toString();
        if (QStringList parts = datetimeStr.split(" "); parts.size() == 2)
        {
            info.date = parts[0];
            info.t = parts[1];
        }
        QJsonArray tagsArray = json["tags"].toArray();
        for (const auto& tagVal : tagsArray)
            info.tag.push_back(tagVal.toString());
        return info;
    }
};

#endif // FILEINFO_H
