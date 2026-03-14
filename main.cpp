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
        // ===== Parámetros para cambiar de la simulación ===== //
        int limLlegadaCliente = 5; // cuantos "minutos"
        int velocidad = 500;

        // ==================================================== //
        int tiempoBancoAbierto = 200;
        int tiempoLlegadaCliente = (rand()%limLlegadaCliente) + 1;
        Banco bancoLCC; // cuantas cajas (default = 3)


        // Ciclo principal de la "simulacion"
        while(bancoLCC.ObtenerTiempoBanco()+1 <= tiempoBancoAbierto){
            LimpiarPantalla();
            cout << "Se atenderan tantas personas puedan en " << tiempoBancoAbierto << " minutos.\n";
            cout << "TIEMPO: " << bancoLCC.ObtenerTiempoBanco() << "\n\n";


            if(tiempoLlegadaCliente == 0){
                bancoLCC.LlegaCliente();
                tiempoLlegadaCliente = (rand()%limLlegadaCliente + 1);
            }
            bancoLCC.PasarTiempo();

            bancoLCC.ImprimirBanco(velocidad);


            --tiempoLlegadaCliente;
            bancoLCC.PasarCliente();

        }

        // Resumen de lo sucedido
        bancoLCC.ImprimirResumen();

    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(Cola<string>::ColaVacia &error){
        cerr << "Error: " << error.what();
    }
    return 0;
}
