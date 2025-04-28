#include <benchmark/benchmark.h>

#pragma GCC push_options
#pragma GCC optimize ("O0")

static uint64_t total = 0;

int callback(int num1, int num2) {
    return num1 + num2;
}

static void basicCCallback(benchmark::State& state) {
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
        // benchmark::ClobberMemory();
    }
}
BENCHMARK(basicCCallback);

#pragma GCC pop_options