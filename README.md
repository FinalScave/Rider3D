# 项目结构
```
├── 3dparty 第三方C++库
└── platform 各平台SDK工程
    └── Android Android平台SDK工程
    └── iOS iOS平台SDK工程
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
2. 运行

## Xcode
1. 安装 cocoapods 和 cmake
2. 进入 platform/iOS 目录，执行 pod install
2. 打开 Unknown3DWprkspace.xcworkspace，Build And Run

## VSCode
1. 如果是Windows系统，安装 [MinGW64](https://zenlayer.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) 和 CMake；
   如果是MacOS系统，安装 Xcode 和 cmake
2. 打开该工程，安装C/C++ Extension Pack(包含CMake)
3. 使用CMake插件在IDE左侧添加的CMake选项运行或执行 build-(mac/windows).sh 都可

## Clion
1. 直接打开该工程即可