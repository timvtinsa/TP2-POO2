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
    } else {
        cerr << "You reached the end of the file" << endl;
        return NULL;
    }

    if (line == "") {
        return NULL;
    }
    
    vector <string> tokens;
    split<vector <string>>(line, tokens);
    vector<string>::const_iterator begin = tokens.begin();
    
    string ipAddress = *(begin++);
    string userLogName = *(begin++);
    string userName = *(begin++);
    string dateTimeString = (*(begin++)).substr(1);
    DateTime dt;
    parseDateTime(dateTimeString, dt);
    ++begin;
    string requestType = (*(begin++)).substr(1);
    string url = *(begin++);
    deleteUrlOptions(url);
    ++begin;
    int responseCode = -1;
    try {
        responseCode = stoi(*(begin++));
    } 
    catch (invalid_argument & ia) {
        //cerr << "Getting response code failed" << endl;
    }
    int amountOfData = -1;
    try {
        amountOfData = stoi(*(begin++));
    } catch (invalid_argument & ia) {
        //cerr << "Getting amount of data failed" << endl;
    }
    string referer = *(begin++);
    deleteUrlOptions(referer);
    trim(referer, '"');
    string browser = *(begin++);

    return new Log(
        ipAddress,
        userLogName,
        userName,
        dt,
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

ostream & operator << (ostream & out, const DateTime datetime) {
    out << "[" << datetime.date << " | " << datetime.hour << ":" << datetime.minute << ":" << datetime.second << "]";
    return out;
}

ostream & operator << (ostream & out, const Log & log) {
    out << "LOG { " << endl;
    out << "\t \"ipAddress\": " << log.ipAddress << "," << endl;
    out << "\t \"userLogName\": " << log.userLogName << "," << endl;
    out << "\t \"userName\": " << log.userName << "," << endl;
    out << "\t \"requestDateTime\": " << log.requestDateTime << "," << endl;
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
    ifstream("../TestInfo/"+fileName)
{
#ifdef MAP
    cout << "Appel au constructeur de <StreamLog>" << endl;
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées