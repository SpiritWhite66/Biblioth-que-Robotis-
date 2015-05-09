#ifndef COMTXT_H
#define COMTXT_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

class comtxt
{
public:

    //Constructeurs
    comtxt();
    ~comtxt();
    void test(std::ifstream &open);
    void dntxt(std::ifstream &open);
    void rmtxt();
    void traitement();
    void convert();
    void serialDisplay();

private:

    int taille;
    int open;
    std::string dnx;
    std::string dny;
    int x;
    int y;
    bool middle = false;

    /****gestion moteur****/
    int moteur1 =0;
    int moteur2 =0;
    int moteur3 =1;
    int time_1;
    int time_2;
    int time_3;
    std::string time_1_s;
    std::string time_2_s;
    int count_time_1;
    int count_time_2;
    int count_i;
    int count_a;

};


#endif // COMTXT_H
