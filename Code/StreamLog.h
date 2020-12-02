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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    StreamLog & operator = ( const StreamLog & unStreamLog );
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

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <StreamLog>

#endif // STREAMLOG_H

