/**
 * @Copyright (C) 2020 ~ 2021 KylinSec Co., Ltd. 
 *
 * Author:     tangjie02 <tangjie02@kylinos.com.cn>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http: //www.gnu.org/licenses/>. 
 */

#pragma once

#include <string>

#include "plugins/display/xrandr-manager.h"

namespace Kiran
{
class DisplayUtil
{
public:
    DisplayUtil(){};
    virtual ~DisplayUtil(){};

    static std::string rotation_to_str(DisplayRotationType rotation);
    static std::string reflect_to_str(DisplayReflectType reflect);
    static DisplayRotationType str_to_rotation(const std::string &str);
    static DisplayReflectType str_to_reflect(const std::string &str);
};
}  // namespace Kiran