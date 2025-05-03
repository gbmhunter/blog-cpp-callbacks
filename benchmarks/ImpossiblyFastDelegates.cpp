#include <cstdio>

#include <benchmark/benchmark.h>

#include "ImpossiblyFastDelegates.hpp"

namespace {

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

static uint64_t total = 0;

static void impossiblyFastDelegates(benchmark::State& state) {
    MyClass myClass;
    auto callback = delegate<int(int, int)>::from(&myClass, &MyClass::methodToCallback);
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
        // benchmark::ClobberMemory();
    }
}
BENCHMARK(impossiblyFastDelegates);

} // namespace
