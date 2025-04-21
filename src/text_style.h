#ifndef TEXT_STYLE
#define TEXT_STYLE

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace style
{
    /**
     * wraps the `contents` with unicode to make it green on console output
     */
    template <typename... Ts>
    string fg_green(Ts... contents)
    {
        ostringstream oss;
        (oss << "\033[32m" << ... << contents) << "\033[0m";
        return oss.str();
    }

    template <typename... Ts>
    string fg_red(Ts... contents)
    {
        ostringstream oss;
        (oss << "\033[31m" << ... << contents) << "\033[0m";
        return oss.str();
    }

    template <typename... Ts>
    string italic(Ts... contents)
    {
        ostringstream oss;
        (oss << "\033[3m" << ... << contents) << "\033[0m";
        return oss.str();
    }

}
#endif