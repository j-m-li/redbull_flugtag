#
# "$Id:  $"
#
# Top-level makefile .
#
# Copyright 1998-2000 by Bill Spitzak and others.
#
# This is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published
# by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
#
#

SHELL	=	/bin/sh
DIRS	=	\
src

all:	Makedefs
	@for dir in $(DIRS); do\
		echo "=== making $$dir ===";\
		if test ! -f $$dir/makedepend; then\
			touch $$dir/makedepend;\
		fi;\
		(cd $$dir; $(MAKE) -$(MAKEFLAGS)) || break;\
	done

install: Makedefs
	@for dir in $(DIRS); do\
		echo "=== installing $$dir ===";\
		if test ! -f $$dir/makedepend; then\
			touch $$dir/makedepend;\
		fi;\
		(cd $$dir; $(MAKE) -$(MAKEFLAGS) install) || break;\
	done
	(cd documentation; $(MAKE) -$(MAKEFLAGS) install)

clean:
	-@ rm -f core config.cache *.o *.bck
	@for dir in $(DIRS); do\
		echo "=== cleaning $$dir ===";\
		(cd $$dir; $(MAKE) -$(MAKEFLAGS) clean) || break;\
	done

distclean: clean
	rm -f config.log config.h config.status Makedefs

Makedefs: configure config.h.in Makedefs.in
	./configure

#
# End of "$Id: $".
#
