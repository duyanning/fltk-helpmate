#pragma once

#include <FL/Fl_Box.H>

class Box :
	protected Fl_Box
{
public:
	Box(int X, int Y, int W, int H, std::string l = "");

	using Fl_Box::box;
	using Fl_Box::labelfont;
	using Fl_Box::labelsize;
	using Fl_Box::labeltype;

};

