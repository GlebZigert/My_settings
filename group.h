#ifndef MY_GROUP_H
#define MY_GROUPGROUP_H

#include <QObject>
#include<QMap>
#include<qDebug>

class MY_GROUP : public QObject
{
    Q_OBJECT
public:
    explicit MY_GROUP(QObject *parent = nullptr);
    int get_id();
    QMap<QString,QByteArray> map;


    bool operator<(const MY_GROUP other) const {
        qDebug()<<"Сравнение "<<id<<" и другой "<<other.id;
           return id<other.id;
       }

private:
    int id;


signals:


};

#endif // MY_GROUP_H
