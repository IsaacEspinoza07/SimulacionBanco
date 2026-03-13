#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "Cola.hpp"
#include "Persona.hpp"

class Banco{
public:
    Banco(int n = 3);
    ~Banco(); // pues se usa memoria dinámica

    void ImprimirBanco();
    void llegaCliente();

private:
    int num_cajas; // pa generalizar chilo, por eso son punteros los otros. 3 porque así se pide.
    Cola<Persona> *cajas;
    Cola<Persona> *historialCajas;
    int capacidadCaja; // generalmente, unas 10 personas esta bien por caja.
    int TiempoBanco;

};


#endif // BANCO_HPP_INCLUDED
