function compile_vertex_windows() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/hlsl/$3" -i ./include --platform windows -p 150 --type vertex --bin2c "$4"
}
function compile_fragment_windows() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/hlsl/$3" -i ./include --platform windows -p 150 --type fragment --bin2c "$4"
}
function compile_vertex_mac() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/metal/$3" -i ./include --platform osx -p metal --type vertex --bin2c "$4"
}
function compile_fragment_mac() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/metal/$3" -i ./include --platform osx -p metal --type fragment --bin2c "$4"
}
function compile_vertex_android() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/glsl/$3" -i ./include --platform android --type vertex --bin2c "$4"
}
function compile_fragment_android() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "../src/core/shader/glsl/$3" -i ./include --platform android --type fragment --bin2c "$4"
}

function windows() {
  compile_vertex_windows simple/vs_simple.sc simple/varying.def.sc vs_simple.h VS_SIMPLE
  compile_fragment_windows simple/fs_simple.sc simple/varying.def.sc fs_simple.h FS_SIMPLE

  compile_vertex_windows common/vs_common.sc common/varying.def.sc vs_common.h VS_COMMON
  compile_fragment_windows common/fs_common.sc common/varying.def.sc fs_common.h FS_COMMON
}
function mac() {
  compile_vertex_mac simple/vs_simple.sc simple/varying.def.sc vs_simple.h VS_SIMPLE
  compile_fragment_mac simple/fs_simple.sc simple/varying.def.sc fs_simple.h FS_SIMPLE

  compile_vertex_mac common/vs_common.sc common/varying.def.sc vs_common.h VS_COMMON
  compile_fragment_mac common/fs_common.sc common/varying.def.sc fs_common.h FS_COMMON
}
function android() {
  compile_vertex_android simple/vs_simple.sc simple/varying.def.sc vs_simple.h VS_SIMPLE
  compile_fragment_android simple/fs_simple.sc simple/varying.def.sc fs_simple.h FS_SIMPLE

  compile_vertex_android common/vs_common.sc common/varying.def.sc vs_common.h VS_COMMON
  compile_fragment_android common/fs_common.sc common/varying.def.sc fs_common.h FS_COMMON
}

if [ "$1" == "windows" ]; then
  windows
elif [ "$1" == "mac" ]; then
  mac
elif [ "$1" == "android" ]; then
  android
fi