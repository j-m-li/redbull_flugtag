/******************************************************************************
 *   "$Id:  $"
 *
 *
 *                 Copyright (c) 2001  O'ksi'D
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

#include "gui.h"
#include <FL/fl_draw.h>
#include "iron.xpm"

Gui::Gui(int X, int Y, int W, int H) : Fl_Group(X, Y, W, H)
{
	pix_y = 159;
	pix_x = 350;
	h_speed = 0;
	v_speed = 0;
	pix = new Fl_Pixmap(iron_xpm);
}

Gui::~Gui()
{
	delete(pix);
}

void Gui::draw()
{
	char *txt;

	fl_color(FL_WHITE);
	fl_rectf(0, 0, w(), h());
	
	fl_color(FL_BLACK);
	fl_rectf(350, 200, 250, 3);

	fl_color(FL_BLUE);
	fl_rectf(0, 300, 350, 100);

	fl_color(FL_GRAY);
	fl_rectf(350, 300, 250, 100);

	fl_color(FL_YELLOW);
	fl_pie(10,10, 40, 40, 0, 360);

	fl_color(FL_GRAY);
	fl_font(0, 14);
	txt = "RED BULL FLUGTAG 2001";
	fl_draw(txt, strlen(txt), 350, 40);
	txt = "8 SEPTEMBRE, LAUSANNE-OUCHY";
	fl_draw(txt, strlen(txt), 350, 60);
	txt = "\"FLYING IRON\" team Nickasil production";
	fl_draw(txt, strlen(txt), 300, 20);

	pix->draw(pix_x, pix_y);
	
	Fl_Group::draw();
}

int Gui::handle(int e)
{
	static int px = -1;
	switch(e) {
	case FL_PUSH:
		if (pix_x != 350) {
			pix_y = 159;
			pix_x = 350;
			h_speed = 0;
			v_speed = 0;
			px = -1;
			redraw();
			return 1;
		}
		if (Fl::event_x() > pix_x && Fl::event_x() < pix_x + 40 &&
			Fl::event_y() > pix_y && Fl::event_y() < pix_y + 40) 
		{
			px = Fl::event_x();
		} else {
			px = -1;
		}
		return 1;
	case FL_DRAG:
		if (px > 0) {
			pix_x = Fl::event_x() - 20;
			if (pix_x < 350) pix_x = 350;
			redraw();
		}
		return 1;
	case FL_RELEASE:
		if (px > 0) {
			runner(this);
		}
		break;
	}
	return Fl_Group::handle(e);
}

void Gui::runner(Gui *self)
{
	self->mover();
	if (self->pix_y < 300) {
		Fl::add_timeout(0.030, (Fl_Timeout_Handler) runner, self);
	}
}

void Gui::mover()
{
	if (pix_x < 310) {
		v_speed += 2;
		pix_x -= h_speed;
		pix_y += v_speed;
	} else {
		h_speed += 1;
		pix_x -= h_speed;
	}
	redraw();
}
