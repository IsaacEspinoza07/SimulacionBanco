#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Cola.hpp"

using namespace std;

int main()
{
    try{

        Cola<string> c;
        c.Agregar("Hola");
        c.Agregar(" Mundo!");

        c.Imprimir();

    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(Cola<string>::ColaVacia &error){
        cerr << "Error: " << error.what();
    }
    return 0;
}
