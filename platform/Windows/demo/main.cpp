#include <stdio.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "Unknown3DEngine.h"

using namespace unknown;

static bool s_showStats = false;

static void glfw_errorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

static void glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
        s_showStats = !s_showStats;
}

int main(int argc, char **argv)
{
    // Create a GLFW window without an OpenGL context.
    glfwSetErrorCallback(glfw_errorCallback);
    if (!glfwInit())
        return 1;
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow *window = glfwCreateWindow(1024, 768, "Unknown3D", nullptr, nullptr);
    if (!window)
        return 1;
    glfwSetKeyCallback(window, glfw_keyCallback);

    void* handle = glfwGetWin32Window(window);
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // init engine
    RenderConfig config = {(uint16_t) width, (uint16_t) height, handle};
    Unknown3DEngine* engine = new Unknown3DEngine(config);
    Scene* scene = new Scene();
    engine->SetScene(scene);
    unknown::Rectangle rectangle = {"rect1", 0.5, 0.5};
    scene->AddChild(rectangle);
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        engine->Render();
    }
    glfwTerminate();
    return 0;
}