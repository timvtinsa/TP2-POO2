/*************************************************************************
                           StreamLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <StreamLog> (fichier StreamLog.h) ----------------
#if ! defined ( STREAMLOG_H )
#define STREAMLOG_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Time {
    int hour;
    int minute;
    int second;

    Time(const int hr, const int min, const int sec) :
        hour(hr), minute(min), second(sec) {}
};

struct Log {
    string ipAddress;
    string userLogName;
    string userName;
    string requestDate;
    Time requestTime; //  string requestTime;
    string url;
    int responseCode;
    int amoutOfData;
    string referer;
    string browserInfo;
    Log (string ip, string logName, string username, string date, Time timeLog, string anurl,
        int responsecode, int dataAmount, string aReferer, string browser):
            ipAddress(ip), userLogName(logName), userName(username), requestDate(date),
            requestTime(timeLog), url(anurl), responseCode(responsecode), amoutOfData(dataAmount),
            referer(aReferer), browserInfo(browser){}
};

//------------------------------------------------------------------------
// Rôle de la classe <StreamLog>
//
//
//------------------------------------------------------------------------

class StreamLog : public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    ifstream & ReadFile (const string & fileName);
    // Mode d'emploi :

    // Contrat :

    Log & GetLog();
    // Mode d'emploi

    // Contrat

    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    StreamLog ( const StreamLog & unStreamLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    StreamLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~StreamLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private :
    bool eof;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <StreamLog>

#endif // STREAMLOG_H

