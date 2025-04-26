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
    
    // Use a lambda to capture myClass and call the member method
    passACallbackToMe([&myClass](int num1, int num2) -> int {
        return myClass.methodToCallback(num1, num2);
    });
}