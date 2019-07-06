#pragma once

#include <FL/Fl_Input.H>

#include "EVENT_TYPE.hpp"

class Input :
	public Fl_Input
{
public:
	Input(int X, int Y, int W, int H, const std::string l);
	EVENT_TYPE(ChangedEvent, (int* sender, int& e), (sender, e));
	ChangedEvent event_changed;
private:
	static void s_callback_func(Fl_Widget* w, void* data)
	{
		static_cast<Input*>(w)->callback_func();
	}

	void callback_func();
};
