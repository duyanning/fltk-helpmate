#include <iostream>
#include <functional>
#include <FL/Fl.H>
#include "Window.h"
#include "Box.h"
#include "Button.h"
#include "Input.h"
#include "StringPrison.h"


using namespace std;

void test_string_prison()
{
	std::string s1{ "abc" };
	std::string s2{ "abc" };
	cout << (void*)s1.c_str() << ", " << (void*)s2.c_str() << endl;


	cout << (void*)intern(s1) << ", "
		<< (void*)intern(s2) << ", "
		<< (void*)intern("abc")
		<< endl;
	cout << "ok" << endl;
}

void foo(int* sender, int& e)
{
	cout << "adfafsa" << endl;
}

void test_function()
{
	std::function<void(int*, int&)> f1 = foo;
	std::function<void(int*, int&)> f2 = [](int* sender, int& e) { cout << "adfafsa" << endl; };
}

int main(int argc, char** argv)
{
	//test_string_prison();
	//return 0;

	Window* window = new Window(340, 280);

	//BoxImpl* box = new Box(20, 40, 300, 100, "dyn");
	//box->box(FL_UP_BOX);
	//box->labelfont(FL_BOLD + FL_ITALIC);
	//box->labelsize(36)5
	//box->labeltype(FL_SHADOW_LABEL);

	Input* input = new Input(60, 40, 200, 30, "name:");
	input->event_changed.addListener([&](int* sender, int& e) { cout << input->when() << endl; });

	Button* button = new Button(20, 100, 300, 100, "ok");
	button->labelfont(FL_BOLD + FL_ITALIC);
	button->labelsize(36);
	button->labeltype(FL_SHADOW_LABEL);
	//button->click.addListener(foo);
	button->eventClicked.addListener([&](Button*) { cout << button->when() << endl; });

	window->end();
	window->show(argc, argv);





	return Fl::run();
}