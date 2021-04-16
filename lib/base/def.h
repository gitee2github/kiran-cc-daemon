/*
 * @Author       : tangjie02
 * @Date         : 2020-05-29 18:16:08
 * @LastEditors  : tangjie02
 * @LastEditTime : 2020-09-02 14:28:16
 * @Description  : 
 * @FilePath     : /kiran-cc-daemon/lib/base/def.h
 */

#pragma once

#include <fmt/format.h>

#include <cstdio>
#include <functional>
#include <vector>

namespace Kiran
{
#define GETTEXT_PACKAGE "kiran-cc-daemon"

#define SYSTEMD_NAME "org.freedesktop.systemd1"
#define SYSTEMD_PATH "/org/freedesktop/systemd1"
#define SYSTEMD_MANAGER_INTERFACE "org.freedesktop.systemd1.Manager"
#define SYSTEMD_UNIT_INTERFACE "org.freedesktop.systemd1.Unit"

#define POLKIT_NAME "org.freedesktop.PolicyKit1"
#define POLKIT_PATH "/org/freedesktop/PolicyKit1/Authority"
#define POLKIT_INTERFACE "org.freedesktop.PolicyKit1.Authority"

#define EPS 1e-4

#define CHECK_XMLPP_ELEMENT(node, err)                                                                       \
    {                                                                                                        \
        const auto element = dynamic_cast<const xmlpp::Element *>(node);                                     \
                                                                                                             \
        if (!element)                                                                                        \
        {                                                                                                    \
            err = fmt::format("the type of the node '{0}' isn't xmlpp::Element.", node->get_name().c_str()); \
            return false;                                                                                    \
        }                                                                                                    \
    }

#define CONNECTION(text1, text2) text1##text2
#define CONNECT(text1, text2) CONNECTION(text1, text2)

class Defer
{
public:
    Defer(std::function<void(std::string)> func, std::string fun_name) : func_(func),
                                                                         fun_name_(fun_name) {}
    ~Defer() { func_(fun_name_); }

private:
    std::function<void(std::string)> func_;
    std::string fun_name_;
};

// helper macro for Defer class
#define SCOPE_EXIT(block) Defer CONNECT(_defer_, __LINE__)([&](std::string _arg_function) block, __FUNCTION__)

#define RETURN_VAL_IF_FALSE(cond, val)            \
    {                                             \
        if (!(cond))                              \
        {                                         \
            LOG_DEBUG("The condition is false."); \
            return val;                           \
        }                                         \
    }

#define RETURN_VAL_IF_TRUE(cond, val) \
    {                                 \
        if (cond) return val;         \
    }

#define RETURN_IF_FALSE(cond)                     \
    {                                             \
        if (!(cond))                              \
        {                                         \
            LOG_DEBUG("The condition is false."); \
            return;                               \
        }                                         \
    }

#define RETURN_IF_TRUE(cond) \
    {                        \
        if (cond) return;    \
    }

#define CONTINUE_IF_FALSE(cond) \
    {                           \
        if (!(cond)) continue;  \
    }

#define CONTINUE_IF_TRUE(cond) \
    {                          \
        if (cond) continue;    \
    }

#define IGNORE_EXCEPTION(expr)          \
    {                                   \
        try                             \
        {                               \
            expr;                       \
        }                               \
        catch (const Glib::Error &e)    \
        {                               \
        }                               \
        catch (const std::exception &e) \
        {                               \
        }                               \
    }

#define POINTER_TO_STRING(p) ((p) ? p : std::string())

using StringHash = uint32_t;

constexpr StringHash prime = 9973;
constexpr StringHash basis = 0xCBF29CE4ul;
constexpr StringHash hash_compile_time(char const *str, StringHash last_value = basis)
{
    return *str ? hash_compile_time(str + 1, (StringHash)((*str ^ last_value) * (uint64_t)prime)) : last_value;
}

inline StringHash shash(char const *str)
{
    StringHash ret{basis};

    while (*str)
    {
        ret ^= *str;
        ret *= prime;
        str++;
    }

    return ret;
}

/// compile-time hash of string.
/// usage: "XXX"_hash
constexpr StringHash operator"" _hash(char const *p, size_t)
{
    return hash_compile_time(p);
}

}  // namespace Kiran
