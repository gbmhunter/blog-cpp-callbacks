#include <cstdio>
#include <functional>

#include <std23/function_ref.h>

#include <benchmark/benchmark.h>

using std23::function_ref;
using std23::nontype;


class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

static uint64_t total = 0;

static void stdFunctionRef(benchmark::State& state) {
    MyClass myClass;
    function_ref<int(int, int)> callback = {nontype<&MyClass::methodToCallback>, myClass};
    uint64_t x = 0;
    uint64_t y = 0;
    for (auto _ : state) {
        total += callback(x++, y++);
    }
}
// Register the function as a benchmark
BENCHMARK(stdFunctionRef);
