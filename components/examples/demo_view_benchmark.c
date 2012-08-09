#include <rtgui/dc.h>
#include <rtgui/dc_hw.h>
#include <rtgui/rtgui_system.h>
#include <rtgui/widgets/container.h>
#include "demo_view.h"

#define RAND(x1, x2) ((rand() % (x2 - x1)) + x1)

static struct rtgui_container *container = RT_NULL;
static int running = 0;

void _onidle(struct rtgui_object *object, rtgui_event_t *event)
{
	rtgui_color_t color;
	rtgui_rect_t rect, draw_rect;
	struct rtgui_dc *dc;

	/* 获得控件所属的DC */
	// dc = rtgui_dc_hw_create(RTGUI_WIDGET(container)); 
	dc = rtgui_dc_begin_drawing(RTGUI_WIDGET(container));
	if (dc == RT_NULL)
		return;

	demo_view_get_logic_rect(RTGUI_CONTAINER(container), &rect);
	draw_rect.x1 = RAND(rect.x1, rect.x2);
	draw_rect.y1 = RAND(rect.y1, rect.y2);
	draw_rect.x2 = RAND(draw_rect.x1, rect.x2);
	draw_rect.y2 = RAND(draw_rect.y1, rect.y2);

	color = RTGUI_RGB(rand() % 255, rand() % 255, rand() % 255);
	RTGUI_WIDGET_BACKGROUND(container) = color;

	rtgui_dc_fill_rect(dc, &draw_rect);

	/* 绘图完成 */
	rtgui_dc_end_drawing(dc);
}

void _draw_default(struct rtgui_object *object, rtgui_event_t* event)
{
	struct rtgui_widget *widget = RTGUI_WIDGET(object);
	struct rtgui_dc* dc;
	rtgui_rect_t rect;

	/* 因为用的是demo container，上面本身有一部分控件，所以在绘图时先要让demo container先绘图 */
	rtgui_container_event_handler(object, event);

	/* 获得控件所属的DC */
	dc = rtgui_dc_begin_drawing(widget);
	if (dc == RT_NULL) /* 如果不能正常获得DC，返回（如果控件或父控件是隐藏状态，DC是获取不成功的） */
		return;

	/* 获得demo container允许绘图的区域 */
	demo_view_get_logic_rect(RTGUI_CONTAINER(widget), &rect);

	/* 擦除所有 */
	RTGUI_WIDGET_BACKGROUND(widget) = default_background;
	rtgui_dc_fill_rect(dc, &rect);

	/* 显示提示 */
	rtgui_dc_draw_text(dc, "按任意键开始/停止测试...", &rect);

	/* 绘图完成 */
	rtgui_dc_end_drawing(dc);
}

rt_bool_t benchmark_event_handler(struct rtgui_object *object, rtgui_event_t *event)
{
	if (event->type == RTGUI_EVENT_PAINT)
	{
		_draw_default(object, event);
	}
	else if (event->type == RTGUI_EVENT_KBD)
	{
		struct rtgui_event_kbd *kbd = (struct rtgui_event_kbd*)event;

		if (kbd->key == RTGUIK_LEFT || kbd->key == RTGUIK_RIGHT)
			return RT_FALSE;

		if (RTGUI_KBD_IS_UP(kbd))
		{
			if (running)
			{
				/* stop */
				rtgui_app_set_onidle(RT_NULL);
				_draw_default(object, event);
			}
			else
			{
				/* run */
				rtgui_app_set_onidle(_onidle);
			}

			running = !running;
		}
		return RT_TRUE;
	}
	else
	{
		/* 调用默认的事件处理函数 */
		return rtgui_container_event_handler(object, event);
	}

	return RT_FALSE;
}

static rt_bool_t _benchmark_onshow(struct rtgui_object *obj, struct rtgui_event* ev)
{
	rtgui_widget_focus(RTGUI_WIDGET(obj));
	return RT_TRUE;
}

rtgui_container_t *demo_view_benchmark(void)
{
	srand(100);
	container = demo_view("绘图测试");
	RTGUI_WIDGET(container)->flag |= RTGUI_WIDGET_FLAG_FOCUSABLE;
	rtgui_object_set_event_handler(RTGUI_OBJECT(container), benchmark_event_handler);
	rtgui_widget_set_onshow(RTGUI_WIDGET(container), _benchmark_onshow);

	return container;
}
