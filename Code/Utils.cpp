#include "Utils.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "StreamLog.h"
using namespace std;

DateTime & parseDateTime (const string & dateTimeString) {
    vector <string> dateTimeTokens;
    split<vector<string>> (dateTimeString, dateTimeTokens, ':');
    vector<string>::const_reverse_iterator rBegin = dateTimeTokens.rbegin();
    vector<string>::const_reverse_iterator rEnd = dateTimeTokens.rend();
    if (rBegin == rEnd) {
        cerr << "End of vector reached" << endl;
    }
    int seconds = stoi(*(rBegin++));
    if (rBegin == rEnd) {
        cerr << "End of vector reached" << endl;
    }
    int mins = stoi(*(rBegin++));
    if (rBegin == rEnd) {
        cerr << "End of vector reached" << endl;
    }
    int hours = stoi(*(rBegin++));
    if (rBegin == rEnd) {
        cerr << "End of vector reached" << endl;
    }
    string dateStr = *(rBegin++);
    DateTime* dt = new DateTime (dateStr, hours, mins, seconds);
    return *dt;
}

bool CheckFileExist(const string & fileName)
{
    ifstream file("../TestInfo/"+fileName);
    return file.good();
}