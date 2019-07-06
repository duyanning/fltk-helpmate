#include "pch.h"
#include "Tree.h"

Tree::Tree(int X, int Y, int W, int H, const std::string l)
	:
	Fl_Tree(X, Y, W, H, intern(l))
{
	callback(s_callback_func, 0);
}

void Tree::callback_func()
{
	Fl_Tree_Item* item = (Fl_Tree_Item*)this->callback_item();
	if (!item) return;
	switch (this->callback_reason()) {
	case FL_TREE_REASON_SELECTED: {
		eventItemSelected.fire(this, item);
		//char pathname[256];
		//this->item_pathname(pathname, sizeof(pathname), item);
		//fprintf(stderr, "TreeCallback: Item selected='%s', Full pathname='%s'\n", item->label(), pathname);
		break;
	}
	case FL_TREE_REASON_DESELECTED:
		// fprintf(stderr, "TreeCallback: Item '%s' deselected\n", item->label());
		break;
	case FL_TREE_REASON_OPENED:
		// fprintf(stderr, "TreeCallback: Item '%s' opened\n", item->label());
		break;
	case FL_TREE_REASON_CLOSED:
		// fprintf(stderr, "TreeCallback: Item '%s' closed\n", item->label());
		break;
#if FLTK_ABI_VERSION >= 10301
		// To enable this callback, use tree->item_reselect_mode(FL_TREE_SELECTABLE_ALWAYS);
	case FL_TREE_REASON_RESELECTED:
		// fprintf(stderr, "TreeCallback: Item '%s' reselected\n", item->label());
		break;
#endif
	default:
		break;
	}
}
