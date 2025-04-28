#include <cstdio>
#include <functional>

#include <benchmark/benchmark.h>

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

static uint64_t total = 0;

static void stdFunctionWithBind(benchmark::State& state) {
    MyClass myClass;
    std::function<int(int, int)> callback = std::bind(&MyClass::methodToCallback, &myClass, std::placeholders::_1, std::placeholders::_2);
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
        // benchmark::ClobberMemory();
    }
}
BENCHMARK(stdFunctionWithBind);
