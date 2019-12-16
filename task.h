#pragma once

#include <cstdint>



class Task
{
public:
    Task();

    using ID = uint16_t;

    virtual void operator()() const = 0;

    template <typename T>
    virtual T get_value() const = 0;

    ID get_id() const;

private:
    ID m_id;
};