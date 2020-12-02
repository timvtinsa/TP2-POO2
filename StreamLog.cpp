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

//------------------------------------------------------ Include personnel
#include "StreamLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type StreamLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
StreamLog & StreamLog::operator = ( const StreamLog & unStreamLog )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
StreamLog::StreamLog ( const StreamLog & unStreamLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <StreamLog>" << endl;
#endif
} //----- Fin de StreamLog (constructeur de copie)


StreamLog::StreamLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <StreamLog>" << endl;
#endif
} //----- Fin de StreamLog


StreamLog::~StreamLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <StreamLog>" << endl;
#endif
} //----- Fin de ~StreamLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées