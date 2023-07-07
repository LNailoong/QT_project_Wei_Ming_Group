#include "mainwindow.h"
#include "addtodo.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include<QPainter>
#include<QMediaPlayer>
#include<addcurriculum.h>
#include<QMediaPlaylist>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//Initialization
    this->resize(600,400);

    for(int i=0;i<=11;i++)
    {
        for(int j=0;j<=7;j++)
        {
            currColor[i][j]=0;
        }
    }

    ui->dateEdit->setDateTime(QDateTime::currentDateTime());

    QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVolume(80);//音量
    QMediaPlaylist *playlist = new QMediaPlaylist(this);//初始化播放列表
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//设置播放模式（单曲循环）
    playlist->addMedia(QUrl("qrc:/bgm.mp3"));//添加歌曲
    mediaPlayer->setPlaylist(playlist);  //设置播放列表
    mediaPlayer->play();

    addtodo* atd=new addtodo(this);
    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"日程");
    ui->tableWidget_2->setRowCount(15);
    ui->tableWidget_2->setVerticalHeaderLabels(QStringList()<<" 7:00-8:00"<<" 8:00-9:00"<<" 9:00-10:00"<<" 10:00-11:00"<<" 11:00-12:00"<<" 12:00-13:00"<<" 13:00-14:00"<<" 14:00-15:00"<<" 15:00-16:00"<<" 16:00-17:00"<<" 17:00-18:00"<<" 18:00-19:00"<<" 19:00-20:00"<<" 20:00-21:00"<<" 21:00-22:00");
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->dayscheduleEdit->setPlaceholderText("请在此输入你的日程 ");


    ui->themeEdit->setPlaceholderText("请在此输入你的主题");
    //tab4
    AddCurriculum* ac=new AddCurriculum(this);
    connect(ui->pushButton_4,&QPushButton::clicked,ac,[=](){
        ac->show();
    });

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Mon"<<"Tue"<<"Wed"<<"Thur"<<"Fri"<<"Sat"<<"Sun");
    ui->tableWidget->setRowCount(12);
    ui->tableWidget->setVerticalHeaderLabels(QStringList()<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//表头字体居中
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

    ui->tableWidget->setStyleSheet("QHeaderView{background:transparent}\
                                    QHeaderView::section{font-size:14px;font-family:'Microsoft YaHei';color:#FFFFFF;background:#60669B;border:none;text-align:left;min-width:40px;min-height:49px;max-height:49px;margin-left:0px;padding-left:0px}\
                                    QTableWidget{background-color: rgb(255, 253, 234);border:none;font-size:20px;font-family:'Microsoft YaHei';color:#666666}\
                                    QTableWidget::item{border-bottom:1px solid #EEF1F7}\
                                    QTableWidget::item::selected{color:red;background:#EFF4FF}");


//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("程序设计实习\n二教407"));
//    ui->tableWidget->item(0,0)->setTextAlignment(Qt::AlignCenter);
//    ui->tableWidget->item(0,0)->setIcon(QIcon(":/red.png"));
//    ui->tableWidget->setIconSize(QSize(32,32));
//    //ui->tableWidget->item(1, 5)->setBackground(Qt::lightGray); //设置单元格背景颜色
//    ui->tableWidget->item(0,0)->setForeground(Qt::black);	// 设置字体颜色
//    ui->tableWidget->item(0,0)->setFont( QFont( "宋体", 14, QFont::Black ));	// 设置宋体、11号、加粗
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/background2.jpg"));
}

//curriculum 刷新
void MainWindow::refresh()
{

    for(int j=0;j<=7;j++)
    {
        for(int i=0;i<=11;i++)
        {
            if(currColor[i][j]!=0)
            {
                qDebug()<<currName[i][j]<<currPlace[i][j]<<currColor[i][j];
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(currName[i][j]+"\n"+currPlace[i][j]));
                ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);
                if(currColor[i][j]==1)
                {
                    ui->tableWidget->item(i,j)->setIcon(QIcon(":/red.png"));
                }
                if(currColor[i][j]==2)
                {
                    ui->tableWidget->item(i,j)->setIcon(QIcon(":/yellow.png"));
                }
                if(currColor[i][j]==3)
                {
                    ui->tableWidget->item(i,j)->setIcon(QIcon(":/pink.png"));
                }
                if(currColor[i][j]==4)
                {
                    ui->tableWidget->item(i,j)->setIcon(QIcon(":/purple.png"));
                }
                ui->tableWidget->setIconSize(QSize(32,32));
                //ui->tableWidget->item(1, 5)->setBackground(Qt::lightGray); //设置单元格背景颜色
                ui->tableWidget->item(i, j)->setForeground(Qt::black);	// 设置字体颜色
                ui->tableWidget->item(i, j)->setFont( QFont( "宋体", 14, QFont::Black ));	// 设置宋体、11号、加粗
            }
        }
    }
}

