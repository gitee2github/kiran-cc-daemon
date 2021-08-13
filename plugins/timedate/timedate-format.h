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

#include "lib/base/base.h"

#define TIMEDATE_NEW_INTERFACE
#include "timedate_i.h"

namespace Kiran
{
class TimedateFormat
{
public:
    TimedateFormat();
    virtual ~TimedateFormat();

    void init();

    // 获取已设置的长格式索引，通过索引从长格式列表中查找格式字符串
    int32_t get_date_long_format_index();
    // 获取已设置的短格式索引，通过索引从短格式列表中查找格式字符串
    int32_t get_date_short_format_index();
    // 获取小时显示格式：12小时制和24小时制
    TimedateHourFormat get_hour_format();
    // 时间中是否显示秒
    bool get_seconds_showing();

    // 设置长格式
    bool set_date_long_format(int32_t index);
    // 设置短格式
    bool set_date_short_format(int32_t index);
    // 设置小时显示格式
    bool set_hour_format(TimedateHourFormat hour_format);
    // 设置是否显示秒
    bool set_seconds_showing(bool seconds_showing);

    // 获取可设置的长格式列表，格式字符串已根据语言环境进行翻译
    std::vector<std::string> get_long_formats();
    // 获取可设置的短格式列表
    std::vector<std::string> get_short_formats();

private:
    // 存储到配置
    bool save_to_config();

private:
    Glib::KeyFile format_config_;

    std::string format_config_path_;
};
}  // namespace Kiran