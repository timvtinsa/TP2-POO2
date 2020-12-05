#include "main.h"
#include "StreamLog.h"
#include "Stats_graph.h"
#include "Utils.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
#include <sstream>
#include <fstream>


const string EXTENSION_IMAGE_JPG = ".jpg";
const string EXTENSION_IMAGE_GIF = ".gif";
const string EXTENSION_IMAGE_PNG = ".png";
const string EXTENSION_IMAGE_PDF = ".pdf";
const string EXTENSION_CSS = ".css";
const string EXTENSION_JAVASCRIPT = ".js";
const string EXTENSION_GRAPH = ".dot";
const string EXTENSION_LOG = ".log";


bool logFilter (const Log & aLog, const Filter & aFilter)
{
    bool returnFilterHour = false;
    bool returnFilterExtension = false;

    if ( aFilter.hourFiltered )
    {
        int filterHour = aFilter.hour;
        int logTimeHour = aLog.requestDateTime.hour;
        if (logTimeHour != filterHour)
        {
            returnFilterHour = true;
            cerr << "L'heure du log n'est pas dans l'intervalle saisi" << endl;
        }
    }
    if ( aFilter.exclude )
    {
        if ((aLog.url.find(EXTENSION_CSS,0)!=string::npos)||(aLog.url.find(EXTENSION_JAVASCRIPT,0)!=string::npos)||
           (aLog.url.find(EXTENSION_IMAGE_GIF,0)!=string::npos)||(aLog.url.find(EXTENSION_IMAGE_JPG,0)!=string::npos)||
           (aLog.url.find(EXTENSION_IMAGE_PDF,0)!=string::npos)||(aLog.url.find(EXTENSION_IMAGE_PNG,0)!=string::npos))
        {
            returnFilterExtension = true;
            cerr << "L'extension du log n'est pas prise en compte" << endl;
        }
    }
    return returnFilterHour||returnFilterExtension;
}


int main ( int argc, char* argv[])
{
    string logFileName(argv[argc-1]);
    if (logFileName.find(EXTENSION_LOG,0)==string::npos)
    {
        cerr << "Erreur : Le nom de fichier de log saisi n'est pas correct" << endl;
        return 1;
    }
    else
    {
        if (!CheckFileExist(logFileName))
        {
            cerr << "Erreur : Le fichier de log en entrée n'existe pas." << endl;
            return 1;
        }

    }

    StreamLog readStream(logFileName);
    Stats_graph statsAndGraph;
    int i;
    bool hourFiltered = false;
    Time timetest (16,0,0);
    DateTime dt ("", 0, 0, 0);
    Log logLine ("","","",dt,"","test",200,0,"",""); // log de test
    bool extensionFiltered = false;
    int argHour2int=0;
    bool graphBuilt = false;
    string fileNameGraph;

    for (i=1; i<argc-1 ; ++i)
    {
        if (strcmp( argv[i], "-g") == 0)
        {
            if (argc >= i+2) // +2 et pas +1 car argv commence à 0
            {
                string fileNameGraphOption (argv[i+1]); //où argv[i+1] = nomFichier.dot entré par l'utilisateur
                if (fileNameGraphOption.find(EXTENSION_GRAPH,0)==string::npos)
                {
                    cerr << "Le nom de fichier saisi pour la génération du graphe n'est pas correcte" << endl;
                    // Le cas où il n'y a pas de nom de fichier après -g est aussi gérer
                    return 1;
                }
                else
                {
                    graphBuilt = true;
                    cout << "création du graph avec le nom : " << fileNameGraphOption << endl;
                    fileNameGraph = fileNameGraphOption;
                }
            }
            else
            {
                cerr << "Le nombre d'arguments saisi n'est pas correct" << endl;
                return 1;
            }
        }
        if (strcmp( argv[i], "-e") == 0)
        {
            extensionFiltered = true;
        }
        if (strcmp( argv[i], "-t") == 0)
        {
            if (argc >= i+2) // +2 et pas +1 car argv commence à 0
            {
                string argHour(argv[i+1]); //où argv[i+1] = nomFichier.dot entré par l'utilisateur
                stringstream ss;
                ss << argHour;
                ss >> argHour2int;
                if (!(ss.fail()))
                {
                    if ((argHour2int > 23)||(argHour2int < 0))
                    {
                        cerr << "L'argument saisi pour le filtre par heure n'est pas une heure (0 à 23)" << endl;
                        return 1;
                    }
                    else
                    {
                        hourFiltered = true;
                    }
                }
                else
                {
                    cerr << "L'argument saisi pour le filtre par heure n'est pas un entier" << endl;
                    return 1;
                }
            }
            else
            {
                cerr << "Le nombre d'arguments saisi n'est pas correct" << endl;
                return 1;
            }
        }
    }
    // string inputFileName (argv[argc - 1]);
    // readFile(inputFileName);


    /*while (!readStream.eof())
    {
        Filter optionsFilter (extensionFiltered,argHour2int,hourFiltered);
        Log * logLine = readStream.GetLog();
        if (logLine != NULL && !(logFilter(*logLine,optionsFilter)))
        {
            //statsAndGraph.InsertLog(readStream.GetLog())
            cout << *logLine;
            statsAndGraph.Add(*logLine);
            cout << "log insérer dans stats graph" << endl;
        }
        if (logLine != NULL) {
            delete logLine;
        }
    }*/

    if (graphBuilt)
    {
        statsAndGraph.BuildGraphFile (fileNameGraph);
        cout << "contruction du graphe" << endl;
    }
    return 0;

}

/*
void readFile (string fileName) {
    StreamLog readStream (fileName);
    while (!readStream.eof()) {
        Log * log = readStream.GetLog();
        if (! log) continue;
        cout << *log << endl;
    }
}*/