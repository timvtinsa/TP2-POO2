/*************************************************************************
                           Stats_graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats_graph> (fichier Stats_graph.h) ----------------
#if ! defined( MAIN_H )
#define MAIN_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "StreamLog.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Filter {
    bool exclude;
    int hour;
    bool hourFiltered;
    Filter ( const bool excludeLog = false, const int hr = 0, const bool hrFiltered = false) :
        exclude(excludeLog), hour(hr), hourFiltered(hrFiltered) {}
};


bool logFilter (const Log & aLog, const Filter & aFilter);

bool CheckFileExist(const string & fileName);

void readFile(string fileName); //Vérifier si cette fonction est utile


#endif 

