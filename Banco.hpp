#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "Cola.hpp"
#include "Persona.hpp"

class Banco{
public:
    Banco(int n = 3);
    ~Banco(); // pues se usa memoria dinámica

    void ImprimirBanco(int ms = 300);
    void ImprimirResumen();
    void LlegaCliente();
    void PasarTiempo();
    int ObtenerTiempoBanco();
    void PasarCliente();

private:
    int num_cajas; // pa generalizar chilo, por eso son punteros los otros. 3 porque así se pide.
    Persona **enCaja;
    Cola<Persona> enEspera;
    Cola<Persona> *historialCajas;
    int tiempoBanco;

};


// ======= útilidades ======== //
void Esperar(int ms);
void LimpiarPantalla();

#endif // BANCO_HPP_INCLUDED
