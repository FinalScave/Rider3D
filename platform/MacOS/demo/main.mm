#import <AppKit/AppKit.h>
#import "bx/thread.h"
#import "bgfx/platform.h"
#include "RiderEngine.h"
#import "TimeUtil.h"

#define WIDTH  1024
#define HEIGHT 728

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    bool terminated;
}
+ (AppDelegate*)sharedDelegate;

- (id)init;

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender;

- (bool)applicationHasTerminated;
@end

@interface Window : NSObject <NSWindowDelegate> {
}
+ (Window*)sharedDelegate;

- (id)init;

- (void)windowCreated:(NSWindow*)window;

- (void)windowWillClose:(NSNotification*)notification;

- (BOOL)windowShouldClose:(NSWindow*)window;
@end

int windowLoop(int argc, const char* const* argv);

namespace demo {
    struct MainThreadEntry {
        int m_argc;
        const char* const* m_argv;

        static int runWindowLooper(bx::Thread* _thread, void* _userData) {
            CFBundleRef mainBundle = CFBundleGetMainBundle();
            if (mainBundle != nil) {
                CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
                if (resourcesURL != nil) {
                    char path[PATH_MAX];
                    if (CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8*)path, PATH_MAX) ) {
                        chdir(path);
                    }
                    CFRelease(resourcesURL);
                }
            }
            MainThreadEntry* self = (MainThreadEntry*)_userData;
            int result = windowLoop(self->m_argc, self->m_argv);
            [[NSApplication sharedApplication] terminate:nil];
            return result;
        }
    };

    void createWindow(float x, float y, UInt32 w, UInt32 h, const char* title);
    const int32_t defStyles = 0 | NSWindowStyleMaskTitled
            | NSWindowStyleMaskResizable | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable;
    bool exited = false;
    bx::Mutex lock;
    NSWindow* window = nullptr;

    int32_t run(int argc, const char* const* argv) {
        NSApplication* app = [NSApplication sharedApplication];
        // 设置NSApplication
        id appDelegate = [AppDelegate sharedDelegate];
        [app setDelegate:appDelegate];
        [app setActivationPolicy:NSApplicationActivationPolicyRegular];
        [app activateIgnoringOtherApps:YES];
        [app finishLaunching];

        // 发送NSApplication周期事件通知
        [[NSNotificationCenter defaultCenter]
                postNotificationName:NSApplicationWillFinishLaunchingNotification
                              object:app];

        [[NSNotificationCenter defaultCenter]
                postNotificationName:NSApplicationDidFinishLaunchingNotification
                              object:app];

        // 菜单
        id quitMenuItem = [NSMenuItem new];
        [quitMenuItem
                initWithTitle:@"Quit"
                       action:@selector(terminate:)
                keyEquivalent:@"q"];

        id appMenu = [NSMenu new];
        [appMenu addItem:quitMenuItem];

        id appMenuItem = [NSMenuItem new];
        [appMenuItem setSubmenu:appMenu];

        id menubar = [[NSMenu new] autorelease];
        [menubar addItem:appMenuItem];
        [app setMainMenu:menubar];

        // 新建窗口
        NSRect screenRect = [[NSScreen mainScreen] frame];
        const float centerX = (screenRect.size.width - WIDTH) * 0.5f;
        const float centerY = (screenRect.size.height - HEIGHT) * 0.5f;
        createWindow(centerX, centerY, WIDTH, HEIGHT, "Rider3D");

        // 启动运行线程
        MainThreadEntry mte{};
        mte.m_argc = argc;
        mte.m_argv = argv;
        bx::Thread thread;
        thread.init(MainThreadEntry::runWindowLooper, &mte);

        [app run];
        while (!(exited = [appDelegate applicationHasTerminated])) {
            bgfx::renderFrame();
        }
        while (bgfx::RenderFrame::NoContext != bgfx::renderFrame() ) {};
        thread.shutdown();
        return 0;
    }

    void createWindow(float x, float y, UInt32 w, UInt32 h, const char* title) {
        bx::MutexScope scope(lock);
        void (^createWindowBlock)(void) = ^(void) {
            NSRect rect = NSMakeRect(x, y, w, h);
            NSWindow* window = [
                    [NSWindow alloc]
                    initWithContentRect:rect
                              styleMask:(NSWindowStyleMask) defStyles
                                backing:NSBackingStoreBuffered
                                  defer:NO
            ];
            NSString* appName = [NSString stringWithUTF8String:title];
            [window setTitle:appName];
            [window makeKeyAndOrderFront:nil];
            [window setAcceptsMouseMovedEvents:YES];
            [window setBackgroundColor:[NSColor blackColor]];
            [[Window sharedDelegate] windowCreated:window];
            demo::window = window;
        };

        if ([NSThread isMainThread]) {
            createWindowBlock();
        } else {
            dispatch_async(dispatch_get_main_queue(), createWindowBlock);
        }
    }
}

@implementation AppDelegate
+ (AppDelegate*)sharedDelegate {
    static id delegate = [AppDelegate new];
    return delegate;
}

- (id)init {
    self = [super init];
    if (nil == self) {
        return nil;
    }
    self->terminated = false;
    return self;
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication*)sender {
    self->terminated = true;
    return NSTerminateCancel;
}

- (bool)applicationHasTerminated {
    return self->terminated;
}
@end

@implementation Window
+ (Window*)sharedDelegate {
    static id windowDelegate = [Window new];
    return windowDelegate;
}

- (id)init {
    self = [super init];
    if (nil == self) {
        return nil;
    }
    return self;
}

- (void)windowCreated:(NSWindow*)window {
    assert(window);
    [window setDelegate:self];
}

- (void)windowWillClose:(NSNotification*)notification {
    NSWindow* window = [notification object];
    [window setDelegate:nil];
}

- (BOOL)windowShouldClose:(NSWindow*)window {
    assert(window);
    return true;
}
@end

int main(int argc, const char* const* argv) {
    int result = demo::run(argc, argv);
    return result;
}

int windowLoop(int argc, const char* const* argv) {
    using namespace rider;
    NSWindow* window = demo::window;

    RenderConfig config{1024, 728, window, true};
    RiderEngine* engine = new RiderEngine(config);
    SceneManager& scenes = engine->GetScenes();
    Scene* mainScene = scenes.CreateScene();
    mainScene->assign<Camera>(Camera{-0.3f,0.5f,3.f});
    auto debugInfo = mainScene->assign<DebugInfo>(DebugInfo{1, 1});
    scenes.LoadScene(mainScene);

    EntityManager& entities = engine->GetEntities();
    // add entity
    Entity box1 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::TriangularPyramid);
    box1.assign<Transform>(Transform{{-0.8, 0.3f}, {0, 0.5, 0}});
    mainScene->AddEntity(box1);
    /*Entity box2 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
    box2.assign<Transform>(Transform{{1, 0.5f}});
    mainScene->AddEntity(box2);*/
    Entity box3 = engine->GetScenes().CreatePrimitiveEntity(PrimitiveType::Box);
    box3.assign<Transform>(Transform{{-0.5, -0.5}});
    mainScene->AddEntity(box3);

    UInt64 start = 0;
    while ([[NSApplication sharedApplication] isRunning]) {
        start = TimeUtil::MilliTime();
        engine->Update();
        UInt64 fps = 1000 / (TimeUtil::MilliTime() - start);
        debugInfo->text = [[NSString stringWithFormat:@"FPS: %lld", fps] UTF8String];
    }
    return 0;
}