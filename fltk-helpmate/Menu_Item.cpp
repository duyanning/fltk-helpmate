#include "pch.h"
#include "Menu_Item.h"

void Menu_Item::callback_func()
{
	//std::cout << "Menu_Item::callback_func" << std::endl;
	eventClicked.fire(this);
}
