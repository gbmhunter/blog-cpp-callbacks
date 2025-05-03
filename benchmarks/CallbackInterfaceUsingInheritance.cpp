#include <cstdio>

#include <benchmark/benchmark.h>

namespace {

/**
 * This defines the interface of the "callbackable" class.
 */
class CallbackInterface {
public:
    virtual int methodToCallback(int num1, int num2) = 0;
};

// If total is defined in the LibraryClass, it is optimized out (0ns runtime).
// So define these on the heap.
static int x = 0;
static int y = 0;
static int total = 0;

class LibraryClass {
public:
    LibraryClass(CallbackInterface* callback) : callback(callback) {}
    void run() {
        // Call the callback function
        total += callback->methodToCallback(x++, y++);
        // benchmark::ClobberMemory
    }
private:
    CallbackInterface* callback;
};

/**
 * Our class inherits from the interface.
 */
class MyClass : public CallbackInterface {
public:
    int methodToCallback(int num1, int num2) {
        return num1 + num2;
    }
};

static void callbackInterfaceUsingInheritance(benchmark::State& state) {
    MyClass myClass;
    LibraryClass libraryClass(&myClass);
    for (auto _ : state) {
        libraryClass.run();
    }
}
// Register the function as a benchmark
BENCHMARK(callbackInterfaceUsingInheritance);

} // namespace
