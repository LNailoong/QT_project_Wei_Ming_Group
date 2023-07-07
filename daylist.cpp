#include "daylist.h"

DayList::DayList()
{

}

void DayList::addnewtask(const Task& _task)
{
    daytask.append(_task);
}

void DayList::addtheme(QString _theme)
{
    theme=_theme;
}

void DayList::add_dayschedule(QString s)
{
    dayschedule=s;
}
