#include "Utils.h"
#include <sstream>
#include <iostream>
#include <vector>
#include "StreamLog.h"
using namespace std;

void parseDateTime (const string & dateTimeString, DateTime & dateTimeStruct) {
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
    
    dateTimeStruct.date = dateStr;
    dateTimeStruct.hour = hours;
    dateTimeStruct.minute = mins;
    dateTimeStruct.second = seconds;
}

bool CheckFileExist(const string & fileName)
{
    ifstream file("../TestInfo/"+fileName);
    return file.good();
}

void deleteUrlOptions (string & url) {
    vector <string> tokens;
    split <vector <string>> (url, tokens, '?');
    vector<string>::iterator begin = tokens.begin();
    vector<string>::iterator end = tokens.end();
    if (begin == end) {
        return;
    }
    url = *begin;
    vector <string> tokens2;
    split <vector <string>> (url, tokens2, ';');
    begin = tokens2.begin();
    end = tokens2.end();
    if (begin == end) {
        return;
    }
    url = *begin;
}