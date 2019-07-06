#pragma once
#include <FL/Fl_Menu_Item.H>
#include "EVENT_TYPE.hpp"

class Menu_Bar;

class Menu_Item //:
	//public Fl_Menu_Item
{
	friend class Menu_Bar;
public:
	EVENT_TYPE(ClickEvent, (Menu_Item* menu_item), (menu_item));
	ClickEvent eventClicked;

	Menu_Item(Fl_Menu_Item* fl_menu_item)
	{
		m_fl_menu_item = fl_menu_item;
	}

	Fl_Menu_Item* fltk() { return m_fl_menu_item; }

	virtual ~Menu_Item()
	{
		delete m_fl_menu_item->user_data();
	}
private:
	Fl_Menu_Item* m_fl_menu_item;

	static void s_callback_func(Fl_Widget* w, void* data)
	{
		static_cast<Menu_Item*>(data)->callback_func();
	}

	void callback_func();
};

