#include <rtthread.h>

void init_entry(void *param)
{
    rt_device_t device;
	/* init driver */
	rt_hw_sdl_start();
	device = rt_device_find("sdl");
	rtgui_graphic_set_device(device);

	/* init gui system */
	rtgui_system_server_init();

	application_init();
}

int rt_application_init()
{
    rt_thread_t tid;

    tid = rt_thread_create("init",
                           init_entry, RT_NULL,
                           2048, RT_THREAD_PRIORITY_MAX / 4, 20);

    if (tid != RT_NULL)
        rt_thread_startup(tid);

    return 0;
}
