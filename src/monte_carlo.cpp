#include <monte_carlo.hpp>
#include <cmath>
#include <ctime>
#include <random>
#include <thread>
#include <vector>

namespace pi
{
    uint64_t monte_carlo::calculate()
    {
        const uint64_t points_per_thread = _settings.get_points_per_thread();
        const uint64_t threads = _settings.get_threads();
        const auto points_total = points_per_thread * threads;

        const auto radius = _settings.get_radius();

        const auto precision = _settings.get_precision();
        const uint64_t shifter = std::pow(10, precision);

        std::vector<uint64_t> applicable_points(threads);
        std::vector<std::thread> calculation_threads;
        for(unsigned i = 0; i < threads; ++i)
        {
            calculation_threads.emplace_back(std::thread(
                &monte_carlo::_applicable_points,
                this,
                points_per_thread,
                radius,
                std::ref(applicable_points[i])));
        }

        for(auto &thread: calculation_threads)
            thread.join();

        uint64_t applicable_points_total{0};
        for(const auto value: applicable_points)
            applicable_points_total += value;

        return 4 * (applicable_points_total*shifter)/points_total;
    }

    void monte_carlo::setup(const monte_carlo_settings &s)
    {
        _settings = s;
    }

    void monte_carlo::_applicable_points(const uint64_t points, const unsigned radius, uint64_t &result)
    {
        uint64_t applicable_points{0};
        for(uint64_t i = 0; i < points; ++i)
        {
            const auto point = _get_point(radius);
            const auto point_radius = std::sqrt(point.first*point.first + point.second*point.second);
            if(point_radius <= radius)
                ++applicable_points;
        }

        result = applicable_points;
    }

    std::pair<double, double> monte_carlo::_get_point(const unsigned max)
    {
        thread_local auto thread_id = std::this_thread::get_id();
        thread_local auto thread_hash = std::hash<std::thread::id>{}(thread_id);
        thread_local auto clock_value = clock();
        thread_local auto generator = std::mt19937(clock_value + thread_hash);
        std::uniform_real_distribution<double> distribution(0.0, max);
        return std::make_pair(distribution(generator), distribution(generator));
    }
}
