#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    //宽度，高度，控件大小
    ui->hLayout1->
}

Test::~Test()
{
    delete ui;
}
