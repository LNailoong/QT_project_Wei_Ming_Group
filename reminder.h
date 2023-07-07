#pragma once

#include <iostream>
#include <QDateTime>
#include <QDebug>

#include "uuid.h"

/*
“提醒”类
每个 Task 类均包含一个名为 reminders 的 vector<Reminder>，表示要在哪些时间提醒
*/
class Reminder {
public:
    long long uuid;

    //确切提醒时间
    QDateTime reminderTime;
    //是否已经提醒
    bool isReminded;

    Reminder();

    friend bool operator== (const Reminder &reminder1, const Reminder &reminder2);
};
