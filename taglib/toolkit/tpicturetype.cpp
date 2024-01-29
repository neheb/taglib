/***************************************************************************
    copyright            : (C) 2023 by Urs Fleisch
    email                : ufleisch@users.sourceforge.net
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#include "tpicturetype.h"

#include "tstring.h"

#include <algorithm>
#include <array>

using namespace TagLib;

namespace {

  const std::array typeStrs {
    String("Other"),
    String("File Icon"),
    String("Other File Icon"),
    String("Front Cover"),
    String("Back Cover"),
    String("Leaflet Page"),
    String("Media"),
    String("Lead Artist"),
    String("Artist"),
    String("Conductor"),
    String("Band"),
    String("Composer"),
    String("Lyricist"),
    String("Recording Location"),
    String("During Recording"),
    String("During Performance"),
    String("Movie Screen Capture"),
    String("Coloured Fish"),
    String("Illustration"),
    String("Band Logo"),
    String("Publisher Logo"),
  };

}  // namespace

String Utils::pictureTypeToString(int type)
{
  if(type >= 0 && type < static_cast<int>(typeStrs.size())) {
    return typeStrs[type];
  }
  return "";
}

int Utils::pictureTypeFromString(const String& str)
{
  auto it = std::find(typeStrs.begin(), typeStrs.end(), str);
  return static_cast<int>(std::distance(typeStrs.begin(), it));
}
