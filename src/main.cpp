#include <cstdio>
#include <monte_carlo.hpp>
#include <monte_carlo_settings.hpp>

int main(int /*arc*/, char **/*argv*/)
{
    {
        pi::monte_carlo mc;
        pi::monte_carlo_settings mcs;
        mcs.set_points_per_thread(1'000'000);
        mc.setup(mcs);
        auto pi = mc.calculate();
        printf("monte carlo: %lu\n", pi);
    }
    return 0;
}
