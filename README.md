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
## Clion
1. 直接打开该工程即可

## Visual Studio Code
1. 如果是Windows系统，安装 [MinGW64](https://zenlayer.dl.sourceforge.net/project/mingw-w64/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/sjlj/x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z) 和 [CMake](https://cmake.org/files/v3.10/cmake-3.10.2-win64-x64.msi)；
   如果是MacOS系统，安装 Xcode 和 cmake
2. 打开该工程，安装C/C++ Extension Pack(包含CMake)
3. 按 Ctrl + F5 运行
   (如果无法运行，就使用CMake插件在IDE左侧添加的CMake选项运行)

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

## ~~Visual Studio~~
`由于MSVC适配麻烦，对VS的支持废弃`
1. 使用Visual Studio Installer安装C++工具(包含适用于Windows的CMake工具)
2. 打开项目根目录，选择启动项为 `Unknown3DDemo.exe`

# 开发路线
参见[项目规划](1st-plan/1-Structure/index.md)

# 代码命名规范
## 文件命名
文件名使用大驼峰命名, 可以包含下划线 () 或连字符 (-)。举例：
```
MyClass.cpp

1> C++ 文件要以 .cpp 结尾, 头文件以 .h 结尾. 专门插入文本的文件则以 .inc 结尾
2> 内联函数直接放在.h文件中
```
## 类型命名
【类, 结构体, 类型定义 (typedef), 枚举, 类型模板参数 均为类型】，以大写字母开始, 每个单词首字母均大写, 不包含下划线。
举例:
```
// 类和结构体
class UrlTable { ...
class UrlTableTester { ...
struct UrlTableProperties { ...

// 类型定义
typedef hash_map<UrlTableProperties *, string> PropertiesMap;

// using 别名
using PropertiesMap = hash_map<UrlTableProperties *, string>;

// 枚举
enum UrlTableErrors { ...
```
## 变量命名
变量 (包括函数参数) 和数据成员名一律小写, 单词之间用下划线连接. 类的成员变量以下划线结尾, 但结构体内部的变量的就不用。
### 普通变量命名
```
string table_name;  // 好 - 用下划线.
string tablename;   // 好 - 全小写.

string tableName;  // 差 - 混合大小写
```
### 类数据成员变量
```
class TableInfo {
...
private:
   string table_name_;  // 好 - 后加下划线.
   string tablename_;   // 好.
   static Pool<TableInfo>* pool_;  // 好.
};
```
### 结构体成员变量
```
struct UrlTableProperties {
   string name;
   int num_entries;
   static Pool<UrlTableProperties>* pool;
};
```
### 全局变量
对全局变量没有特别要求, 少用就好, 但如果要用, 可以用 g 或其它标志作为前缀, 以便更好的区分局部变量.
### 常量命名
声明为 constexpr 或 const 的变量, 或在程序运行期间其值始终保持不变的, 命名时以 “k” 开头, 大小写混合，举例：
```
const int kDaysInAWeek = 7;
```
## 函数命名
函数名的每个单词首字母大写 (即 “驼峰变量名” 或 “帕斯卡变量名”)，没有下划线，举例：
```
AddTableEntry()
DeleteUrl()
OpenFileOrDie()
```
## 枚举命名
枚举的命名使用大驼峰命名或全大写命名。举例：
```
enum UrlTableErrors {
   Ok = 0,
   ErrorOutOfMemory,
   ErrorMalformedInput,
};
enum AlternateUrlTableErrors {
   OK = 0,
   OUT_OF_MEMORY = 1,
   MALFORMED_INPUT = 2,
};
```
## 宏命名
命名全部大写, 单词间使用下划线。举例：
```
#define ROUND(x) ...
#define PI_ROUNDED 3.0
```