#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include "WNativeConverter.h"
#include "RiderEngine.h"

using namespace NS_RIDER;
using namespace emscripten;

extern "C"
NATIVE_PTR EMSCRIPTEN_KEEPALIVE RiderEngine_makeEngine(std::string canvas_id, bool debug) {
    val canvas = val::global("document").call<val>("getElementById", canvas_id);
    uint16_t width = canvas["width"].as<uint16_t>();
    uint16_t height = canvas["height"].as<uint16_t>();
    RenderConfig config{width, height, canvas.as_handle(), debug};
    RiderEngine* engine = new RiderEngine(config);
    return ToEngineJsObject(engine);
}