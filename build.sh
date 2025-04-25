cd caller-knows-the-callee-type
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd static-methods-or-non-member-functions
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd calling-member-functions-through-shared-variables
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd static-variables-with-templating
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..
