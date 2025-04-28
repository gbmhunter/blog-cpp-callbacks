#include <cstdio>
#include <functional>

#include <std23/function_ref.h>
#include <benchmark/benchmark.h>

class MyClass {
public:
    int methodToCallback(int num1, int num2) {
        return num1 + num2;
    }
};

static int x = 0;
static int y = 0;
static int total = 0;

class LibraryClass {
public:

    LibraryClass(std23::function_ref<int(int, int)> callback) : callback(callback) {}

    void run() {
        total += callback(x++, y++);
    }
private:
    std23::function_ref<int(int, int)> callback;
};

static void stdFunctionRef(benchmark::State& state) {
    MyClass myClass;
    std23::function_ref<int(int, int)> callback = {std23::nontype<&MyClass::methodToCallback>, myClass};
    LibraryClass libraryClass(callback);
    for (auto _ : state) {
        libraryClass.run();
    }
}
// Register the function as a benchmark
BENCHMARK(stdFunctionRef);
