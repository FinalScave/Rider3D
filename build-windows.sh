mkdir build
cd build
mkdir Windows
cd Windows
cmake ../../ -G "MinGW Makefiles" -DCMAKE_CXX_FLAGS="-frtti -fexceptions -w" -DCMAKE_BUILD_TYPE=Release
cmake --build .