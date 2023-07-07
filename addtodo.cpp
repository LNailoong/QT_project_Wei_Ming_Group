#include "addtodo.h"
#include "ui_addtodo.h"
#include<QMessageBox>
addtodo::addtodo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtodo)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("Please type new TO DO here. ");
    //设置图标大小为32*32(默认为16*16)
    ui->comboBox->setIconSize(QSize(32, 32));
    ui->comboBox->addItem(QIcon(":/red.png"), "red");
    ui->comboBox->addItem(QIcon(":/yellow.png"), "yellow");
    ui->comboBox->addItem(QIcon(":/pink.png"), "pink");
    ui->comboBox->addItem(QIcon(":/purple.png"), "purple");
    ui->comboBox->addItem(QIcon(":/blue.png"),"blue");
    ui->comboBox->addItem(QIcon(":/green.png"),"green");
    ui->comboBox->addItem(QIcon(":/grey.png"),"grey");
}

addtodo::~addtodo()
{
    delete ui;
}

