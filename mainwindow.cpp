#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>
#include <QSettings>
#include <QFile>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//XOR_password();

QMap<QString,MY_GROUP*> map=this->get_ini_qmap("D:/rifx.ini");
QByteArray pwd=map.value("MYSQL")->map.value("Password");
   qDebug()<<"Password" << QString::fromUtf8(pwd);
   QByteArray uncrypt;
   uncrypt.append(XOR_Crypt(pwd));
   qDebug()<<"Password" << QString::fromUtf8(uncrypt);

   save_ini(map, "D:/result.ini");



/*
QString path1=("D:/rezult.ini");
 QFile file1(path1);
         QByteArray Buffer;
                Buffer.clear();
              if(file1.open(QIODevice::ReadOnly))
              {
                 QDataStream stream(&file1);
                 qDebug()<<"file size"<<file1.size();
                 while(!file1.atEnd())
                             {
                      quint8 data;
                            stream >> data;
                            Buffer.append(data);

                             }

             }
              file1.close();
              qDebug()<<"размер "<<Buffer.length();
              qDebug()<<QString::fromUtf8(Buffer);


       //   QFile file1(path1);
QString path2=("D:/rezult2.ini");
QFile file2(path2);          if(file2.open(QIODevice::WriteOnly))
          {
              QDataStream stream(&file2);

      //  stream<<Buffer;
              stream.writeRawData(Buffer,Buffer.length());


          }
 file2.close();
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::XOR_Crypt(QByteArray val)
{
    QString key="start7";

        QByteArray pw=key.toLocal8Bit();

        qDebug()<<pw.size();
        QByteArray res;
        res.clear();
        for (int x=1;x<val.size()+1;x++)
        {
    //    qDebug()<<"---"<<x<<"-------------";

               int val1=  pw[(x)%pw.size()] * 2;

             int inx=val[x-1];
       //     qDebug()<<" val1 "<<val1<<"inx "<<inx;

             int val2= inx ^ val1;
             char chr = (char)val2;
       //      qDebug()<<chr;
     //         OutputDebugString(&in[x]);
     //         OutputDebugString(&pass[x%pass.Length()+1]);
     //         OutputDebugString(&chr);
     //          OutputDebugString("----------------");
     //      out +=  chr; /// ??????? * 2 ? ????? ?????????? ?????????
       //      qDebug()<<chr<<" "<<QString(QChar(chr)) ;
             res.append(chr);
        //     qDebug()<<QString::fromUtf8(res);
        }
         //    qDebug()<<QString::fromUtf8(res);
         //   qDebug()<<QString::fromLocal8Bit(res);

        QString str_res = QString::fromLocal8Bit(res);

        return res;
    /*
    qDebug()<<"[XOR_Crypt]";
    QByteArray ar=src.toLocal8Bit();
qDebug()<<"src "<<src;
QString key="start7";

    QByteArray pw=key.toLocal8Bit();

    qDebug()<<pw.size();
    QByteArray res;
    res.clear();
    for (int x=1;x<ar.size()+1;x++)
    {
    qDebug()<<"---"<<x<<"-------------";

           int val1=  pw[(x)%pw.size()] * 2;

         int inx=ar[x-1];
   //     qDebug()<<" val1 "<<val1<<"inx "<<inx;

         int val2= inx ^ val1;
         char chr = (char)val2;
   //      qDebug()<<chr;
 //         OutputDebugString(&in[x]);
 //         OutputDebugString(&pass[x%pass.Length()+1]);
 //         OutputDebugString(&chr);
 //          OutputDebugString("----------------");
 //      out +=  chr; /// ??????? * 2 ? ????? ?????????? ?????????
         qDebug()<<chr<<" "<<QString(QChar(chr)) ;
         res.append(chr);
         qDebug()<<QString::fromUtf8(res);
    }
         qDebug()<<QString::fromUtf8(res);
        qDebug()<<QString::fromLocal8Bit(res);

    QString str_res = QString::fromLocal8Bit(res);
    return str_res;
    */
}

