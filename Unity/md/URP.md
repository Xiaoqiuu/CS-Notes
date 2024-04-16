---------
[TOC]

# 1. Unity升级项目到URP(通用渲染管线)以及画面后处理

## 综述
*URP*,全称为*Universal Render Pipeline*,即通用渲染管线。
Render Pipeline(渲染管线)可以称其为像素流水线，是显示芯片内部处理图形信号相互独立的并行处理单元。在最开始，Unity使用的是固定渲染管线，这样对于游戏开发者就没有个性化的调整空间，有一定的限制，所以后来出现了可编程渲染管线*SRP*

> 关于可编程渲染管线
> * 在Unity中，可编程渲染管线底层使用C++封装一些接口来提供给C#去调用，帮助游戏开发者在脚本中使用这些接口
> * 可编程渲染管线有URP和HDRP两种，URP主要面向低性能终端的一种渲染方式
> * 最开始URP叫做LWRP，未来可能会作为Unity的默认渲染管线

URP相比于默认渲染管线，在提升画质的同时，也可以通过一定的优化提升游戏的性能表现。

## 升级项目到URP
### 1. 开始前准备

记得备份项目（打包成`Package`来导出项目）。
做好备份后，就可以正式开始项目的升级工作，我们可以在导航栏中的`Window`选项中找到`Package Manager`，再找到`Universal RP`，然后点击安装。

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0001.png">

### 2. 将默认渲染管线替换为URP

导入URP插件后，在`Project`面板右键选择`Create - > Rendering - > Universal Render Pipeline - > Pipeline Asset`创建一个URP的Asset命名为`UrpTest`

<div align = center><img src = "C:\Archive\LanQiao\Unity\md\Pictures\0002.png"></div>
接下来在`Edit`中打开`Project Setting`面板，选择`Graphics`，然后再其中的`Scriptable Render Pipeline setting`中选择`UrpTest`

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0003.png">
完成上面的设置，就代表完成了将默认渲染管线替换为URP渲染管线的步骤。此时返回场景，场景真的是一片粉。。。

> 项目升级到URP产生的几个负面效果：
> * 标准材质失败，可以通过一键改回来
> * 自己创建地形所刷的树同样丢失，很难一键改回
> * 自己编写的大多Shader也会失效，只能重新编写

产生这种情况的原因是材质之前的`Shader`无法正常地被URP所识别渲染，所以我们要去改变其材质的Shader类型。

> 关于材质Shader类型：
> * 在默认渲染管线中模型的Material默认Shader为Standard，而当我们把项目升级到URP后，这种Shader类型不能被URP识别渲染
> * 我们可以手动把材质Shader改为URP支持的类型

快速调整：`Edit - > Render Pipeline - > Universal Render Pipeline - > Upgrade Project Materials to URP Materials`

还是有粉色的地方！这该怎么办呢？我的想法是：针对单独无法识别的Shader进行调整吧。。。（重做）

2024.2.19补充
可以创建新的默认材质（URP下），多选进行替换