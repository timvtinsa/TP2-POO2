/*************************************************************************
                           StreamLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <StreamLog> (fichier StreamLog.h) ----------------
#ifndef STREAMLOG_H
#define STREAMLOG_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Time
{
    int hour;
    int minute;
    int second;

    Time(int hr, int min, int sec) : hour(hr), minute(min), second(sec) {}
};

ostream & operator << (ostream & out, const Time & t);

struct DateTime
{
    string date;
    int hour;
    int minute;
    int second;
    DateTime(string dt, int hr, int min, int sec) : date(dt), hour(hr), minute(min), second(sec) {}
};

struct Log
{
    string ipAddress;
    string userLogName;
    string userName;
    string requestDate;
    Time requestTime;
    string requestType;
    string url;
    int responseCode;
    int amoutOfData;
    string referer;
    string browserInfo;
    Log(const string &ip, const string &logName, const string &username, const string &date, const Time &timeLog, const string &rqType, const string &anurl,
        int responsecode, int dataAmount, const string &aReferer, const string &browser) : ipAddress(ip), userLogName(logName), userName(username), requestDate(date),
                                                                                           requestTime(timeLog), requestType(rqType), url(anurl), responseCode(responsecode), amoutOfData(dataAmount),
                                                                                           referer(aReferer), browserInfo(browser) {}
};

ostream & operator << (ostream & out, const Log & log);

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
    void ReadFile(const string &fileName);
    // Mode d'emploi :

    // Contrat :

    Log * GetLog();
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
    StreamLog(const StreamLog &unStreamLog);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    StreamLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    StreamLog(const string &fileName);

    virtual ~StreamLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <StreamLog>

#endif // STREAMLOG_H
