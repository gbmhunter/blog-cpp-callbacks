#include <cstdio>
#include <functional>

class MyClass {
public:
    int methodToCallback(int num1, int num2) {
        return num1 + num2;
    }
};

void passACallbackToMe(std::function<int(int, int)> callback) {
    int o = callback(1, 2);
    printf("Value: %i\n", o);
}

int main()
{
    MyClass myClass;
    passACallbackToMe(std::bind(&MyClass::methodToCallback, myClass, std::placeholders::_1, std::placeholders::_2));
}