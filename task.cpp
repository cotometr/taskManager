#include "task.h"

Task::Task()
{
    static ID global_id;

    m_id = global_id;

    ++global_id;
}

uint16_t Task::get_id() const
{
    return m_id;
}