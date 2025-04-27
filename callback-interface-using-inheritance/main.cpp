#include <cstdio>

/**
 * This defines the interface of the "callbackable" class.
 */
class CallbackInterface {
public:
    virtual void methodToCallback(int num1, int num2) = 0;
};

class LibraryClass {
public:
    LibraryClass(CallbackInterface* callback) : callback(callback) {}
    void run() {
        // Call the callback function
        callback->methodToCallback(1, 2);
    }
private:
    CallbackInterface* callback;
};

/**
 * Our class inherits from the interface.
 */
class MyClass : public CallbackInterface {
public:
    void methodToCallback(int num1, int num2) {
        printf("onMsg() called with num1=%i, num2=%i\n", num1, num2);
    }
};

int main() {
    MyClass myClass;
    LibraryClass libraryClass(&myClass);
    libraryClass.run();
}