#ifndef VALIDATION
#define VALIDATION

#include <iostream>
#include <functional>

using namespace std;

namespace validation
{
    template <typename T>
    T getValidInput(istream &in, ostream &out, string prompt, string err_msg, function<bool(T)> isValid)
    {
        int n;
        out << prompt;
        in >> n;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!in.fail() && isValid(n))
            return n;
        else
        {
            out << err_msg;
            if (in.fail())
            {
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return getValidInput(in, out, prompt, err_msg, isValid);
        }
    }
}

#endif