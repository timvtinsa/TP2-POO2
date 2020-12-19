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
#include "Utils.h"
#include <unordered_map>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Stats_graph::BuildGraphFile (const string & fileName)
{
    NodesMap nodesMatch;
    string links;
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
void Stats_graph::Add(const Log &log)
{
    // If the taget doesn't already exist
    if (this->targets.count(log.url) == 0)
    {
        Referers refs;
        string referorUrl = getURLFromURI(log.referer);
        pair <string, int> refPair (referorUrl, 1);
        refs.referors.insert(refPair);
        refs.total = 1;
        pair <string, Referers> targetPair (log.url, refs);
        this->targets.insert(targetPair);
        int posTop10 = this->findPositionInTop10(log.url);
        if (posTop10 != -1) {
            this->insertInTop10(log.url, posTop10);
        }
    }
    else
    {
        string referorUrl = getURLFromURI(log.referer);
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
        this->updateTop10();
        int posTop10 = this->findPositionInTop10(log.url);
        if (posTop10 != -1) {
            this->insertInTop10(log.url, posTop10);
        }
    }
}

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
    this->top10Size = 0;
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

int Stats_graph::getTotal (const string & targetName) const {
    return this->targets.at(targetName).total;
}

// int Stats_graph::findPositionInTop10(const string & targetName) const {
//     if (this->top10Size == 0) return 0;
//     int targetTotal = this->getTotal(targetName);
//     int top10min = this->getTotal(this->top10[top10Size - 1]);
//     if (this->top10Size == NUMBER_OF_ELEMENTS_TOP && targetTotal <= top10min) return -1;
//     int iter =0;
//     for ( int lowerBound = 0, upperBound = this->top10Size -1, index = (lowerBound+upperBound+1)/2;; ) {
//         iter++;
//         int indexTotal = this->getTotal(this->top10[index]);
//         if (targetName == this->top10[index]) return -1;
//         if ( index == 0 && targetTotal > indexTotal ) return index;
//         else if (targetTotal <= indexTotal) return 1;
//         if ( index == NUMBER_OF_ELEMENTS_TOP - 1 && targetTotal > indexTotal) return index;
//         if ( index == this->top10Size - 1 && targetTotal < indexTotal) return this->top10Size;
//         if ( lowerBound == upperBound ) return lowerBound;
//         if ( targetTotal > indexTotal && targetTotal < this->getTotal(this->top10[index-1])) return index;
//         if ( targetTotal > indexTotal) 
//         {
//             upperBound = index;
//             index = (upperBound + lowerBound) / 2;
//         } else if (targetTotal < indexTotal)
//         {
//             lowerBound = index;
//             index = (upperBound + lowerBound + 1 ) / 2;
//         } else {
//             if (targetTotal<this->getTotal(this->top10[index-1])) return index;
//             if (index == 0) return index;
//             --index;
//         }
//     }
// }

int Stats_graph::findPositionInTop10(const string & targetName) const {
    if (this->top10Size == 0) return 0;
    int targetTotal = this->getTotal(targetName);
    int top10min = this->getTotal(this->top10[top10Size - 1]);
    if (this->top10Size == NUMBER_OF_ELEMENTS_TOP && targetTotal <= top10min) return -1;
    for ( int lowerBound = 0, upperBound = this->top10Size -1, index = (lowerBound+upperBound)/2;; ) {
        int indexTotal = this->getTotal(this->top10[index]);
        if (lowerBound == upperBound - 1) {
            if (targetName == this->top10[lowerBound]) return -1;
            return lowerBound;
        }
        if (targetTotal > indexTotal){
            upperBound = index;
            index = (upperBound + lowerBound)/2;
        } else if (targetTotal < indexTotal) {
            lowerBound = index;
            index =  (upperBound + lowerBound)/2;
        } else {
            for (int i = index; i>0 && this->getTotal(this->top10[i]) == targetTotal; i--) {
                if (this->top10[i] == targetName) return -1;
            }
            for (int i = index; i< this->top10Size && this->getTotal(this->top10[i]) == targetTotal; i++) {
                if (this->top10[i] == targetName) return -1;
            }
            return index;
        }
    }
}

void Stats_graph::insertInTop10(const string & targetName, int position) {
    if (position < 0 || position > NUMBER_OF_ELEMENTS_TOP - 1) return;
    if (this->top10Size < NUMBER_OF_ELEMENTS_TOP) {
        ++this->top10Size;
    }
    for (int i = top10Size - 1; i > position; --i) {
        this->top10[i] = this->top10[i - 1];
    }
    this->top10[position] = targetName;
}

void Stats_graph::updateTop10() {
    for (int i = this->top10Size - 2; i >= 0; i --) {
        int total = this->getTotal(this->top10[i]);
        int totalNext = this->getTotal(this->top10[i+1]);
        if (total < totalNext) {
            string temp = this->top10[i];
            this->top10[i] = this->top10[i+1];
            this->top10[i+1] = temp;
        }
    }
}

void Stats_graph::ShowTop10() const {
    cout << endl << "[" << endl;
    for (int i = 0; i < 10; i++) {
        if (top10[i] == "") break;
        cout << "\t" << top10[i] << " : " << this->getTotal(top10[i]) << endl;
    }
    cout << "]" << endl;
}