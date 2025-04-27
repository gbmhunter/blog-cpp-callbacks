#include <cstdio>

class MyClass {
public:
    // This is our application callback handler for when a message is received, we will
    // pass this into the library which deals with message parsing
    // The "static" keyword makes it easy, as now this function does not
    // take a this pointer and has the same signature as a plain C function
    void methodToCallback(int num1, int num2) {
        printf("methodToCallback() called with num1=%i, num2=%i\n", num1, num2);
        // NOTE: Can't call any non-static method functions here!
    }
};

class LibraryClass {
public:
    template <typename T, typename U>
    void passACallbackToMe(T callback, U& instance) {
        (instance.*callback)(1, 2);
    }
};

int main() {
    MyClass myClass;
    LibraryClass libraryClass;
    libraryClass.passACallbackToMe(&MyClass::methodToCallback, myClass);
}
