#pragma once

class Widget :
	protected Fl_Widget
{
public:
	Widget(int X, int Y, int W, int H, const std::string l);
private:
	static void s_callback_func(Fl_Widget* w, void* data)
	{
		static_cast<Widget*>(w)->callback_func();
	}

	void callback_func()
	{
		std::cout << "WidgetImpl" << std::endl;
	}


};

