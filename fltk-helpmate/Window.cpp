#include "pch.h"
#include "Window.h"
#include "StringPrison.h"

Window::Window(int w, int h, std::string title)
	: Fl_Window(w, h, intern(title))
{

}

Window::Window(int x, int y, int w, int h, std::string title)
	: Fl_Window(x, y, w, h, title.c_str())
{
}
