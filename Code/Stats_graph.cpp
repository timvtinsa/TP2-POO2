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
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Stats_graph.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



void Stats_graph::BuildGraphFile (const string & fileName)
{
    NodesMap nodesMatch;
    string links;

    Target targetTest;
    Target targetTest2;
    Target targetTest3;
    targetTest.referors.insert(make_pair("R0",15));
    targetTest2.referors.insert(make_pair("foeuhg",6));
    targetTest3.referors.insert(make_pair("C1",5));
    targets.insert(make_pair("C1",targetTest));
    targets.insert(make_pair("Ceiuhg",targetTest2));
    targets.insert(make_pair("R0",targetTest3));
    int nodeNumber =0;

    for(TargetsMap ::const_iterator itTarget=targets.begin() ; itTarget!=targets.end() ; ++itTarget)
    {
        string key = itTarget->first;
        if (nodesMatch.find(key) == nodesMatch.end())
        {
          addNode(nodesMatch,nodeNumber,itTarget->first);
        }

        for(ReferorsMap ::const_iterator itReferor=itTarget->second.referors.begin() ; itReferor!=itTarget->second.referors.end() ; ++itReferor)
        {
            string key = itReferor->first;
            if (nodesMatch.find(key) == nodesMatch.end())
            {
                addNode(nodesMatch,nodeNumber,itReferor->first);
            }
            writeLink (itReferor->second,links,itTarget->first,itReferor->first, nodesMatch);
        }
    }

    string nodesList;
    writeNodes( nodesMatch, nodesList);

    ofstream graphFile;
    graphFile.open(fileName);

    graphFile << "digraph {" << endl;
    graphFile << nodesList;
    graphFile << links;
    graphFile << "}" << endl;

    graphFile.close();

}
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
void Stats_graph::addNode ( NodesMap & nodes, int & nodeNb, const string & key) const
{
    stringstream ss;
    ss << nodeNb;
    string nodeNb2string;
    ss >> nodeNb2string;
    nodes.insert(make_pair(key,"node"+nodeNb2string));
    ++nodeNb;
}

string & Stats_graph::writeLink (const int nbHit, string & links, const string & target, const string & referor, NodesMap & nodes) const
{
    stringstream ss;
    ss << nbHit;
    string nbHits2string;
    ss >> nbHits2string;
    string tmp;
    tmp = nodes[referor] + " -> " + nodes[target] + " [label=" + '"' + nbHits2string + '"' + "];" + "\n";
    links = links + tmp;
    return links;
}

string & Stats_graph::writeNodes ( NodesMap & nodes, string & nodesList)
{
    for (NodesMap ::const_iterator it=nodes.begin() ; it !=nodes.end() ; ++it)
    {
        string tmp;
        tmp = it->second + " [label=" + '"' + it->first + '"' + "]" + ";" + "\n";
        nodesList = nodesList + tmp;
    }
    return nodesList;
}