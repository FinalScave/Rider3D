function compile_vertex_metal() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx -p metal --type vertex
  cp "$3" ../platform/iOS/"$3"
  rm -f "$3"
}
function compile_fragment_metal() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx -p metal --type fragment
  cp "$3" ../platform/iOS/"$3"
  rm -f "$3"
}
function compile_vertex_glsl() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "$3" --bin2c "$4" -i ./include --platform windows -p 150 --type vertex
}
function compile_fragment_glsl() {
  ../tools/windows/shaderc.exe -f "$1" --varyingdef "$2" -o "$3" --bin2c "$4" -i ./include --platform windows -p 150 --type fragment
}

#glsl
# 编译最小shader
compile_vertex_glsl simple/vs_simple.sc simple/varying.def.sc ../src/unknown/shader/vs_simple.h VS_SIMPLE
compile_fragment_glsl simple/fs_simple.sc simple/varying.def.sc ../src/unknown/shader/fs_simple.h FS_SIMPLE

# 编译通用shader
# compile_vertex_glsl common/vs_common.sc common/varying.def.sc ../src/unknown/shader/vs_common.h VS_COMMON
# compile_fragment_glsl common/fs_common.sc common/varying.def.sc ../src/unknown/shader/fs_common.h FS_COMMON
