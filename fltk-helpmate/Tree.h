#pragma once

#include <string>
#include <FL/Fl_Tree.H>

#include "EVENT_TYPE.hpp"

class Tree :
	public Fl_Tree
{
public:
	Tree(int X, int Y, int W, int H, const std::string l = "");
	EVENT_TYPE(ItemSelectedEvent, (Tree* tree, Fl_Tree_Item* item), (tree, item));
	ItemSelectedEvent eventItemSelected;
private:
	static void s_callback_func(Fl_Widget* w, void* data)
	{
		static_cast<Tree*>(w)->callback_func();
	}

	void callback_func();
};

