# 一、项目内容
本项目包含内容：
-[x] 日志系统
-[x] 渲染引擎（含二维图像引擎和三维图像引擎、字体渲染） 
-[ ] 资源管理
-[ ] 模型加载
-[ ] 场景管理
-[ ] 用户输入(触摸、键盘输入等)
-[ ] 音效
-[ ] 碰撞检测系统
-[ ] 粒子系统
-[ ] 动画系统
-[ ] 网络引擎
-[ ] 脚本引擎
-[ ] 物理引擎
-[ ] 编辑器

# 二、项目架构
## 1 前置介绍
本项目采用ECS(Entity-Component-System)架构
- 实体（Entity）代表独立的对象或物体。它们可以是游戏中的角色、道具、场景等等。
实体本身并不包含任何行为或功能，只是一个标识符或容器，用于关联和组织相关的组件。
- 组件（Component）是实体的一部分，用于描述实体的特定属性或行为。
例如，一个角色实体可能有一个位置组件、一个渲染组件、一个碰撞组件等等。
每个组件都是独立的，可以被添加或移除，以便根据需要定制实体的功能。
- 系统（System）是处理实体和组件的逻辑的模块。系统负责根据组件的状态和属性来执行特定的操作或行为。
例如，一个渲染系统可以根据实体的渲染组件来绘制图形，一个碰撞系统可以根据实体的碰撞组件来检测碰撞等等。
系统可以独立地操作组件，而不需要直接访问实体。
## 2 架构方向
以引擎使用者的角度来看，3D物体(Object)是引擎的核心，一个场景中会包含若干个3D物体，
结合ECS框架，可以作出如下决策：
1. 将Object规定为Entity，以树形结构呈现物体之间的关系，内置基本的3D物体（Box、Sphere、SkyBox等）
2. 将Object规定为Component容器，用户可对Object进行任意Component(如Transform的增删查改
3. 将System规定为控制器，根据Object和Component进行逻辑控制
4. EventManager负责事件的管理（订阅和发送），Object/Component/System都可以通过EventManager订阅事件
### 2.1 Object的索引方式
在常见的缓存索引机制中，常见的Key类型为ID和名称，参考Unity和UE4的Api设计，Unknown3D采用名称索引的方式
### 2.2 Manager形态
Manager采用单例模式，一个进程中只能存在一个SystemManager/EventManager/EntityManager

# 三、项目实现
## 渲染引擎
参见[渲染引擎实现概览](../2-Render/index.md)
## 资源管理
参见[资源管理器实现概览](../3-ResourceManager/index.md)
## 模型加载
参见[模型加载实现概览](../4-Model/index.md)
## 场景管理
参见[场景管理实现概览](../5-SceneManager/index.md)
## 用户输入
参见[用户输入实现概览](../6-Input/index.md)
## 音效
参见[音效实现概览](../7-Sound/index.md)
## 碰撞检测系统
参见[碰撞检测系统实现概览](../8-Collision/index.md)
## 粒子系统
参见[粒子系统实现概览](../9-Particle/index.md)
## 动画系统
参见[动画系统实现概览](../10-Animation/index.md)
## 网络引擎
参见[网络引擎实现概览](../11-Net/index.md)
## 脚本引擎
参见[脚本引擎实现概览](../12-Script/index.md)
## 物理引擎
参见[物理引擎实现概览](../13-PBR/index.md)
## 编辑器
参见[编辑器实现概览](../final-Editor/index.md)