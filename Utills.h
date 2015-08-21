#ifndef UTILLS_H
#define UTILLS_H

#include <vector>
#include <string>
#include <sstream>

namespace util
{
    static std::vector<std::string> split(const std::string& str, char delimiter) {

        std::vector<std::string> internal;
        std::stringstream ss(str); // Turn the string into a stream.
        std::string tok;

        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }

        return internal;
    }
}

#endif // UTILLS_H
