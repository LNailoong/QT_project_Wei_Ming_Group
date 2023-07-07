#include "switchday.h"
#include "ui_switchday.h"

SwitchDay::SwitchDay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SwitchDay)
{
    ui->setupUi(this);
}

SwitchDay::~SwitchDay()
{
    delete ui;
}
