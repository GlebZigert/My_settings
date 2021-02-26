#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <group.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString XOR_Crypt(QByteArray src);

    void  XOR_password();
    void find_password();
    QMap<QString,MY_GROUP*> get_ini_qmap(QString filepath);
    void save_ini(QMap<QString,MY_GROUP*> map, QString filepath);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