void MainWindow::XOR_password()
{
    /*
    //    QSettings settings("C:/Program Files/RIFx/rifx.ini", QSettings::IniFormat);
        QSettings settings("D:/1.ini", QSettings::IniFormat);
      #if (defined (_WIN32) || defined (_WIN64))
          settings.setIniCodec( "Windows-1251" );
       //   settings.setIniCodec( "UTF-16" );
      #else
          settings.setIniCodec( "UTF-8" );
      #endif

        settings.beginGroup("MySQL");

        QString in=settings.value("Password", "").toString();






        long password_value = settings.value("Password", "").toInt();
        QByteArray password_ar = settings.value("Password", "").toByteArray();
        qDebug()<<password_ar.toHex();
        qDebug()<<"password_value "<<password_value;
        qDebug()<<"SoundType  "<<in.toUtf8();

        this->ui->lineEdit->setText(in);

        qDebug()<<"this->ui->lineEdit->text():  "<<this->ui->lineEdit->text();

        settings.endGroup();



        QString crypt = XOR_Crypt(in);


        QString final =XOR_Crypt(crypt);

        qDebug()<< "final" <<final.toUtf8();

         this->ui->lineEdit_2->setText(crypt);

        this->ui->lineEdit_3->setText(final);





        QString path=("D:/res.ini");

            QFile file(path);
            file.open(QIODevice::WriteOnly | QIODevice::Text);



              // optional, as QFile destructor will already do it:
              file.close();


        QSettings settings1(path,QSettings::IniFormat);
        settings1.setIniCodec( "Windows-1251" );
         settings1.beginGroup(in);
         settings1.setValue("SoundType",in);
         settings1.setValue("Password_value",(int)password_value);
         settings1.setValue("Password_ar",QString::fromLocal8Bit(password_ar.toHex()));


         settings1.endGroup();

        QString path1=("D:/res1.ini");
         QFile file1(path1);





         if(file1.open(QIODevice::WriteOnly))
         {
             QDataStream stream(&file1);    // read the data serialized from the file

             stream<<in.toUtf8();

             file.close();
         }
         */
}

