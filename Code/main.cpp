#include "main.h"
#include "StreamLog.h"
#include "Stats_graph.h"
#include <cstring>
#include <iostream>

const string EXTENSION_IMAGE_JPG = ".jpg";
const string EXTENSION_IMAGE_GIF = ".gif";
const string EXTENSION_IMAGE_PNG = ".png";
const string EXTENSION_IMAGE_PDF = ".pdf";
const string EXTENSION_CSS = ".css";
const string EXTENSION_JAVASCRIPT = ".js";


bool logFilter (const Log & aLog, const Filter & aFilter)
{
    bool returnFilter = true;


    if ( aFilter.hourFiltered )
    {
        long int filterHour = aFilter.hour;
        long int logTimeHour = aLog.requestTime.hour;
        if (!(logTimeHour == filterHour))
        {
            returnFilter = false;
            cerr << "L'heure du log n'est pas dand l'intervalle saisi" << endl;
        }
    }
    if ( aFilter.exclude )
    {
        if ((aLog.url.find(EXTENSION_CSS,0)!=string::npos)||(aLog.url.find(EXTENSION_JAVASCRIPT,0)!=string::npos)||
           (aLog.url.find(EXTENSION_IMAGE_GIF,0)!=string::npos)||(aLog.url.find(EXTENSION_IMAGE_JPG,0)!=string::npos)||
           (aLog.url.find(EXTENSION_IMAGE_PDF,0)!=string::npos)||(aLog.url.find(EXTENSION_IMAGE_PNG,0)!=string::npos))
        {
            returnFilter = false;
            cerr << "L'extension du log n'est pas prise en compte" << endl;
        }
    }

    return returnFilter;
}

int main ( int argc, char* argv[])
{
    StreamLog readStream;
    Stats_graph statsAndGraph;
    int i;
    //while (!readStream.eof)
    {
        for (i=1; i<argc ; ++i)
        {
            if (strcmp( argv[i], "-g") == 0)
            {
                //statsAndGraph.BuildGraph (argv[i+1]) où argv[i+1] = nomFichier.dot entré par l'utilisateur
            }
            if (strcmp( argv[i], "-e") == 0)
            {
                Filter excludeFilter (true,readStream.GetLog().requestTime.hour,false);
                if (logFilter(readStream.GetLog(),excludeFilter))
                {
                    //statsAndGraph.InsertLog(readStream.GetLog())
                }
            }
            if (strcmp( argv[i], "-t") == 0)
            {
                string arg(argv[i+1]);
                int hourLog = stoi(arg);

                Filter hourFilter (false,hourLog,true);
                if (logFilter(readStream.GetLog(),hourFilter))
                {
                    //statsAndGraph.InsertLog(readStream.GetLog())
                }
            }
        }
    }

}

