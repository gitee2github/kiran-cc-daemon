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

#ifndef GREETER_NEW_INTERFACE
#warning This file will be deprecated. please use greeter-i.h file
#endif

#define GREETER_DBUS_NAME "com.kylinsec.Kiran.SystemDaemon.Greeter"
#define GREETER_OBJECT_PATH "/com/kylinsec/Kiran/SystemDaemon/Greeter"

#ifdef __cplusplus
extern "C"
{
#endif

    // 登录界面缩放模式
    enum GreeterScalingMode
    {
        // 手动设定缩放率
        GREETER_SCALING_MODE_AUTO = 0,
        // 手动设定缩放率
        GREETER_SCALING_MODE_MANUAL,
        // 禁用缩放
        GREETER_SCALING_MODE_DISABLE,
        GREETER_SCALING_MODE_LAST,
    };

#ifdef __cplusplus
}
#endif
