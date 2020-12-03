/*************************************************************************
                           Stats_graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats_graph> (fichier Stats_graph.h) ----------------
#if ! defined ( STATS_GRAPH_H )
#define STATS_GRAPH_H

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Target {
    unordered_map<string, int> referors;
    int total;
};

//------------------------------------------------------------------------
// Rôle de la classe <Stats_graph>
//
//
//------------------------------------------------------------------------

class Stats_graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Stats_graph & operator = ( const Stats_graph & unStats_graph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stats_graph ( const Stats_graph & unStats_graph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stats_graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stats_graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private :
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    typedef unordered_map<string, Target> TargetsMap;
    TargetsMap targets;

};

//-------------------------------- Autres définitions dépendantes de <Stats_graph>

#endif // STATS_GRAPH_H

