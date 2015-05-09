#include <iostream>
#include <fstream>
#include <string>
#include "comtxt.h"
using namespace std;

int main()
{
    /****Boucle d'écriture****/
    ifstream open("C:/Users/vincent/Desktop/tpe.txt");
comtxt commu;
commu.test(open);
}
