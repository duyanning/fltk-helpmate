#pragma once

#include <string>
#include <FL/Fl_Window.H>



class Window :
	protected Fl_Window
{
public:
	Window(int w, int h, std::string title = "");
	Window(int x, int y, int w, int h, std::string title = "");

	using Fl_Window::end;
	using Fl_Window::show;
};

