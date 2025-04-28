/******************************************************************************
 *   "$Id: $"
 *
 *   This file is part of the FLE project. 
 *
 *                 Copyright (c) 2000  O'ksi'D
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 *   Author : Jean-Marc Lienher ( http://oksid.ch )
 *
 ******************************************************************************/
#ifndef gui_h
#define gui_h

#include <FL/Fl_Double_Window.H>
#include <FL/Fl.H>
#include <FL/x.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Button.H>


class Gui : public Fl_Group {
public:
	Fl_Pixmap *pix;
	int pix_x;
	int pix_y;
	int v_speed;
	int h_speed;
	Gui(int X, int Y, int W, int H);
	~Gui();
	void draw(void);
	int handle(int e);
	static void runner(Gui *self);
	void mover(void);
};


#endif
