//
//   Copyright (C) 2011 by sinamas <sinamas at users.sourceforge.net>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License version 2 for more details.
//
//   You should have received a copy of the GNU General Public License
//   version 2 along with this program; if not, write to the
//   Free Software Foundation, Inc.,
//   51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef MMPRIORITY_H_
#define MMPRIORITY_H_

#include "uncopyable.h"
#include <QtGlobal> // Q_OS_WIN define

class SetThreadPriorityAudio : Uncopyable {
public:
	SetThreadPriorityAudio();
	~SetThreadPriorityAudio();

#ifdef Q_OS_WIN
private:
	void *const handle_;
#endif
};

#endif /* MMPRIORITY_H_ */
