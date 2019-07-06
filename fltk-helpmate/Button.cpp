#include "pch.h"
#include "Button.h"

Button::Button(int X, int Y, int W, int H, const std::string l)
	:
	Fl_Button(X, Y, W, H, intern(l))
{
	callback(s_callback_func, 0);
}

void Button::callback_func()
{
	//std::cout << "ButtonImpl" << std::endl;
	eventClicked.fire(this);

}
