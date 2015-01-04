#include <rtthread.h>
#include <rtgui/rtgui_app.h>
#include <rtgui/widgets/container.h>
#include <rtgui/widgets/window.h>
#include <rtgui/widgets/filelist_view.h>

void filelist_app_init(void *parameter)
{
    struct rtgui_app *application;
    struct rtgui_win *win;

    application = rtgui_app_create("filelist");
    if (application != RT_NULL)
    {
        struct rtgui_rect rect;
        rtgui_filelist_view_t *view;

        win = rtgui_mainwin_create(RT_NULL, "filelist",
                                   RTGUI_WIN_STYLE_MAINWIN | RTGUI_WIN_STYLE_DESTROY_ON_CLOSE);

        rtgui_widget_get_extent(RTGUI_WIDGET(win), &rect);

        view = rtgui_filelist_view_create("/", "*.*", &rect);
        rtgui_container_add_child(RTGUI_CONTAINER(win), RTGUI_WIDGET(view));

        rtgui_win_show(win, RT_TRUE);
        rtgui_app_destroy(application);
    }
}

void filelist_app_create(void *p)
{
    rt_thread_t tid;

    tid = rt_thread_create("filelist", filelist_app_init, RT_NULL,
                           2048, 20, 8);
    if (tid != RT_NULL) rt_thread_startup(tid);
}
#include <finsh.h>
FINSH_FUNCTION_EXPORT(filelist_app_create, filelist gui app run);
