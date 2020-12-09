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
#include <string>
#include "StreamLog.h"

//------------------------------------------------------------- Constantes
const int NUMBER_OF_ELEMENTS_TOP = 10;
//------------------------------------------------------------------ Types
typedef unordered_map<string, int> ReferorsMap;
typedef unordered_map<string,string> NodesMap;
struct Referers {
    ReferorsMap referors;
    int total;
};

ostream & operator << (ostream & out, const Referers & refs);

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
    //void InsertLog (const Log & logToInsert)
    //Insère le log passé en entrée dans statsAndGraph.TargetsMap

    void BuildGraphFile (const string & fileName);
    //Construit le fichier fileName.dot avec le code nécessaire pour générer le graphe


    // void DisplayTopTen ( const TopTen & theTop);
    //Surcharge de l'opérateur << pour afficher une cible avec la syntaxe ex: /page3.html (1 hits)

    void Add (const Log & log);

    void ShowTop10() const;

    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator << (ostream & out, const Stats_graph & stg);

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
    void addNode ( NodesMap & nodes, int & nodeNb, const string & key) const;

    string & writeLink (const int nbHit, string & links, const string & target, const string & referor, NodesMap & nodes) const;

    string & writeNodes ( NodesMap & nodes, string & nodesList );

    int findPositionInTop10(const string & targetName) const;

    int getTotal (const string & targetName) const;

    void insertInTop10(const string & targetName, int position);

    void updateTop10();
//----------------------------------------------------- Attributs protégés
    typedef unordered_map<string, Referers> TargetsMap;
    TargetsMap targets;
    string top10[10];
    int top10Size;

};

//-------------------------------- Autres définitions dépendantes de <Stats_graph>

#endif // STATS_GRAPH_H

