set -e

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

cd std-function-with-std-bind
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd std-function-with-lambdas
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd templates
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd using-std-function-ref
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..

cd benchmarks
mkdir -p build
cd build
cmake ..
cmake --build .
./output
cd ../..
