/**
 * @file          /kiran-cc-daemon/plugins/appearance/theme/theme-parse.h
 * @brief         
 * @author        tangjie02 <tangjie02@kylinos.com.cn>
 * @copyright (c) 2020 KylinSec. All rights reserved. 
 */

#pragma once

#include "appearance-i.h"
#include "lib/base/base.h"
#include "plugins/appearance/theme/theme-monitor.h"

namespace Kiran
{
struct ThemeBase
{
    // 主题类型
    AppearanceThemeType type;
    // 主题名
    std::string name;
    // 主题加载优先级
    int32_t priority;
    // 主题路径
    std::string path;
};

struct ThemeMeta : public ThemeBase
{
    std::string gtk_theme;
    std::string metacity_theme;
    std::string icon_theme;
    std::string cursor_theme;
};

using ThemeInfoVec = std::vector<std::shared_ptr<ThemeBase>>;

class ThemeParse
{
public:
    ThemeParse(std::shared_ptr<ThemeMonitorInfo> monitor_info);
    virtual ~ThemeParse(){};

    std::shared_ptr<ThemeBase> parse();
    std::shared_ptr<ThemeBase> parse_base();

private:
    std::shared_ptr<ThemeBase> parse_meta();
    std::shared_ptr<ThemeBase> parse_gtk();
    std::shared_ptr<ThemeBase> parse_metacity();
    std::shared_ptr<ThemeBase> parse_icon();
    std::shared_ptr<ThemeBase> parse_cursor();

    std::shared_ptr<ThemeBase> file_base(std::shared_ptr<ThemeBase> theme_base, AppearanceThemeType type);
    std::string get_theme_path(const std::string& path, AppearanceThemeType type);

private:
    std::shared_ptr<ThemeMonitorInfo> monitor_info_;

    static std::map<ThemeMonitorType, AppearanceThemeType> monitor2theme_;
};
}  // namespace Kiran