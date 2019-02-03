#pragma once
#include <settings.hpp>
#include <cstdint>

namespace pi
{
    class monte_carlo_settings: public settings
    {
    public:
        monte_carlo_settings();

        void set_radius(const unsigned r);
        unsigned get_radius() const;

        void set_points_per_thread(const uint64_t p);
        uint64_t get_points_per_thread() const;
    private:
        unsigned _radius;
        uint64_t _points_per_thread;
    };
}
