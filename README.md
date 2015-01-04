# Overview

RTGUI is one of the components of RT-Thread. It aims at providing a
easy-to-use GUI library for embedded systems. Thanks to the integration with
RT-Thread, it's much easier to develop. This GUI could provide ways for
human-machine interaction interface such as HMI, information display, music
player. The features of RTGUI contains:

*  multi threaded GUI
*  real time GUI depend on RT-Thread
*  object-oriented design in C:
    -  run time type identification
    -  automatic object destruction
*  theme support
*  Chinese text display
*  plenty of widgets:
    -  button, checkbox, radiobox
    -  textbox
    -  progressbar, slider
    -  list view, file list view
    -  et al

# Usage

1. direct usage(run in Windows via simulation)

    Install VS(2008+, express edition should be OK), run scons on the root
    directory of this project. There will be two executeables in the folder
    executeables/. One is demo.exe, the other is demo_shell.exe. After copying
    resource/ and $RTT_ROOT/bsp/simulator/SDL/lib/x86/SDL.dll to executeables/,
    you are ready to run the programs above.

2. use it in RT-Thread

    Because RT-Thread has removed RTGUI component. You have to copy
    `components/rtgui` to the `components` folder. If you need demo, you should
    copy all the files in `demo/examples` to the examples/gui folder under RTT.
    Don't forget to re-run scons.

