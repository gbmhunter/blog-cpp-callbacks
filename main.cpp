#include <iostream>
#include <functional>

class MyClass1 {
    public:
        void functionToCall() {
            std::cout << "functionToCall() called." << std::endl;
        }
};

void giveMeACallback(std::function<void()> callback) {
    callback();
}

int main() {
    MyClass1 myClass1;
    giveMeACallback(std::bind(&MyClass1::functionToCall, &myClass1));
}