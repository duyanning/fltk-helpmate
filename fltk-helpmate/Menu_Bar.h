#pragma once

#include <string>
#include <FL/Fl_Menu_Bar.H>

#include "EVENT_TYPE.hpp"

class Menu_Item;

class Menu_Bar :
	public Fl_Menu_Bar
{
public:
	Menu_Bar(int X, int Y, int W, int H, const std::string l = "");
	//EVENT_TYPE(ClickEvent, (Button* button), (button));
	//ClickEvent eventClicked;

	Menu_Item* add(std::string label, int shortcut);

private:
	//static void s_callback_func(Fl_Widget* w, void* data)
	//{
	//	//static_cast<Button*>(w)->callback_func();
	//}

	//void callback_func();
};

