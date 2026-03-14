#include "Persona.hpp"
#include <fstream>
#include <cstdlib>

// Constructor por default


int Persona::GenerarTiempo(int tiempoMax)
{
    // de 1 a lo que se introduzca (15 esta decente)
    return rand() % tiempoMax +1;
}

Persona::Persona(const Persona &p)
{
    *this = p;
}

Persona &Persona::operator=(const Persona &p)
{
    if (this == &p) return *this;

    this->nombre = p.nombre;
    this->tiempoEspera = p.tiempoEspera;

    return *this;
}

// Vector porque sino esta dificil moverme sobre el pa agarrar uno aleatorio.
vector<string> Persona::CargarTextos(const string &texto)
{
    std::ifstream archivo(texto);
    vector<string> lineas; // lo que se leera (apellidos o nombres en este caso)
    string linea_individual;//una unica linea del .txt

    while(getline(archivo,linea_individual)){
        lineas.push_back(linea_individual);
    }

    return lineas;
}

int Persona::ObtenerTiempoEspera()
{
    return tiempoEspera;
}
void Persona::PasarTiempo()
{
    --tiempoEspera;
}


// =======================0 //
Persona::Persona(const string &nombres, const string &apellidos): tiempoEspera(GenerarTiempo(25))
{
    vector<string> nom = CargarTextos(nombres);
    vector<string> ap = CargarTextos(apellidos);

    // Esto los junta y separa y lo guarda en la instancia
    this->nombre = nom[rand()%nom.size()] + " " + ap[rand()%ap.size()];
}


// Sobrecarga del <<
ostream &operator<<(ostream &salida, const Persona &p)
{
    salida << p.nombre;
    return salida;
}
