#pragma once

#include <vector>
#include "task.h"

using std::vector;

class TaskManager
{
public:
    TaskManager( );

    void add_task_loop( const Task& task, uint16_t triger_ms );

    void add_task_once( const Task& task );

    void change_task_triger_ms( Task::ID, uint16_t new_triger_ms );
    void remove_task( Task::ID task_id );

    void poll();

private:

    bool get_task_entry_by_id(Task::ID, TaskEntry& taskEntry_out);

    struct TaskEntry
    {
        Task task;
        uint16_t m_triger_ms;
        unsigned long last_trigger_time_ms;
    };

    struct compare {

        bool operator()(const TaskManager::TaskEntry& value,
                        const Task::ID& key)
        {
            return (value.task.get_id() < key);
        }
        bool operator()(const Task::ID& key,
                        const TaskManager::TaskEntry& value)
        {
            return (key < value.task.get_id());
        }
    };
    std::vector< TaskEntry > m_tasks;
};