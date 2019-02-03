#pragma once
#include <cstdint>

namespace pi
{
    template<typename Settings>
    class calculator
    {
    public:
        virtual ~calculator(){};
        virtual uint64_t calculate() = 0;
        virtual void setup(const Settings &s) = 0;
    };
}
