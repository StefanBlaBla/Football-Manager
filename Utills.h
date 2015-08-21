#ifndef UTILLS_H
#define UTILLS_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

namespace util
{
    static std::vector<std::string> splitToString(const std::string& str, char delimiter) {
        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;

        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }

    static std::vector<short> splitToShort(const std::string& str, char delimiter) {
        std::vector<short> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;


        while(getline(ss, tok, delimiter)) {
           internal.push_back((short)std::atoi(tok.c_str()));
        }

        return internal;
    }
}

#endif // UTILLS_H