//day schedule 刷新
void MainWindow::refresh(const QDateTime &dateTime)
{
    //qDebug()<<dateTime.toString("yyyy-MM-dd hh:mm:ss")<<'@';
    //qDebug()<<bank_daylist.size()<<'?';

    ui->tableWidget_2->setColumnCount(1);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"日程");
    ui->tableWidget_2->setRowCount(15);
    ui->tableWidget_2->setVerticalHeaderLabels(QStringList()<<" 7:00-8:00"<<" 8:00-9:00"<<" 9:00-10:00"<<" 10:00-11:00"<<" 11:00-12:00"<<" 12:00-13:00"<<" 13:00-14:00"<<" 14:00-15:00"<<" 15:00-16:00"<<" 16:00-17:00"<<" 17:00-18:00"<<" 18:00-19:00"<<" 19:00-20:00"<<" 20:00-21:00"<<" 21:00-22:00");
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVector<DayList>::iterator iter;
    bool flag=0;
    bool come[20]={0};
    for (iter=bank_daylist.begin();iter!=bank_daylist.end();iter++)
    {
        if((*iter).daytime.toString("yyyy-MM-dd")==dateTime.toString("yyyy-MM-dd"))
        {
            qDebug()<<'>';
            flag=1;
            ui->themeEdit->setPlainText((*iter).theme);

            QVector<Task>::iterator iterr;
            for (iterr=(*iter).daytask.begin();iterr!=(*iter).daytask.end();iterr++)
            {
                int sthour=(*iterr).startTime.time().hour();
                ui->tableWidget_2->setItem(sthour-8,1,new QTableWidgetItem((*iterr).content));
                come[sthour-7]=1;
            }
            break;
        }
    }
    if(!flag)
    {
        ui->themeEdit->setPlainText("");
    }
    for(int i=0;i<=14;i++)
    {
        if(!come[i])
        {
            ui->tableWidget_2->setItem(i-1,1,new QTableWidgetItem(""));
        }
    }
}

//你懂的
void MainWindow::month_schedule_refresh(const QDateTime &dateTime)
{
    //qDebug()<<dateTime.toString("yyyy-MM-dd hh:mm:ss")<<'@';
    QVector<DayList>::iterator iter;
    bool flag=0;
    for (iter=bank_daylist.begin();iter!=bank_daylist.end();iter++)
    {
        if((*iter).daytime.toString("yyyy-MM-dd")==dateTime.toString("yyyy-MM-dd"))
        {
            qDebug()<<(*iter).dayschedule;
            flag=1;
            ui->dayscheduleEdit->setPlainText((*iter).dayschedule);
            break;
        }
    }
    if(!flag)
    {
        ui->dayscheduleEdit->setPlainText("");
    }
}

//day schedule 切换日期
void MainWindow::on_dateEdit_dateTimeChanged(const QDateTime &dateTime)
{
    refresh(dateTime);
}

//day schedule 填写任务内容
void MainWindow::on_tableWidget_2_itemChanged(QTableWidgetItem *item)
{
    int t=item->row();
    QString content=item->text();
    QString stdatetime=(ui->dateEdit->date().toString("yyyy-MM-dd")).append(" ");
    QString sttime[]={"07","08","09","10","11","12","13","14","15","16","17","18","19","20","21"};
    stdatetime.append(sttime[t]+":00:00");

    Task new_task;
    new_task.startTime=QDateTime::fromString(stdatetime,"yyyy-MM-dd hh:mm:ss");
    new_task.date=new_task.startTime.date();
    new_task.content=content;
    new_task.type=TaskType::IN_TO_DO_LIST;

    bool flag=0;
    QVector<DayList>::iterator iter;
    for (iter=bank_daylist.begin();iter!=bank_daylist.end();iter++)
    {
        if((*iter).daytime.toString("yyyy-MM-dd")==new_task.startTime.toString("yyyy-MM-dd"))
        {
            (*iter).addnewtask(new_task);
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        DayList new_daylist;
        new_daylist.daytask.append(new_task);
        new_daylist.daytime=new_task.startTime;
        new_daylist.theme="";
        bank_daylist.append(new_daylist);
    }
    refresh(new_task.startTime);
}

//编辑日程主题后确认按键
void MainWindow::on_themeConfirm_clicked()
{
    QMessageBox message_box;
    QMessageBox::StandardButton result=message_box.question(nullptr, "", "Confirm?");
    if(result==QMessageBox::Yes)
    {
        QString s=ui->themeEdit->toPlainText();
        QDate now_date=ui->dateEdit->date();
        //qDebug()<<now_date.toString("yyyy-MM-dd");

        bool flag=0;
        QVector<DayList>::iterator iter;
        for (iter=bank_daylist.begin();iter!=bank_daylist.end();iter++)
        {
            if((*iter).daytime.toString("yyyy-MM-dd")==now_date.toString("yyyy-MM-dd"))
            {
                flag=1;
                (*iter).addtheme(s);
                break;
            }
        }
        if(!flag)
        {
            DayList new_daylist;
            new_daylist.theme=s;
            new_daylist.daytime=QDateTime::fromString(now_date.toString("yyyy-MM-dd"),"yyyy-MM-dd");
            bank_daylist.append(new_daylist);
        }
        refresh(QDateTime::fromString(now_date.toString("yyyy-MM-dd"),"yyyy-MM-dd"));
    }
}

//month schedule 切换日期
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    month_schedule_refresh(QDateTime::fromString(date.toString("yyyy-MM-dd"),"yyyy-MM-dd"));
}

//month schedule 编辑日程后保存按键
void MainWindow::on_save_clicked()
{
    QMessageBox message_box;
    QMessageBox::StandardButton result=message_box.question(nullptr,"","Save?");
    if(result==QMessageBox::Yes)
    {
        bool flag=0;
        QVector<DayList>::iterator iter;
        for (iter=bank_daylist.begin();iter!=bank_daylist.end();iter++)
        {
            if((*iter).daytime.toString("yyyy-MM-dd")==ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"))
            {
                flag=1;
                (*iter).add_dayschedule(ui->dayscheduleEdit->toPlainText());
                break;
            }
        }
        if(!flag)
        {
            DayList new_daylist;
            new_daylist.dayschedule=ui->dayscheduleEdit->toPlainText();
            new_daylist.daytime=QDateTime::fromString(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"),"yyyy-MM-dd");
            bank_daylist.append(new_daylist);
        }
        month_schedule_refresh(QDateTime::fromString(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"),"yyyy-MM-dd"));
    }
}

