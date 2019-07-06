#include "pch.h"
#include "Input.h"

Input::Input(int X, int Y, int W, int H, const std::string l)
	:
	Fl_Input(X, Y, W, H, intern(l))
{
	callback(s_callback_func, 0);
	when(FL_WHEN_CHANGED); // Fl_Input默认不调用任何回调
}

void Input::callback_func()
{
	//std::cout << "InputImpl" << std::endl;
	int e;
	event_changed.fire(0, e);

}
