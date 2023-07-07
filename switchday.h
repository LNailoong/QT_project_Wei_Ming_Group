#ifndef SWITCHDAY_H
#define SWITCHDAY_H

#include <QMainWindow>

namespace Ui {
class SwitchDay;
}

class SwitchDay : public QMainWindow
{
    Q_OBJECT

public:
    explicit SwitchDay(QWidget *parent = nullptr);
    ~SwitchDay();

private:
    Ui::SwitchDay *ui;
};

#endif // SWITCHDAY_H
