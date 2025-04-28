#include <cstdio>
#include <functional>

#include <benchmark/benchmark.h>

#pragma GCC push_options
#pragma GCC optimize ("O0")

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

static uint64_t total = 0;

class LibraryClass {
public:
    template <typename T, typename U>
    void passACallbackToMe(T callback, U& instance) {
        total += (instance.*callback)(x++, y++);
    }
private:
    uint64_t x = 0;
    uint64_t y = 0;
};

static void templatingTheMemberFunctionAndInstance(benchmark::State& state) {
    MyClass myClass;
    LibraryClass libraryClass;
    for (auto _ : state) {
        libraryClass.passACallbackToMe(&MyClass::methodToCallback, myClass);
        // benchmark::ClobberMemory();
    }
}
BENCHMARK(templatingTheMemberFunctionAndInstance);

#pragma GCC pop_options