/*************************************************************************
                           StreamLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <StreamLog> (fichier StreamLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "StreamLog.h"
#include "Utils.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void StreamLog::ReadFile(const string &fileName)
{
    this->open(fileName);
}

Log * StreamLog::GetLog()
{
    string line;
    
    if (!this->eof()) {
        std::getline(*this, line);
        cout << line << endl;
    } else {
        cerr << "You reached the end of the file" << endl;
        return NULL;
    }

    if (line == "") {
        return NULL;
    }
    stringstream ss;
    
    vector <string> tokens;
    split<vector <string>>(line, tokens);
    vector<string>::const_iterator begin = tokens.begin();
    vector<string>::const_iterator end = tokens.end();
    
    string ipAddress = *(begin++);
    string userLogName = *(begin++);
    string userName = *(begin++);
    string dateTimeString = (*(begin++)).substr(1);
    DateTime dt = parseDateTime(dateTimeString);
    Time t (dt.hour, dt.minute, dt.second);
    ++begin;
    string requestType = (*(begin++)).substr(1);
    string url = *(begin++);
    ++begin;
    int responseCode;
    ss << *(begin++);
    ss >> responseCode;
    int amountOfData;
    ss << *(begin++);
    ss >> amountOfData;
    string referer = *(begin++);
    string browser = *(begin++);

    cout << "extraction done" << endl;

    return new Log(
        ipAddress,
        userLogName,
        userName,
        dt.date,
        t,
        requestType,
        url,
        responseCode,
        amountOfData,
        referer,
        browser
    );

}

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & out, const Time & t) {
    out << "[" << t.hour << ":" << t.minute << ":" << t.second << "]";
    return out;
}

ostream & operator << (ostream & out, const Log & log) {
    out << "LOG { " << endl;
    out << "\t \"ipAddress\": " << log.ipAddress << "," << endl;
    out << "\t \"userLogName\": " << log.userLogName << "," << endl;
    out << "\t \"userName\": " << log.userName << "," << endl;
    out << "\t \"requestDate\": " << log.requestDate << "," << endl;
    out << "\t \"requestTime\": " << log.requestTime << "," << endl;
    out << "\t \"requestType\": " << log.requestType << "," << endl;
    out << "\t \"url\": " << log.url << "," << endl;
    out << "\t \"responseCode\": " << log.responseCode << "," << endl;
    out << "\t \"amoutOfData\": " << log.amoutOfData << "," << endl;
    out << "\t \"referer\": " << log.referer << "," << endl;
    out << "\t \"browserInfo\": " << log.browserInfo << "," << endl;
    out << "}" << endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
StreamLog::StreamLog(const StreamLog &unStreamLog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <StreamLog>" << endl;
#endif
} //----- Fin de StreamLog (constructeur de copie)

StreamLog::~StreamLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <StreamLog>" << endl;
#endif
} //----- Fin de ~StreamLog

StreamLog::StreamLog(const string &fileName):
    ifstream(fileName)
{
    if (!(*this)) {
        cerr << "erreur d'ouverture du fichier" << endl;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées