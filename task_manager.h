#pragma once

#include <vector>
#include "task.h"

using std::vector;

class TaskManager
{
public:
    TaskManager( uint16_t clock_rate_ms );

    void add_task( const Task& task, uint16_t triger_ms );

    void pause_task( uint16_t task_id );
    void resume_task( uint16_t task_id );
    void remove_task( uint16_t task_id );

private:
    int m_clock_rate;

    struct TaskEntry
    {
        Task task;
        uint16_t m_triger_ms;
        Status m_status;

        enum Status
        {
            WORK,
            PAUSE
        };

    };

    std::vector< TaskEntry > m_tasks;
};