void MainWindow::find_password()
{
    QString path;
     path=("D:/rifx.ini");
  //   path=("D:/qwerty.txt");
  //   path=("D:/1.txt");

       QFile file(path);



       if(file.open(QIODevice::ReadOnly))
       {
          QDataStream stream(&file);    // read the data serialized from the file
          /*
          [   91
          =   61
             10
             13
             10
          ]   93
                  */
          QString str;
          QMap<QString,QByteArray> fields;
          QList<QByteArray> list;
          QList<QByteArray> list1;
          QByteArray key;
          QByteArray val;
          QByteArray ar;
          int flag=0;
          int fl1=0;
          int fflag=0;
          QByteArray Buf1;
          QByteArray Buf2;
           while(!file.atEnd())
                       {
                       flag=0;
               quint8 data;

                          stream >> data;
                          qDebug()<<(char)data<<" "<<data;

  if (fflag==0)
      Buf1.append(data);
  if (fflag==2)
      Buf2.append(data);

                  /*
                         if(data==32)
                                 flag=1;

                        if(ar.size()>0)
                        {

                            if(((quint8)ar[ar.size()-1]==10)||
                            ((quint8)ar[ar.size()-1]==13))
                            {
                                ar.remove(ar.size()-1,1);
                                    flag=2;

                            }

                             if((quint8)ar[ar.size()-1]==10)
                             if((quint8)ar[ar.size()-2]==13)
                             {
                             ar.remove(ar.size()-2,2);
                                 flag=2;
                             }

                         }
                             */

                          if((data==32)||
                             (data==13)||
                             (data==10))
                              flag=1;



                         if(flag==0)
                         {
                            ar.append(data);
                         }
                         else
                         {
                                  if(ar.size()>0)
                                 list.append(ar);

                             QString str=QString::fromLocal8Bit(ar);
                              if(ar.size()>0)
                             qDebug()<<"fl "<<flag<<" "<<str<<"            "<<ar.toHex();


                             if(str=="[MYSQL]")
                             {
                                 qDebug()<<"------------------[MYSQL]";
                                 fl1=1;
                             }
                             str.clear();
                             if((fl1==1)&&(data==91))
                                 fl1=0;




                                  if(ar.size()>0)
                                  {

                                      int res=0;
                                      for(int i=0;i<ar.size();i++)
                                       {



                                          if((quint8)ar.at(i)==61)
                                              res=1;
                                          else
                                          if(res==0)
                                          {
                                             key.append(ar[i]);
                                          }
                                          else
                                          {
                                              val.append(ar[i]);
                                           }



                                       }
                                      qDebug()<<"key "<<QString::fromUtf8(key);
                                      qDebug()<< "val "<<" "<<QString::fromUtf8(val)<<" "<<val.toHex();

                                  //    fields.insert(QString::fromUtf8(key),val);

                                      list1.append(val);
                                      if(fl1==1)
                                      {

                                      if(QString::fromUtf8(key)=="Password")
                                      {
                                          qDebug()<<"[PROFIT]";

                                          QString key="start7";

                                              QByteArray pw=key.toLocal8Bit();

                                              qDebug()<<pw.size();
                                              QByteArray res;
                                              res.clear();
                                              for (int x=1;x<val.size()+1;x++)
                                              {
                                              qDebug()<<"---"<<x<<"-------------";

                                                     int val1=  pw[(x)%pw.size()] * 2;

                                                   int inx=val[x-1];
                                             //     qDebug()<<" val1 "<<val1<<"inx "<<inx;

                                                   int val2= inx ^ val1;
                                                   char chr = (char)val2;
                                             //      qDebug()<<chr;
                                           //         OutputDebugString(&in[x]);
                                           //         OutputDebugString(&pass[x%pass.Length()+1]);
                                           //         OutputDebugString(&chr);
                                           //          OutputDebugString("----------------");
                                           //      out +=  chr; /// ??????? * 2 ? ????? ?????????? ?????????
                                                   qDebug()<<chr<<" "<<QString(QChar(chr)) ;
                                                   res.append(chr);
                                                   qDebug()<<QString::fromUtf8(res);
                                              }
                                                   qDebug()<<QString::fromUtf8(res);
                                                  qDebug()<<QString::fromLocal8Bit(res);

                                              QString str_res = QString::fromLocal8Bit(res);
                                               this->ui->lineEdit->setText(str_res);
                                      }
                                      }
                                     key.clear();
                                     val.clear();



                              }
      ar.clear();


                          }

                       }



          /* foreach(QString key,fields)
           {
               qDebug()<<"key: "<<key<<  "val:........."<<QString::fromUtf8(fields.value(key));
           }
          */
           qDebug()<<"----------------------------------------------------------";
           QMap<QString,MY_GROUP*> map;
           QString str_group;

       //   MY_GROUP group[100];
          int cnt_group=0;

           foreach(QByteArray val,list)
           {
             //   qDebug()<< "ar "<<" "<<QString::fromUtf8(val)<<" "<<val.toHex();
                //check for GROUP
                if(((quint8)val[0]==91)&&((quint8)val[val.size()-1])==93)
                {

                 qDebug()<<"----------------------------";
  /*                     foreach(QString key1, map.keys())
                    {

                      qDebug()<<"["<<key1<<"]";
                  //    qDebug()<<"key "<<key1<<"id "<<map.value(key1)->get_id();
                         foreach(QString key2,map.value(key1)->map.keys())
                      {
                          qDebug()<<key2<<"="<<QString::fromUtf8(map.value(key1)->map.value(key2));
                      }

                    }
  */

                    str_group=QString::fromUtf8(val);
                    str_group.replace("[","");
                    str_group.replace("]","");


                    MY_GROUP* gr=new MY_GROUP(this);


                    qDebug()<<"id "<<gr->get_id();

                    map.insert(str_group,gr);

                    cnt_group++;

                    qDebug()<<"id "<<map.last()->get_id();

                    qDebug()<<"GROUP "<<str_group<<" id "<<map.last()->get_id();
                    qDebug()<<"GROUP "<<str_group<<" id "<<map.value(str_group)->get_id();
                }
                  else
                {

                    QByteArray src;
                    QByteArray key;

                    qDebug()<<map.value(str_group)->map.size();

                    int res=0;
                    for(int i=0;i<val.size();i++)
                    {
                        if((quint8)val.at(i)==61)
                        res=1;
                        else
                        if(res==0)
                        key.append(val[i]);
                        else
                        src.append(val[i]);
                    }

              //      qDebug()<<"key "<<QString::fromUtf8(key);
               //     qDebug()<< "val "<<" "<<QString::fromUtf8(src)<<" "<<src.toHex();


                    map.value(str_group)->map.insert(QString::fromUtf8(key),src);

                            //..insert(QString::fromUtf8(key),src);
  /**/
                }
           }

           qDebug()<<"Password" << QString::fromUtf8(map.value("MYSQL")->map.value("Password"));
  }
   //    file.close();

}

