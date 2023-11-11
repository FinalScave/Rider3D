function compile_vertex_metal() {
  ../tools/mac/shaderc -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx -p metal --type vertex
  cp "$3" ../platform/iOS/"$3"
  rm -f "$3"
}
function compile_fragment_metal() {
  ../tools/mac/shaderc -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx -p metal --type fragment
  cp "$3" ../platform/iOS/"$3"
  rm -f "$3"
}
function compile_vertex_glsl() {
  ../tools/mac/shaderc -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx --type vertex
  cp "$3" ../platform/Android/demo/src/main/assets/shaders/"$3"
  rm -f "$3"
}
function compile_fragment_glsl() {
  ../tools/mac/shaderc -f "$1" --varyingdef "$2" -o "$3" -i ./include --platform osx --type fragment
  cp "$3" ../platform/Android/demo/src/main/assets/shaders/"$3"
  rm -f "$3"
}

#glsl
# 编译通用shader
compile_vertex_glsl common/vs_common.sc common/varying.def.sc vs_common.bin
compile_fragment_glsl common/fs_common.sc common/varying.def.sc fs_common.bin
