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
#include "StreamLog.h"
#include <unordered_map>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
<<<<<<< HEAD



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
=======
void Stats_graph::Add(const Log &log)
{
    // If the taget doesn't already exist
    if (this->targets.count(log.url) == 0)
    {
        Referers refs;
        string referorUrl = log.referer;
        pair <string, int> refPair (referorUrl, 1);
        refs.referors.insert(refPair);
        refs.total = 1;
        pair <string, Referers> targetPair (log.url, refs);
        this->targets.insert(targetPair);
    }
    else
    {
        string referorUrl = log.referer;
        TargetsMap::iterator target = this->targets.find(log.url);
        Referers refs = target->second;
        // If the target has already been refered by the referor
        if (refs.referors.count(referorUrl) == 1) {
            unordered_map<string, int>::iterator referers = refs.referors.find(referorUrl);
            referers->second = referers->second + 1;
        }else {
            pair <string, int> ref(referorUrl, 1);
            refs.referors.insert(ref);
        }
        refs.total++;
        target->second = refs;
    }
}

>>>>>>> stat_graph automatic creation
// type Stats_graph::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & out, const Referers & refs) {
    unordered_map<string, int>::const_iterator begin = refs.referors.begin();
    unordered_map<string, int>::const_iterator end = refs.referors.end();
    out << "REFERERS(total=" << refs.total << ") : {";
    for (; begin != end; begin++) {
        out << begin->first << ":" << begin->second << "|";
    }
    out << "}";
    return out;
}

ostream & operator << (ostream & out, const Stats_graph & stg) {
    unordered_map<string, Referers>::const_iterator begin = stg.targets.begin();
    unordered_map<string, Referers>::const_iterator end = stg.targets.end();
    out << "STATS_GRAPH {" << endl;
    out << "\ttargets {" << endl;
    for (; begin != end; begin++) {
        out << "\t\t" << begin->first << " : " << begin->second << endl;
    }
    out << "\t}" << endl;
    out << "}" << endl;
    return out;
}
// Stats_graph & Stats_graph::operator = ( const Stats_graph & unStats_graph )
// // Algorithme :
// //
// {
// } //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Stats_graph::Stats_graph(const Stats_graph &unStats_graph)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats_graph>" << endl;
#endif
} //----- Fin de Stats_graph (constructeur de copie)

Stats_graph::Stats_graph()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats_graph>" << endl;
#endif
} //----- Fin de Stats_graph

Stats_graph::~Stats_graph()
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