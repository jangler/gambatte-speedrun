//
//   Copyright (C) 2007 by sinamas <sinamas at users.sourceforge.net>
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

#ifndef HuC3Chip_H
#define HuC3Chip_H

enum
{
    HUC3_READ = 0,
    HUC3_WRITE = 1,
    HUC3_NONE = 2
};

#include <ctime>

namespace gambatte {

struct SaveState;

class HuC3Chip {
public:
	HuC3Chip();
	std::time_t baseTime() const { return baseTime_; }
	void setBaseTime(std::time_t baseTime) { baseTime_ = baseTime; }

	void saveState(SaveState &state) const;
	void loadState(SaveState const &state);
    void setRamflag(unsigned char ramflag) { ramflag_ = ramflag; }
    bool isHuC3() const { return enabled_; }

	void set(bool enabled) {
		enabled_ = enabled;
	}
    
    unsigned char read(unsigned p) const;
	void write(unsigned p, unsigned data);

private:
	std::time_t baseTime_;
	std::time_t haltTime_;
	unsigned dataTime_;
    unsigned writingTime_;
    unsigned char ramValue_;
    unsigned char shift_;
    unsigned char ramflag_;
    unsigned char modeflag_;
	bool enabled_;
	bool lastLatchData_;
    bool halted_;

	void doLatch();
    void updateTime();
};

}

#endif