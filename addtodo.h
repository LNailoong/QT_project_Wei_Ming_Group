#ifndef ADDTODO_H
#define ADDTODO_H

#include <QDialog>

namespace Ui {
class addtodo;
}

class addtodo : public QDialog
{
    Q_OBJECT

public:
    explicit addtodo(QWidget *parent = nullptr);
    ~addtodo();

private:
    Ui::addtodo *ui;
};

#endif // ADDTODO_H
