#include <cstdio>
#include <functional>

#include <benchmark/benchmark.h>

/**
 * This defines the interface of the "callbackable" class.
 */
class CallbackInterface {
public:
    virtual int methodToCallback(int num1, int num2) = 0;
};

class LibraryClass {
public:
    LibraryClass(CallbackInterface* callback) : callback(callback) {}
    void run() {
        // Call the callback function
        total += callback->methodToCallback(x++, y++);
    }
    int x = 0;
    int y = 0;
    int total = 0;
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
