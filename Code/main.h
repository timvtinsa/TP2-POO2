/*************************************************************************
                           Stats_graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats_graph> (fichier Stats_graph.h) ----------------
#if ! defined ( MAIN_H )
#define MAIN_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "StreamLog.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Filter {
    string graphFile;
    bool exclude;
    string hour;
    Filter () : 
        graphFile(""), exclude(false), hour(""){}
};


bool filter (const Log & aLog, const Filter & aFilter);

#endif 