QMap<QString, MY_GROUP*> MainWindow::get_ini_qmap(QString filepath)
{
    QMap<QString,MY_GROUP*> map;

  //   path=("D:/1.txt");

       QFile file(filepath);
       if(file.open(QIODevice::ReadOnly))
       {
          QDataStream stream(&file);    // read the data serialized from the file
          /*
          [   91
          =   61
             10
             13
             10
          ]   93
                  */
          QString str;
          QMap<QString,QByteArray> fields;
          QList<QByteArray> list;
          QList<QByteArray> list1;
          QByteArray key;
          QByteArray val;
          QByteArray ar;
          int flag=0;
          int fl1=0;


           while(!file.atEnd())
                       {
                       flag=0;
               quint8 data;

                          stream >> data;
//                          qDebug()<<(char)data<<" "<<data;

                          if((data==32)||(data==13)||(data==10))
                              flag=1;

                         if(flag==0)
                         {
                            ar.append(data);
                         }
                         else
                         {
                            if(ar.size()>0)
                            list.append(ar);

                            QString str=QString::fromLocal8Bit(ar);
                            if(ar.size()>0)
//                          qDebug()<<"fl "<<flag<<" "<<str<<"            "<<ar.toHex();


                             if(str=="[MYSQL]")
                             {
                                 qDebug()<<"------------------[MYSQL]";
                                 fl1=1;
                             }
                             str.clear();




                                  if(ar.size()>0)
                                  {

                                      int res=0;
                                      for(int i=0;i<ar.size();i++)
                                       {



                                          if((quint8)ar.at(i)==61)
                                              res=1;
                                          else
                                          if(res==0)
                                          {
                                             key.append(ar[i]);
                                          }
                                          else
                                          {
                                              val.append(ar[i]);
                                           }



                                       }
                                      qDebug()<<"key "<<QString::fromUtf8(key);
                                      qDebug()<< "val "<<" "<<QString::fromUtf8(val)<<" "<<val.toHex();

                                  //    fields.insert(QString::fromUtf8(key),val);

                                      list1.append(val);
                                      if(fl1==1)
                                      {

                                      if(QString::fromUtf8(key)=="Password")
                                      {
                                          qDebug()<<"[PROFIT]";

                                          QString key="start7";

                                              QByteArray pw=key.toLocal8Bit();

                                              qDebug()<<pw.size();
                                              QByteArray res;
                                              res.clear();
                                              for (int x=1;x<val.size()+1;x++)
                                              {
                                              qDebug()<<"---"<<x<<"-------------";

                                                     int val1=  pw[(x)%pw.size()] * 2;

                                                   int inx=val[x-1];
                                             //     qDebug()<<" val1 "<<val1<<"inx "<<inx;

                                                   int val2= inx ^ val1;
                                                   char chr = (char)val2;
                                             //      qDebug()<<chr;
                                           //         OutputDebugString(&in[x]);
                                           //         OutputDebugString(&pass[x%pass.Length()+1]);
                                           //         OutputDebugString(&chr);
                                           //          OutputDebugString("----------------");
                                           //      out +=  chr; /// ??????? * 2 ? ????? ?????????? ?????????
                                                   qDebug()<<chr<<" "<<QString(QChar(chr)) ;
                                                   res.append(chr);
                                                   qDebug()<<QString::fromUtf8(res);
                                              }
                                                   qDebug()<<QString::fromUtf8(res);
                                                  qDebug()<<QString::fromLocal8Bit(res);

                                              QString str_res = QString::fromLocal8Bit(res);
                                               this->ui->lineEdit->setText(str_res);
                                      }
                                      }
                                     key.clear();
                                     val.clear();



                              }
      ar.clear();


                          }

                       }



          /* foreach(QString key,fields)
           {
               qDebug()<<"key: "<<key<<  "val:........."<<QString::fromUtf8(fields.value(key));
           }
          */
           qDebug()<<"----------------------------------------------------------";
           QMap<QString,MY_GROUP*> map;
           QString str_group;

       //   MY_GROUP group[100];
          int cnt_group=0;

           foreach(QByteArray val,list)
           {
             //   qDebug()<< "ar "<<" "<<QString::fromUtf8(val)<<" "<<val.toHex();
                //check for GROUP
                if(((quint8)val[0]==91)&&((quint8)val[val.size()-1])==93)
                {

                 qDebug()<<"----------------------------";
  /*                     foreach(QString key1, map.keys())
                    {

                      qDebug()<<"["<<key1<<"]";
                  //    qDebug()<<"key "<<key1<<"id "<<map.value(key1)->get_id();
                         foreach(QString key2,map.value(key1)->map.keys())
                      {
                          qDebug()<<key2<<"="<<QString::fromUtf8(map.value(key1)->map.value(key2));
                      }

                    }
  */

                    str_group=QString::fromUtf8(val);
                    str_group.replace("[","");
                    str_group.replace("]","");


                    MY_GROUP* gr=new MY_GROUP(this);


                    qDebug()<<"id "<<gr->get_id();

                    map.insert(str_group,gr);

                    cnt_group++;

                    qDebug()<<"id "<<map.last()->get_id();

                    qDebug()<<"GROUP "<<str_group<<" id "<<map.last()->get_id();
                    qDebug()<<"GROUP "<<str_group<<" id "<<map.value(str_group)->get_id();
                }
                  else
                {

                    QByteArray src;
                    QByteArray key;

                    qDebug()<<map.value(str_group)->map.size();

                    int res=0;
                    for(int i=0;i<val.size();i++)
                    {
                        if((quint8)val.at(i)==61)
                        res=1;
                        else
                        if(res==0)
                        key.append(val[i]);
                        else
                        src.append(val[i]);
                    }

              //      qDebug()<<"key "<<QString::fromUtf8(key);
               //     qDebug()<< "val "<<" "<<QString::fromUtf8(src)<<" "<<src.toHex();


                    map.value(str_group)->map.insert(QString::fromUtf8(key),src);

                            //..insert(QString::fromUtf8(key),src);
  /**/
                }
           }

           //Cортировать по айдишнику MY_GROUP;



           return map;
       }
}

