#include <cstdio>
#include <functional>

#include <benchmark/benchmark.h>

namespace {

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

static uint64_t total = 0;

MyClass * l_myClass;

static int standardCFunction(int num1, int num2) {
    return l_myClass->methodToCallback(num1, num2);
}

static void callingMemberThroughStandardCFunction(benchmark::State& state) {
    MyClass myClass;
    l_myClass = &myClass;
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += standardCFunction(x++, y++);
        // benchmark::ClobberMemory();
    }
}
BENCHMARK(callingMemberThroughStandardCFunction);

} // namespace