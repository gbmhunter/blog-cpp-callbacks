#include <cstdio>
#include <functional>

#include <std23/function_ref.h>

using std23::function_ref;
using std23::nontype;

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

void passACallbackToMe(function_ref<int(int, int)> callback) {
    int o = callback(1, 2);
    printf("Value: %i\n", o); // We might be on an embedded system, use printf() and not std::cout
}

int main()
{
    MyClass myClass;
    passACallbackToMe({nontype<&MyClass::methodToCallback>, myClass});
}
