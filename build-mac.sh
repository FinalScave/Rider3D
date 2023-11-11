mkdir build
cd build
mkdir MacOS
cd MacOS
cmake -S ../../ -DCMAKE_CXX_FLAGS="-std=c++11 -frtti -fexceptions -w"
cmake --build .