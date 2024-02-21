# 项目结构
```
├── 1st-plan 项目开发路线规划
├── 3dparty 第三方C++库
└── platform 各平台SDK工程
    └── Android Android平台SDK工程
    └── iOS iOS平台SDK工程
    └── Linux Linux平台SDK工程
    └── MacOS MacOS平台SDK工程
    └── Windows Windows平台SDK工程
├── shaders 存放bgfx shader文件
├── src C++源代码目录
└── tools 相关工具存放目录
```

# 开发环境
## Android Studio
1. 打开 platform/Android 工程，并安装ndk和cmake
2. 在 local.properties 文件指定ndk和cmake路径<br>
```kotlin
  ndk.dir=[ndk安装路径]
  cmake.dir=[cmake安装路径]
```
3. 运行

## Xcode
1. 安装 cocoapods 和 cmake
2. 进入 platform/iOS 目录，执行 pod install
3. 打开 Unknown3DWorkspace.xcworkspace，Build And Run

## VSCode
1. 如果是Windows系统，安装 [MinGW64](https://zenlayer.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) 和 [CMake](https://cmake.org/files/v3.10/cmake-3.10.2-win64-x64.msi)；
   如果是MacOS系统，安装 Xcode 和 cmake
2. 打开该工程，安装C/C++ Extension Pack(包含CMake)
3. 按 Ctrl + F5 运行
   (如果无法运行，就使用CMake插件在IDE左侧添加的CMake选项运行)

## Clion
1. 直接打开该工程即可

# 开发路线
参见[项目规划](1st-plan/1.Structure.md)