#pragma once
#include <calculator.hpp>
#include <monte_carlo_settings.hpp>
#include <utility>

namespace pi
{
    class monte_carlo: public calculator<monte_carlo_settings>
    {
    public:
        uint64_t calculate();
        void setup(const monte_carlo_settings &s);
    private:
        void _applicable_points(const uint64_t points, const unsigned radius, uint64_t &result);
        std::pair<double, double> _get_point(const unsigned max);

        monte_carlo_settings _settings;
    };
}
