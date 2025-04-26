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

static void stdFunctionWithLambdas(benchmark::State& state) {
    MyClass myClass;
    std::function<int(int, int)> callback = [&myClass](int num1, int num2) -> int {
        return myClass.methodToCallback(num1, num2);
    };
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
    }
}
BENCHMARK(stdFunctionWithLambdas);
