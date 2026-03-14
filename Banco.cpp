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
        Sleep(ms);
    #else
        usleep(ms*1000);
        //porque por alguna razon linux los usa en MICROsegundos (?)
    #endif // _WIN32
}



// ===== CONSTRUCTORES ====== //

Banco::Banco(int n): tiempoBanco(0)
{
    try{
        this->num_cajas = n;
        this->enCaja = new Persona*[n];
        historialCajas = new Cola<Persona>[n];

        for(int i = 0; i < n; ++i){
            enCaja[i] = nullptr;
        }

    }catch(std::bad_alloc &){
        throw "No hay suficiente memoria";
    }
}

Banco::~Banco()
{
    delete[] historialCajas;
    for(int i = 0; i < num_cajas; ++i){
        delete enCaja[i];
    }
    delete []enCaja;
}

// ====== MÉTODOS DE LA CLASE ===== //
void Banco::LlegaCliente()
{
    Persona p("nombres.txt","apellidos.txt");
    enEspera.Agregar(p);
}

void Banco::PasarCliente()
{
    // Si no hay nadie esperando pues no hago nada.
    if(enEspera.EstaVacia()) return;
    // Pasar a una caja vacia.
    for(int i = 0; i < num_cajas; ++i){
        if(enCaja[i] == nullptr){
            Persona atendida = enEspera.ObtenerTope();
            historialCajas[i].Agregar(atendida);
            enEspera.Eliminar();
            enCaja[i] = new Persona(atendida);
            return;
        }
    }

}

void Banco::ImprimirBanco(int ms)
{
    //Por ahora, refrescaremos la pantalla. Se vera
    // un parpadeo muy feo, pero eso será antes de encontrar una buena solución
    // TODO: Borrar todo para evitar el parpadeo
    for(int i = 0; i < num_cajas; ++i){
        cout << "CAJA " << i+1 << ": ";
        if(enCaja[i] == nullptr){
            cout << "(desocupada)";
        }else{
            cout << *enCaja[i];
        }
        cout << "\n\n";
    }

    cout << "\n\nEn Espera:\n";
    enEspera.ImprimirLista();
    cout << "\n\n";
    Esperar(ms);
}

void Banco::PasarTiempo()
{
    ++tiempoBanco;

    // Actualizar tiempos de los atendidos
    for(int i = 0; i < num_cajas; ++i){
        // Actualizar tiempos de los atendidos
        if(enCaja[i] != nullptr){
            enCaja[i]->PasarTiempo();
        }
        // Si ya acabaron el "tramite", lo sacamos.
        if(enCaja[i] != nullptr && enCaja[i]->ObtenerTiempoEspera() == 0){
            delete enCaja[i];
            enCaja[i] = nullptr;
        }
    }

}

int Banco::ObtenerTiempoBanco()
{
    return tiempoBanco;
}

void Banco::ImprimirResumen()
{
    LimpiarPantalla();
    for(int i = 0; i < num_cajas; ++i){
        cout << "Atendidos por la caja " << i+1 << ": \n";
        historialCajas[i].ImprimirLista();
        cout << endl;
    }
    cout << "\n\nRestantes por atender:\n";
    if(enEspera.EstaVacia()) cout << "Nadie, todos fueron atendidos!\n\n";
    else enEspera.ImprimirLista();

}









