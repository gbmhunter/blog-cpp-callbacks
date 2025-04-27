#include <cstdio>

template <typename T, typename U>
class LibraryClass {
public:
    LibraryClass(T callback, U& instance) : callback(callback), instance(instance) {}

    void run() {
        (instance.*callback)(1, 2);
    }
private:
    T callback;
    U& instance;
};

class MyClass {
public:
    void methodToCallback(int num1, int num2) {
        printf("methodToCallback() called with num1=%i, num2=%i\n", num1, num2);
    }
};

int main() {
    MyClass myClass;
    LibraryClass libraryClass(&MyClass::methodToCallback, myClass);
    libraryClass.run();
}
