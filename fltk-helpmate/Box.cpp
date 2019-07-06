#include "pch.h"
#include "Box.h"
#include "StringPrison.h"

Box::Box(int X, int Y, int W, int H, const std::string l)
	: Fl_Box(X, Y, W, H, intern(l))
{
}
