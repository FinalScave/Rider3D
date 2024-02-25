#include <cstdio>
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"
#include "UnknownEngine.h"
#include "component/BasicComponents.h"

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

void add_rect(UnknownEngine* engine, Scene* scene) {
    Entity rectangle = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Rectangle);
    Transform transform;
    transform.translation.x = 0.5;
    rectangle.assign_from_copy(transform);
    scene->AddEntity(rectangle);
}

void add_box(UnknownEngine* engine, Scene* scene) {
    Entity box = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
    scene->AddEntity(box);
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
    RenderConfig config = {(uint16_t) width, (uint16_t) height,
                           handle, true};
    UnknownEngine* engine = new UnknownEngine(config);
    SceneManager& scenes = engine->GetScenes();
    Scene* scene_main = scenes.CreateScene();
    Camera camera{0.1f,0.5f,2.f};
    scene_main->assign_from_copy(camera);
    scenes.LoadScene(scene_main);
    // add entity
    Entity box = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
    scene_main->AddEntity(box);

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        engine->Update();
    }
    glfwTerminate();
    return 0;
}