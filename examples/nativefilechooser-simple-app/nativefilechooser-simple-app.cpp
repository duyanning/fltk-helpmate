//
// "$Id: nativefilechooser-simple-app.cxx 10005 2013-10-22 09:09:53Z manolo $"
//
//	An example of how to use Fl_Native_File_Chooser to open & save files.
//
// Copyright 2010 Greg Ercolano.
// Copyright 1998-2010 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     http://www.fltk.org/COPYING.php
//
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//
#include <stdio.h>	// printf
#include <stdlib.h>	// exit,malloc
#include <string.h>	// strerror
#include <errno.h>	// errno
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
//#include <FL/Fl_Menu_Bar.H>
#include "Menu_Bar.h"
#include "Menu_Item.h"
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>

#pragma comment(lib, "fltk-helpmate")

class Application : public Fl_Window {
	Fl_Native_File_Chooser* fc;
	// Does file exist?
	int exist(const char* filename) {
		FILE* fp = fl_fopen(filename, "r");
		if (fp) { fclose(fp); return(1); }
		else { return(0); }
	}
	// 'Open' the file
	void open(const char* filename) {
		printf("Open '%s'\n", filename);
	}
	// 'Save' the file
	//    Create the file if it doesn't exist
	//    and save something in it.
	//
	void save(const char* filename) {
		printf("Saving '%s'\n", filename);
		if (!exist(filename)) {
			FILE* fp = fl_fopen(filename, "w");				// create file if it doesn't exist
			if (fp) {
				// A real app would do something useful here.
				fprintf(fp, "Hello world.\n");
				fclose(fp);
			}
			else {
				fl_message("Error: %s: %s", filename, strerror(errno));
			}
		}
		else {
			// A real app would do something useful here.
		}
	}
	// Handle an 'Open' request from the menu
	//static void open_cb(Fl_Widget* w, void* v) {
	void open_cb(Menu_Item* menu_item) {
		//Application* app = (Application*)v;
		Application* app = this;
		app->fc->title("Open");
		app->fc->type(Fl_Native_File_Chooser::BROWSE_FILE);		// only picks files that exist
		switch (app->fc->show()) {
		case -1: break;	// Error
		case  1: break; 	// Cancel
		default:		// Choice
			app->fc->preset_file(app->fc->filename());
			app->open(app->fc->filename());
			break;
		}
	}
	// Handle a 'Save as' request from the menu
	//static void saveas_cb(Fl_Widget* w, void* v) {
	void saveas_cb(Menu_Item* menu_item) {
		//Application* app = (Application*)v;
		Application* app = this;
		app->fc->title("Save As");
		app->fc->type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);	// need this if file doesn't exist yet
		switch (app->fc->show()) {
		case -1: break;	// Error
		case  1: break; 	// Cancel
		default:		// Choice
			app->fc->preset_file(app->fc->filename());
			app->save(app->fc->filename());
			break;
		}
	}
	// Handle a 'Save' request from the menu
	//static void save_cb(Fl_Widget* w, void* v) {
	void save_cb(Menu_Item* menu_item) {
		//Application* app = (Application*)v;
		Application* app = this;
		if (strlen(app->fc->filename()) == 0) {
			//saveas_cb(w, v);
			saveas_cb(menu_item);
		}
		else {
			app->save(app->fc->filename());
		}
	}
	//static void quit_cb(Fl_Widget* w, void* v) {
	void quit_cb(Menu_Item* menu_item) {
		exit(0);
	}
	// Return an 'untitled' default pathname
	const char* untitled_default() {
		static char* filename = 0;
		if (!filename) {
			const char* home =
				getenv("HOME") ? getenv("HOME") :		 // unix
				getenv("HOME_PATH") ? getenv("HOME_PATH") :	 // windows
				".";						 // other
			filename = (char*)malloc(strlen(home) + 20);
			sprintf(filename, "%s/untitled.txt", home);
		}
		return(filename);
	}
public:
	// CTOR
	Application() : Fl_Window(400, 200, "Native File Chooser Example") {
		//Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, 400, 25);
		Menu_Bar* menu = new Menu_Bar(0, 0, 400, 25);
		//menu->add("&File/&Open", FL_COMMAND + 'o', open_cb, (void*)this);
		Menu_Item* menu_item = menu->add("&File/&Open", FL_COMMAND + 'o');
		menu_item->eventClicked.addListener(this, &Application::open_cb);
		//menu->add("&File/&Save", FL_COMMAND + 's', save_cb, (void*)this);
		menu_item = menu->add("&File/&Save", FL_COMMAND + 's');
		menu_item->eventClicked.addListener(this, &Application::save_cb);
		//menu->add("&File/&Save As", 0, saveas_cb, (void*)this);
		menu_item = menu->add("&File/&Save As", 0);
		menu_item->eventClicked.addListener(this, &Application::saveas_cb);
		//menu->add("&File/&Quit", FL_COMMAND + 'q', quit_cb);
		menu_item = menu->add("&File/&Quit", FL_COMMAND + 'q');
		menu_item->eventClicked.addListener(this, &Application::quit_cb);
		// Describe the demo..
		Fl_Box* box = new Fl_Box(20, 25 + 20, w() - 40, h() - 40 - 25);
		box->color(45);
		box->box(FL_FLAT_BOX);
		box->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);
		box->label("This demo shows an example of implementing "
			"common 'File' menu operations like:\n"
			"    File/Open, File/Save, File/Save As\n"
			"..using the Fl_Native_File_Chooser widget.\n\n"
			"Note 'Save' and 'Save As' really *does* create files! "
			"This is to show how behavior differs when "
			"files exist vs. do not.");
		box->labelsize(12);
		// Initialize the file chooser
		fc = new Fl_Native_File_Chooser();
		fc->filter("Text\t*.txt\n");
		fc->preset_file(untitled_default());
		end();
	}
};

int main(int argc, char* argv[]) {
	Fl::scheme("gtk+");
	Application* app = new Application();
	app->show(argc, argv);
	return(Fl::run());
}

//
// End of "$Id: nativefilechooser-simple-app.cxx 10005 2013-10-22 09:09:53Z manolo $".
//
