#pragma once

namespace pi
{
    class settings
    {
    public:
        settings();
        virtual ~settings();

        void set_precision(const unsigned p);
        unsigned get_precision() const;

        void set_threads(const unsigned t);
        unsigned get_threads() const;
    private:
        unsigned _precision;
        unsigned _threads;
    };
}
