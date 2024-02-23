#include <stdio.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "UnknownEngine.h"
#include "bx/math.h"
#include "component/BasicComponents.h"
#include "net/Http.h"

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
    UnknownEngine* engine = new UnknownEngine(config);
    Entity entity = engine->GetEntities().create();
    entity.assign<Scene>();
    entity.assign<Camera>();
    entity.assign<Position>();
    entity.assign<Transform>();
    entity.component<Transform>()->rotation = Vec3{1,1,1};
    Scene* scene = new Scene();

    Http http;
    HttpRequest request{Get, "http://aaa.com/api/test"};
    http.SendRequestAsync(request, [&](const HttpResponse& res) {
        std::cout << res.body;
    })
    Camera* camera = new Camera {{3,2,-3}, {0, 0, 0}};
    scene->SetCamera(camera);
    Box box = {"box1", 0.4, 0.8, 0.4};
    //box.rotation->z = -0.5;
    scene->AddChild(box);
    // render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        engine->Update();
    }
    glfwTerminate();
    return 0;
}