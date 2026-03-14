#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using std::ostream, std::string, std::vector;

class Persona{
    // Cout para poder imprimirlo desde la cola
    friend ostream &operator<<(ostream &salida, const Persona &p);

public:
    Persona(const string &nombres, const string &apellidos);
    Persona(const Persona &p); // constructor de copias
    Persona &operator=(const Persona &p); // op =

    vector<string> CargarTextos(const string &texto);
    int ObtenerTiempoEspera();
    void PasarTiempo();

private:
    int tiempoEspera;
    int GenerarTiempo(int tiempoMax);
    string nombre;
};

#endif // PERSONA_HPP_INCLUDED
