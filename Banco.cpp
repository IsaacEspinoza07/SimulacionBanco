#include "Banco.hpp"
#include <cstdlib>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

// ====== ÚTILIDADES ====== //
void LimpiarPantalla()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32

}

void Esperar(int ms)
{
    #ifdef _WIN32
        sleep(ms);
    #else
        usleep(ms*1000);
        //porque por alguna razon los usa en MICROsegundos (?)
    #endif // _WIN32
}



// ===== CONSTRUCTORES ====== //

Banco::Banco(int n)
{
    try{
        this->num_cajas = n;
        cajas = new Cola<Persona>[n];
        historialCajas = new Cola<Persona>[n];


    }catch(std::bad_alloc &){
        throw "No hay suficiente memoria";
    }
}

Banco::~Banco()
{
    delete[] cajas;
    delete[] historialCajas;
}


// ====== MÉTODOS DE LA CLASE ===== //
void Banco::llegaCliente()
{
    int eleccionCaja = rand() % 3;
    Persona p("nombres.txt","apellidos.txt");
    cajas[eleccionCaja].Agregar(p);
}


void Banco::ImprimirBanco()
{
    LimpiarPantalla();
    //Por ahora, refrescaremos la pantalla. Se vera
    // un parpadeo muy feo, pero eso será antes de encontrar una buena solución
    // TODO: Borrar todo para evitar el parpadeo
    for(int i = 0; i < num_cajas; ++i){
        cout << "CAJA " << i+1 << ": "; cajas[i].Imprimir(); cout << "\n\n";
    }
    Esperar(500);

}
