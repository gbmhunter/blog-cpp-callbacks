#include <cstdio>

class MyClass {
public:
    // This is our application callback handler for when a message is received, we will
    // pass this into the library which deals with message parsing
        void onMsg(int num1, int num2) {
        printf("onMsg() called with num1=%i, num2=%i\n", num1, num2);
    }
};

class LibraryClass {
public:
    // For the library class to call the onMsg, it has to be passed both an instance
    // of MyClass and a pointer to the member function to call
    // Note that MyClass has to be known here! This creates undesired coupling...in
    // reality your library should never have to know about MyClass
    void passACallbackToMe(MyClass* myClass, void (MyClass::* onMsg)(int num1, int num2)) {
        // Call the callback function
        (myClass->*onMsg)(1, 2);
    }
};

int main() {
    MyClass myClass;
    LibraryClass libraryClass;

    // Provide the instance and function to call
    libraryClass.passACallbackToMe(&myClass, &MyClass::onMsg);
}