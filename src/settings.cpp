#include <settings.hpp>
#include <thread>

namespace pi
{
    settings::settings()
        : _precision(8)
        , _threads(std::thread::hardware_concurrency())
    {}

    settings::~settings()
    {}

    void settings::set_precision(const unsigned p)
    {
        _precision = p;
    }

    unsigned settings::get_precision() const
    {
        return _precision;
    }

    void settings::set_threads(const unsigned t)
    {
        _threads = t;
    }

    unsigned settings::get_threads() const
    {
        return _threads;
    }
}
