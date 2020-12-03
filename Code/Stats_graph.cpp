/*************************************************************************
                           Stats_graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Stats_graph> (fichier Stats_graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Stats_graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Stats_graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// Stats_graph & Stats_graph::operator = ( const Stats_graph & unStats_graph )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Stats_graph::Stats_graph ( const Stats_graph & unStats_graph )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats_graph>" << endl;
#endif
} //----- Fin de Stats_graph (constructeur de copie)


Stats_graph::Stats_graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats_graph>" << endl;
#endif
} //----- Fin de Stats_graph


Stats_graph::~Stats_graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats_graph>" << endl;
#endif
} //----- Fin de ~Stats_graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées