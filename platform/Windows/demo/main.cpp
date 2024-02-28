#include <windows.h>
#include <windowsx.h>
#include "RiderEngine.h"
#include "component/BasicComponents.h"
#include "bx/thread.h"
#include "bgfx/platform.h"
#include "TimeUtil.h"

#define WIDTH 1024
#define HEIGHT 720

using namespace NS_RIDER;

HWND window = nullptr;
bool m_render_finished = false;

struct RenderThreadEntry {
    static int32_t render(bx::Thread* _thread, void* _userData) {
        RenderConfig config{1024, 728, window, true};
        RiderEngine* engine = new RiderEngine(config);
        SceneManager& scenes = engine->GetScenes();
        Scene* mainScene = scenes.CreateScene();
        mainScene->assign<Camera>(Camera{0.1f,0.5f,2.f});
        auto debugInfo = mainScene->assign<DebugInfo>(DebugInfo{1, 1});
        scenes.LoadScene(mainScene);

        // add entity
        Entity box1 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Rectangle);
        box1.assign<Transform>(Transform{{-1, 0.5f}});
        mainScene->AddEntity(box1);
        Entity box2 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
        box2.assign<Transform>(Transform{{1, 0.5f}});
        mainScene->AddEntity(box2);
        Entity box3 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
        box3.assign<Transform>(Transform{{-0.5, -0.5}});
        mainScene->AddEntity(box3);

        UInt64 start = 0;
        while (!m_render_finished) {
            start = TimeUtil::MilliTime();
            engine->Update();
            UInt64 fps = 1000 / (TimeUtil::MilliTime() - start);
            char buf[10] = {0};
            sprintf(buf, "FPS: %lld", fps);
            debugInfo->text = buf;
        }
        return 0;
    }
};

LRESULT process(HWND _hwnd, UINT _id, WPARAM _wparam, LPARAM _lparam) {
    switch (_id) {
        case WM_CLOSE:
            m_render_finished = true;
            DestroyWindow(_hwnd);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_QUIT:
            m_render_finished = true;
            // Don't process message. Window will be destroyed later.
            return 0;
    }
    return DefWindowProcW(_hwnd, _id, _wparam, _lparam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd) {
    SetDllDirectoryA(".");

    HINSTANCE instance = (HINSTANCE)GetModuleHandle(NULL);

    WNDCLASSEXW wnd;
    bx::memSet(&wnd, 0, sizeof(wnd) );
    wnd.cbSize = sizeof(wnd);
    wnd.style = CS_HREDRAW | CS_VREDRAW;
    wnd.lpfnWndProc = process;
    wnd.hInstance = instance;
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.lpszClassName = L"Rider3D";
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    RegisterClassExW(&wnd);

    window = CreateWindowExA(
            WS_EX_ACCEPTFILES
            , "Rider3D"
            , "Rider3D"
            , WS_OVERLAPPEDWINDOW|WS_VISIBLE
            , 0
            , 0
            , WIDTH
            , HEIGHT
            , NULL
            , NULL
            , instance
            , 0
    );

    RenderThreadEntry render_thread;
    bx::Thread thread;
    thread.init(RenderThreadEntry::render, &render_thread);

    MSG msg;
    msg.message = WM_NULL;
    while (!m_render_finished) {
        while (PeekMessageW(
                &msg, NULL, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
    thread.shutdown();
    return thread.getExitCode();
}