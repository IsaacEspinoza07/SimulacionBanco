#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Cola.hpp"
#include "Persona.hpp"
#include "Banco.hpp"

using namespace std;

int main()
{
    srand(time(nullptr));
    try{
        Banco bancoLCC;
        for(int i = 0; i < 10; ++i){
            bancoLCC.ImprimirBanco();
            bancoLCC.llegaCliente();
        }

    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(Cola<string>::ColaVacia &error){
        cerr << "Error: " << error.what();
    }
    return 0;
}
