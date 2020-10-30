// oricad_version.h

/*
 * This file is part of Oricad, a computer-aided origami design tool
 *
 * Copyright (c) 2020 Simon Marynissen <marynissen.simon@gmail.com>
 *
 * Oricad is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Oricad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Oricad.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_ORICAD_VERSION
#define INCLUDED_ORICAD_VERSION

#include <oricad_config_export.h>

#include <string>

namespace oricad {

struct ORICAD_CONFIG_EXPORT Version {
  static unsigned int major();
  static unsigned int minor();
  static unsigned int patch();
  static std::string full();
  static std::string gitHash();
};

}

#endif