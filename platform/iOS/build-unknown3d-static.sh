#!/bin/sh
platform=OS64
echo $(pwd)
if [$1 eq "all"]; then
    platform=OS64COMBINED
fi
cd ../../
cmake -H. -B./build/iOS/.cxx/arm64 -DPLATFORM=OS64 -DCMAKE_LIBRARY_OUTPUT_DIRECTORY=./build/iOS/lib/arm64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=./platform/iOS/ios.toolchain.cmake -DCMAKE_CXX_FLAGS="-std=c++11 -frtti -fexceptions" -DIOS=ON
cd ./build/iOS/.cxx/arm64
cmake --build .
