set -e

mkdir -p build
cd build

cmake -G "Unix Makefiles" ..
make
cmake --install .

cd ..
