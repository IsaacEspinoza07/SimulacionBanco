#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Cola.hpp"
#include "Persona.hpp"

using namespace std;

int main()
{
    srand(time(nullptr));
    try{
        Persona p("nombres.txt","apellidos.txt");
        cout << p;
        p.Ot();


    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(Cola<string>::ColaVacia &error){
        cerr << "Error: " << error.what();
    }
    return 0;
}
