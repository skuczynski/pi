#include <monte_carlo_settings.hpp>

namespace pi
{
    monte_carlo_settings::monte_carlo_settings()
        : settings()
        , _radius(1)
        , _points_per_thread(500)
    {}

    void monte_carlo_settings::set_radius(const unsigned r)
    {
        _radius = r;
    }

    unsigned monte_carlo_settings::get_radius() const
    {
        return _radius;
    }

    void monte_carlo_settings::set_points_per_thread(const uint64_t p)
    {
        _points_per_thread = p;
    }

    uint64_t monte_carlo_settings::get_points_per_thread() const
    {
        return _points_per_thread;
    }
}
