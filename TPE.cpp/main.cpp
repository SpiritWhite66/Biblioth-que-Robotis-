#include <iostream>
#include <fstream>
#include <string>
#include "comtxt.h"
using namespace std;

int main()
{
    /****Boucle d'�criture****/
    ifstream open("C:/Users/vincent/Desktop/tpe.txt");
comtxt commu;
commu.test(open);
}
