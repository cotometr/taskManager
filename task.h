#pragma once

class Task
{
public:
    Task();

    virtual void operator() = 0;

    template <typename T>
    virtual T get_value() = 0;

    uint16_t get_id() const;

private:
    uint16_t m_id;
};