void MainWindow::save_ini(QMap<QString, MY_GROUP *> map, QString filepath)
{
    QByteArray next_string;
    next_string.append(0x0D);
    next_string.append(0x0A);
    QFile file(filepath);



    auto write_group = [](QDataStream* stream, QString src)
    {
      QByteArray res=src.toLocal8Bit();

      res.clear();
      res.append(91);
      res.append(src);
      res.append(93);
      res.append(0x0D);
      res.append(0x0A);
      res.append(0x0D);
      res.append(0x0A);

      stream->writeRawData(res,res.size());
    };

    auto write_field = [](QDataStream* stream, QString key, QByteArray val)
    {
      QByteArray res=key.toLocal8Bit();

      res.clear();
      res.append(key);
      res.append(61);
      res.append(val);
      res.append(0x0D);
      res.append(0x0A);

      stream->writeRawData(res,res.size());
    };


//Создадим QList из ключей map и отсортируем
    QList<MY_GROUP*> list;
    foreach(MY_GROUP* val,map.values())
    {
        list.append(val);
    }

    qDebug()<<"-- До сортировки ------------------------";
    QList<MY_GROUP*>::iterator i;
    for (i = list.begin(); i != list.end()-1; ++i)
    {
      qDebug()<<map.key(*i)<<"  id= "<<(*i)->get_id();

    }

    qSort(list.begin(), list.end(),
          [](const MY_GROUP* a, const MY_GROUP* b) -> bool
    { return &a < &b;});
    qDebug()<<"-- После сортировки ------------------------";

    for (i = list.begin(); i != list.end()-1; ++i)
    {
      qDebug()<<map.key(*i)<<"  id= "<<(*i)->get_id();

    }

    qDebug()<<"--------------------------------------------";

    /*
   QList<QString>::iterator i;
   for (i = list.begin(); i != list.end()-1; ++i)
   {
       QString str1=*i;
       QString str2=*(i+1);
       int val1=map.value(str1)->get_id();
       int val2=map.value(str2)->get_id();


   }*/


  /*
  qSort(list.begin(), list.end(), [](const QVariant &v1,
                                                  const QVariant &v2)
                                                               ->bool
    {

       return v1<v2;
    }
                                                                );

 */


    if(file.open(QIODevice::WriteOnly))
    {
       QDataStream stream(&file);
//       foreach(QString key,map.keys())
       QMap<QString,MY_GROUP*>::iterator i;
       for (i = map.begin(); i != map.end(); ++i)
       {
         //  stream.writeRawData((char)0x91,1);
           write_group(&stream,i.key());
           qDebug()<<i.key();
           MY_GROUP* group=i.value();
           foreach (QString key, group->map.keys()) {


           write_field(&stream,key,group->map.value(key));
         //  stream.writeRawData(key.toLocal8Bit(),key.toLocal8Bit().size());

           }


       }

    }
    file.close();
}

