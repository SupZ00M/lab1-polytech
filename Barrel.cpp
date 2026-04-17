#include <iostream>
#include <cstdlib> 
#include "Barrel.hpp"
using namespace std;

Barrel::Barrel (double Alch, double Wat){
alch = Alch;
wat = Wat;
}

void Barrel::from_barrel(double volume, Barrel& barrel){
    alch += volume*barrel.alch/(barrel.alch + barrel.wat);
    wat += volume*barrel.wat/(barrel.alch + barrel.wat);
    barrel.alch -=volume*barrel.alch/(barrel.alch + barrel.wat);
    barrel.wat -=volume*barrel.wat/(barrel.alch + barrel.wat);
}

double  Barrel::alch_prop(){
    return alch/(alch + wat);



}

