# 先构建Rider3D库
echo "Building Rider3D lib..."
cd ../../../
cmake -B./build -DWEB=ON -DSTATIC_LIB=ON -DENABLE_LOG=ON -UBUILD_PC_DEMO
cmake --build ./build

# 执行Emscripten构建
export TOTAL_MEMORY=67108864
export WASM_OUTPUT_DIR=platform/Web/wasm
export RIDER3D_BUILD_DIR=build
export RIDER3D_SRC_DIR=src
export RIDER3D_WEB_DIR=src/platform/web

echo "Running Emscripten..."
# can force ignore undefined symbol by add -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
em++ ${RIDER3D_WEB_DIR}/WNativeConverter.cpp \
    ${RIDER3D_WEB_DIR}/WRiderEngine.cpp \
    ${RIDER3D_BUILD_DIR}/librider3d.a \
    -O3 \
    -I "${RIDER3D_SRC_DIR}" \
    -I "${RIDER3D_SRC_DIR}/entityx" \
    -I "${RIDER3D_SRC_DIR}/core" \
    -I "${RIDER3D_SRC_DIR}/util" \
    -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
    -s WASM=1 \
    -s NO_EXIT_RUNTIME=1 \
    -s ASSERTIONS=0 \
    -s TOTAL_MEMORY=${TOTAL_MEMORY} \
    -s ALLOW_MEMORY_GROWTH=1 \
    -o ${WASM_OUTPUT_DIR}/rider3d.js \
    --no-entry

echo "Finished Build"