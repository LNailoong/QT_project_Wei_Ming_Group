#include "reminder.h"

Reminder::Reminder()
{
    uuid=get_uuid();
    isReminded=0;
}
bool operator== (const Reminder &reminder1, const Reminder &reminder2) {
    return reminder1.reminderTime == reminder2.reminderTime;
}
