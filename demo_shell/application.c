#include <rtthread.h>
#include <rtgui/rtgui_server.h>
#include <rtgui/rtgui_system.h>
#include <rtgui/rtgui_app.h>

#include <mainmenu.h>

void picture_app_create(void *param);
void filelist_app_create(void*);

#define APPS_RESOURCE_PATH "/resource/apps"
void init_entry(void *param)
{
    mainmenu_register_internal_app("picture", "图片",
                                   rtgui_image_create(APPS_RESOURCE_PATH"/picture.png", RT_FALSE),
                                   picture_app_create, RT_NULL);
    mainmenu_register_internal_app("filelist", "文件",
                                   rtgui_image_create(APPS_RESOURCE_PATH"/filelist.png", RT_FALSE),
                                   filelist_app_create, RT_NULL);
    mainmenu_register_internal_app("任务", "",
                                   rtgui_image_create(APPS_RESOURCE_PATH"/status.png", RT_FALSE),
                                   tasklist_show, RT_NULL);
    app_mainui_init();
}

void rt_application_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("init",
                           init_entry, RT_NULL,
                           2048, RT_THREAD_PRIORITY_MAX / 4, 20);

    if (tid != RT_NULL)
        rt_thread_startup(tid);
}

