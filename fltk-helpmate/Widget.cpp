#include "pch.h"

#include "Widget.h"

Widget::Widget(int X, int Y, int W, int H, const std::string l)
	:
	Fl_Widget(X, Y, W, H, intern(l))
{
	callback(s_callback_func, 0);
}
