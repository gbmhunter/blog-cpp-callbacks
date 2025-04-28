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

cd callback-interface-using-inheritance
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

cd templating-the-member-function-and-instance
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
# Run the benchmarks and save the output to a JSON file
./output_opt --benchmark_out=output_opt.json --benchmark_out_format=json
./output_no_opt --benchmark_out=output_no_opt.json --benchmark_out_format=json
cd ../..
