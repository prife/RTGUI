# 简介

RTGUI 是一系列 RT-Thread 组件的一部分。它的目的是为开发人员提供一个便于在嵌入式
系统中使用的图形界面库。以其和 RT-Thread 天然集成的优势，方便开发人员开发。这个
图形用户界面组件能够为RT-Thread上的应用程序提供人机界面交互的功能，例如人机界面
设备，设备信息显示，播放器界面等。图形用户界面组件的功能包括：

*  多线程图形用户界面；
*  依赖于RT-Thread线程调度器的实时图形用户界面；
*  C语言方式的全面向对象设计：
    -  对象具备运行时类型信息；
    -  对象自动销毁，使得内存的管理更为轻松；
*  界面主题支持；
*  中文文本显示支持；
*  丰富的控件支持：
    -  button，checkbox，radiobox
    -  textbox
    -  progressbar，slider
    -  列表视图，文件列表视图
    -  等等

# 使用方法

1. 直接使用(在 windows 中模拟运行)

    安装好 VS(2008+，express版应该就可以)，在根目录下运行 scons。这时在
    executeables 目录下会有两个可执行文件。一个是 demo，一个是 demo_shell。把
    resource/ 和 $RTT_ROOT/bsp/simulator/SDL/lib/x86/ 里的 SDL.dll 复制到
    executeables 里即可运行以上应用程序。

2. 在 RT-Thread 中使用

    由于 RT-Thread 上游已经将 RTGUI 组件删除，所以如果需要在 RT-Thread 中运行
    RTGUI的话需要将 components/rtgui 复制到 RTT 的 components 文件夹之下。如果
    需要运行demo，需要将 demo/examples 内的所有文件复制到 RTT 的 examples/gui/
    目录下(没有目录的需要创建一个)。然后再在你的工程目录里重新运行 scons 即可。

