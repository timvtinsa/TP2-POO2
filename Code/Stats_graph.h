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

    void BuildGraphFile (const string & fileName);
    // Mode d'emploi :
    // Cette méthode permet de construire le fichier .dot avec le code permettant de construire
    // le graphe à partir des données contenus dans l'objet qui appelle la méthode
    //
    // Contrat : Aucun
    //

    void Add (const Log & log);
    // Mode d'emploi :
    // Cette méthode permet d'ajouter un log dans l'objet statsAndGraph qui appelle la méthode.
    // Le contrôle de la validité du log se fait avant son ajout dans une autre fonction.
    //
    // Contrat : Aucun
    //

    void ShowTop10() const;
    // Mode d'emploi :
    // Cette méthode permet d'affciher le TOP 10 correspondant aux données contenues dans
    // l'objet statsAndGraph qui appelle la méthode.
    //
    // Contrat : Aucun
    //


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator << (ostream & out, const Stats_graph & stg);
    // Mode d'emploi :
    //
    // Contrat :
    //


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
    // Mode d'emploi :
    // Cette méthode permet d'jouter un noeud dans la map de noeuds qui stocke tous les
    // noeuds que l'on va devoir créer dans le graph associé à l'objet statsAndGraph
    //
    // Contrat :
    //

    string & writeLink (const int nbHit, string & links, const string & target, const string & referor, NodesMap & nodes) const;
    // Mode d'emploi :
    // Cette méthode permet d'écrire un lien entre deux noeuds pour le code de génération du graphe.
    //
    // Contrat : Aucun
    //

    string & writeNodes ( NodesMap & nodes, string & nodesList );
    // Mode d'emploi :
    // Cette méthode permet d'ajouter tous les noeuds contenus dans la map de
    // noeuds nodes passées en entrée dans une chaîne de caractères que l'on pourra
    // alors directement insérer dans le fichier .dot
    //
    // Contrat : Aucun
    //

    int findPositionInTop10(const string & targetName) const;
    // Mode d'emploi :
    // Cette méthode permet de trouver la postion d'une cible (dont le nom est
    // passée en entrée de la méthode) dans le tableau correspondant au TOP 10.
    //
    // Contrat : Aucun
    //

    int getTotal (const string & targetName) const;
    // Mode d'emploi :
    // Cette méthode permet d'obtenir le total des hits associé à une cible
    // (dont le nom est passé en entrée de la méthode).
    //
    // Contrat : Aucun
    //

    void insertInTop10(const string & targetName, int position);
    // Mode d'emploi :
    // Cette méthode permet d'insérer une cible dans le tableau du top 1à à une
    // positon donnée (passée en entrée)
    //
    // Contrat : Aucun
    //


    void updateTop10();
    // Mode d'emploi :
    // Cette méthode permet de mettre à jour le TOP 10.
    //
    // Contrat : Aucun
    //

//----------------------------------------------------- Attributs protégés
    typedef unordered_map<string, Referers> TargetsMap;
    TargetsMap targets;
    string top10[10];
    int top10Size;

};

//-------------------------------- Autres définitions dépendantes de <Stats_graph>

#endif // STATS_GRAPH_H

