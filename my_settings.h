#ifndef MY_SETTINGS_H
#define MY_SETTINGS_H

#include <QObject>


class My_settings : public QObject
{
    Q_OBJECT
public:
    explicit My_settings(QObject *parent = nullptr);

    void set_value(QString field, QVariant value);
    void value(QString field, QVariant value);

    void begin_group(QString group);
    void end_group();

signals:

};

#endif // MY_SETTINGS_H
