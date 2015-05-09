#include "comtxt.h"
#include <fstream>
#include <iostream>
#include <sstream>

comtxt::comtxt()
{
    //ctor
}

comtxt::~comtxt()
{
}
void comtxt::test(std::ifstream& open)
{
if(open){
    /**** Boucle de test ****/
open.seekg(0, std::ios::end);  //On se déplace à la fin du fichier
taille = open.tellg();
if(taille < 1)
{
    std::cout <<"Fichier vide";
}
else
{
  comtxt::dntxt(open);
  comtxt::convert();
  comtxt::traitement();
  comtxt::serialDisplay();
}
}
}

void comtxt::dntxt(std::ifstream& open)
{
        open.seekg(0, std::ios::beg);
         getline(open, dnx);
         getline(open, dny);
}

void comtxt::rmtxt()
{

    std::ofstream write("C:/Users/vincent/Desktop/tpe.txt");
     if(write){
            write << "";
            write.close();
            }
            else {

            }
}
void comtxt::convert()
{

    std::istringstream convertx(dnx);
    convertx >> x;
    std::istringstream converty(dny);
    converty >> y;
}
void comtxt::traitement()
{
  if(y == 1){moteur1 = 0;} else{moteur1 = 1; time_1 = 18*y+9;}
  if(x == 1){moteur2 = 0;} else{moteur2 = 1; time_2 = 18*x+9;}
  count_time_1 = time_1;
  count_time_2 = time_2;

  std::stringstream out;
  out << time_1;
  time_1_s = out.str();
  std::stringstream out2;
  out2 << time_2;
  time_2_s = out.str();

for(int i =1; count_time_1 > 1; i++)
{
   count_time_1 = count_time_1/10;
   count_i = i;
}
if(count_i == 1){time_1_s="0000"+time_1_s;}
if(count_i == 2){time_1_s="000"+time_1_s;}
if(count_i == 3){time_1_s="00"+time_1_s;}
if(count_i == 4){time_1_s="0"+time_1_s;}

for(int a =1peut etre; count_time_2 > 1; a++)
{
   count_time_2 = count_time_2/10;
   count_a = a;
}
if(count_a == 1){time_2_s="0000"+time_2_s;}
if(count_a == 2){time_2_s="000"+time_2_s;}
if(count_a == 3){time_2_s="00"+time_2_s;}
if(count_a == 4){time_2_s="0"+time_2_s;}
}

void comtxt::serialDisplay()
{
   std::cout << moteur1 << moteur2 <<moteur3 <<" "<<time_1_s<<" "<<time_2_s;
}

