#ifndef ADDCURRICULUM_H
#define ADDCURRICULUM_H

#include <QDialog>

namespace Ui {
class AddCurriculum;
}

class AddCurriculum : public QDialog
{
    Q_OBJECT

public:
    explicit AddCurriculum(QWidget *parent = nullptr);
    ~AddCurriculum();
    QString week[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    QString hour[12]={"1","2","3","4","5","6","7","8","9","10","11","12"};
    void paintEvent(QPaintEvent*);
    bool haveset(int _week,int _hours);
    void set(int _week,int _hours,QString _name,QString _place, int _color);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddCurriculum *ui;
};

#endif // ADDCURRICULUM_H
