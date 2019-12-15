#include "task.h"

Task::Task()
{
    static uint16_t global_id;

    m_id = global_id;

    ++global_id;
}

uint16_t Task::get_id() const
{
    return id;
}