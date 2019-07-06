#include "pch.h"
#include "Menu_Bar.h"
#include "Menu_Item.h"

Menu_Bar::Menu_Bar(int X, int Y, int W, int H, const std::string l)
	:
	Fl_Menu_Bar(X, Y, W, H, intern(l))
{
}

Menu_Bar::~Menu_Bar()
{
	//Fl_Menu_Item* fl_menu_item = const_cast<Fl_Menu_Item*>(menu()) + n;
	for (int i = 0; i < this->size(); i++) { 
		const Fl_Menu_Item& fl_menu_item = this->menu()[i];
		delete fl_menu_item.user_data();

	}
}

Menu_Item* Menu_Bar::add(std::string label, int shortcut)
{
	int n = Fl_Menu_::add(intern(label), shortcut, 0);

	Fl_Menu_Item* fl_menu_item = const_cast<Fl_Menu_Item*>(menu()) + n;

	Menu_Item* menu_item = new Menu_Item(fl_menu_item);
	fl_menu_item->user_data(menu_item);

	fl_menu_item->callback(Menu_Item::s_callback_func, menu_item);

	return menu_item;
}

//void Menu_Bar::callback_func()
//{
//	//eventClicked.fire(this);
//}