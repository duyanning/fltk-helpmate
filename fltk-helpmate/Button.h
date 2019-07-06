#pragma once

#include <string>
#include <FL/Fl_Button.H>

#include "EVENT_TYPE.hpp"

class Button :
	public Fl_Button
{
public:
	Button(int X, int Y, int W, int H, const std::string l);
	EVENT_TYPE(ClickEvent, (Button* button), (button));
	ClickEvent eventClicked;
private:
	static void s_callback_func(Fl_Widget* w, void* data)
	{
		static_cast<Button*>(w)->callback_func();
	}

	void callback_func();
};
