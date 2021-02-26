#include "group.h"
#include <QDebug>

MY_GROUP::MY_GROUP(QObject *parent) : QObject(parent)
{
    static int val=0;
    qDebug()<<"static int val: "<<val;
    id=val;

    val++;
}

int MY_GROUP::get_id()
{
    return id;
}
