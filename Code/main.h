/*************************************************************************
                           main  -  Interface
                             -------------------
    début                : 2020
    copyright            : (C) 2020 par Timothé - Yanis
*************************************************************************/

//---------- Interface du module <main> (fichier main.h) -------------------
#if ! defined ( MAIN_H )
#define MAIN_H


/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "StreamLog.h"
#include "Stats_graph.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct Filter {
    bool exclude;
    int hour;
    bool hourFiltered;
    Filter ( const bool excludeLog = false, const int hr = 0, const bool hrFiltered = false) :
            exclude(excludeLog), hour(hr), hourFiltered(hrFiltered) {}
};

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

bool logFilter (const Log & aLog, const Filter & aFilter);
// Mode d'emploi :
// Cette fonction permet de vérifier si le log passé en entrée respecte le filtre lui
// aussi passé en entrée de la fonction.
// La fonctionne retourne un booléen qui prend la valeur true lorsque le log est conforme
// au filtre et prend la valeur false sinon.
//
// Contrat : Aucun
//

void BuildLogMap (const Filter optionsFilter, StreamLog & readStream,Stats_graph & statsAndGraph);
// Mode d'emploi :
// Cette fonction permet de construire notre objet statsAndGraph qui est une
// unordered_map<string, unordered_map<string, int>> à partir des logs (contenus
// dans le fichier de logs passé en entrée du programme) conformes au filtre passé
// en entrée de la fonction.
//
// Contrat : Aucun
//

int CheckLogFileName(const string & logFileName);
// Mode d'emploi :
// Cette fonction permet de vérifier si le nom du fichier de log passé en
// entrée du programme (via la commande bash de lancement) est conforme au
// format attendu, c'est-à-dire si le fichier donné est bien possède bien
// une extension .log
//
// Contrat : Aucun
//

int CheckGraphFileOption (const string & fileNameGraphOption);
// Mode d'emploi :
// Cette fonction permet de vérifier si le nom de fichier passé en entrée
// du programme (via la commande bash de lancement) est conforme au format attendu
// c'est-à-dire si le fichier possède bien une extension .dot
//
// Contrat : Aucun
//

int CheckHourOption ( const string & argHour, int argHour2int);
// Mode d'emploi :
// Cette fonction permet de vérifier si l'heure passée en entrée pour le
// filtrage selon une heure (dans la commande bash de lancement) est conforme
// au format attendu c'est-à-dire un nombre compris entre 0 et 23.
//
// Contrat : Aucun
//

bool IsAnOptionTag (const string & argument);
// Mode d'emploi :
// Cette fonction permet de vérifier un argument passé en entrée est une option
// c'est-à-dire si la chaîne passée en entrée correspond à -g -e ou -t
//
// Contrat : Aucun
//
#endif 

