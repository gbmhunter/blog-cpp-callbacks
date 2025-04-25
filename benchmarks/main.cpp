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

void passACallbackToMe(function_ref<int(int, int)> callback) {
    int o = callback(1, 2);
    total += o;
    // printf("Value: %i\n", o); // We might be on an embedded system, use printf() and not std::cout
}


static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state) {
    MyClass myClass;
    passACallbackToMe({nontype<&MyClass::methodToCallback>, myClass});
  }
  printf("Total: %lu\n", total);
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// int main()
// {
//     MyClass myClass;
//     passACallbackToMe({nontype<&MyClass::methodToCallback>, myClass});
// }

BENCHMARK_MAIN();
