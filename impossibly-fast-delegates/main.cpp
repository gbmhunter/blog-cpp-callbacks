#include <cstdio>

#include "ImpossiblyFastDelegates.hpp"

class MyClass {
public:
    // This is our application callback handler for when a message is received, we will
    // pass this into the library which deals with message parsing
    int methodToCallback(int num1, int num2) {
        printf("methodToCallback() called with num1=%i, num2=%i\n", num1, num2);
        return num1 + num2;
    }
};

class LibraryClass {
public:
    void passACallbackToMe(delegate<int(int, int)> callback) {
        // Call the callback function
        callback(1, 2);
    }
};

int main() {
    MyClass myClass;
    LibraryClass libraryClass;

    auto callback = delegate<int(int, int)>::from(&myClass, &MyClass::methodToCallback);

    // Provide the instance and function to call
    libraryClass.passACallbackToMe(callback);
}
