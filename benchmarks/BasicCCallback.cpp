#include <benchmark/benchmark.h>

static uint64_t total = 0;

int callback(int num1, int num2) {
    return num1 + num2;
}

void passACallbackToMe(int (*callback)(int, int)) {
    int o = callback(1, 2);
    total += o;
}

static void basicCallback(benchmark::State& state) {
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
    }
}
BENCHMARK(basicCallback);
