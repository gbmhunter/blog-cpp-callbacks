#include <cstdio>
#include <functional>

class LibraryClass {
public:
	  void passACallbackToMe(int (*callback)(int num1, int num2)) {
	      // Now invoke (call) the callback
        int o = callback(1, 2);
        printf("Value: %i\n", o); // We might be on an embedded system, use printf() and not std::cout
	  }
};

class MyClass {
public:
      int methodToCallback(int num1, int num2) {
          return num1 + num2;
      }
};

// Global pointer to an instance of our class so the C style callback
// wrapper can invoke the callback on a particular instance (yuck!)
MyClass * myClassPtr;
int cStyleWrapper(int num1, int num2) {
    return myClassPtr->methodToCallback(num1, num2);
}

int main()
{
    MyClass myClass;
    // Make the global variable point to our new instance. Obviously, this
    // way does not scale well, as you have to make global variable and C-style
    // function for every instance (and what if you don't know how many instances you will
    // need!?!)
    myClassPtr = &myClass; 
    
    LibraryClass libraryClass;
    libraryClass.passACallbackToMe(&cStyleWrapper);
}