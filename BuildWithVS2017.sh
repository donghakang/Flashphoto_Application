cd src/external/MinGfx
./BuildWithVS2017.sh
cd ../../flashphoto

mkdir -p build
mkdir -p ../../build/bin
touch CMakeLists.txt
cd build
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_INSTALL_PREFIX=../../../build -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --target install
cd ..
