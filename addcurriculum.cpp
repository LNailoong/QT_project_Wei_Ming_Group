#include "addcurriculum.h"
#include "ui_addcurriculum.h"
#include "mainwindow.h"
#include<QMessageBox>
#include<QPainter>
AddCurriculum::AddCurriculum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCurriculum)
{
    ui->setupUi(this);
    //ui->currtime->setPlaceholderText("For instance,Monday+1");
    ui->comboBox->setIconSize(QSize(32, 32));
    ui->comboBox->addItem(QIcon(":/red.png"), "red");
    ui->comboBox->addItem(QIcon(":/yellow.png"), "yellow");
    ui->comboBox->addItem(QIcon(":/pink.png"), "pink");
    ui->comboBox->addItem(QIcon(":/purple.png"), "purple");
    for(int i=0;i<=6;i++)
    {
        ui->currweek->addItem(week[i]);
    }
    for(int i=0;i<=11;i++)
    {
        ui->currhours->addItem(hour[i]);
    }
}

AddCurriculum::~AddCurriculum()
{
    delete ui;
}

bool AddCurriculum::haveset(int _week,int _hours)
{
    MainWindow* parent = dynamic_cast<MainWindow*>(this->parentWidget());
    if(parent->currColor[_hours][_week]!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//_color starts from 1
void AddCurriculum::set(int _week,int _hours,QString _name,QString _place, int _color)
{
    MainWindow* parent = dynamic_cast<MainWindow*>(this->parentWidget());
    parent->currColor[_hours][_week]=_color;
    parent->currName[_hours][_week]=_name;
    parent->currPlace[_hours][_week]=_place;
}

void AddCurriculum::on_buttonBox_accepted()
{
    QMessageBox message_box;
    int week=ui->currweek->currentIndex();
    int hours=ui->currhours->currentIndex();
    if(haveset(week,hours))
    {
        QMessageBox::StandardButton result=message_box.question(nullptr, "", "Have found a course at this time, want to change?");
        if(result==QMessageBox::Yes)
        {
            QString new_name=ui->currname->text();
            QString new_place=ui->currplace->text();
            set(week,hours,new_name,new_place,ui->comboBox->currentIndex()+1);
        }
    }
    else
    {
        QString new_name=ui->currname->text();
        QString new_place=ui->currplace->text();
        set(week,hours,new_name,new_place,ui->comboBox->currentIndex()+1);
    }
    MainWindow* parent = dynamic_cast<MainWindow*>(this->parentWidget());
    parent->refresh();
    this->close();
}

void AddCurriculum::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/background2.jpg"));
}

