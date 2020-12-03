#if !defined(UTILS_H)
#define UTILS_H

#include <string>
#include <sstream>
#include "StreamLog.h"

using namespace std;

template <typename T>
void split (string str, T & container, char delimiter = ' ') {
    stringstream ss (str);
    string token;
    while (std::getline(ss, token, delimiter)) {
        container.push_back(token);
    }
}

DateTime & parseDateTime (const string & dateTimeString);

#endif