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
        int limLlegadaCliente = 5; // cuantos "minutos" tarda en llegar
        int velocidad = 500;
        int numCajas = 3;

        // ==================================================== //
        int tiempoBancoAbierto = 200;
        int tiempoLlegadaCliente = (rand()%limLlegadaCliente) + 1;
        Banco bancoLCC/*(numCajas)*/; // cuantas cajas (default = 3)

        //Menú para antes de la simulacion ===============
        cout << "=== SIMULACI\340N DE BANCO ===\n\n";
        cout << "-Duracion de la simulacion: " << tiempoBancoAbierto << " \"minutos\".\n";
        cout << "-Cada cuanto puede llegar un cliente: " << limLlegadaCliente << " \"minutos\".\n";
        cout << "-Velocidad de refresco: " << velocidad << " ms.\n";
        cout << "-N\243mero de cajas: " << numCajas << " cajas.\n\n";

        Pausar();

        // ===================== Fin del menú.


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
    }catch(exception &error){
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }
    return 0;
}
