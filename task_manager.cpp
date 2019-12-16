//
// Created by yura on 15.12.19.
//
#include <USBAPI.h>
#include <algorithm> // binary search

#include "task_manager.h"

TaskManager::TaskManager()
{

}

void TaskManager::add_task_loop(const Task &task, uint16_t triger_ms)
{
    TaskEntry taskEntry;
    taskEntry.task = task;
    taskEntry.m_triger_ms = triger_ms;
    taskEntry.last_trigger_time_ms = millis();

    m_tasks.push_back(taskEntry);
}

void TaskManager::add_task_once(const Task &task)
{
    task();
}

void TaskManager::change_task_triger_ms(Task::ID, uint16_t new_triger_ms)
{

}

bool TaskManager::get_task_entry_by_id(Task::ID id, TaskManager::TaskEntry &task_entry_out)
{
    if (std::binary_search(m_tasks.begin(), m_tasks.end(), id, compare()))
    {

    }
}




