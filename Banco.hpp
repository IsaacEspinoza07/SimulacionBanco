/**
* \file Banco.hpp
* Este archivo contiene funciones y par&aacute;metros de la clase 'Banco'
* \authors
    David Armando Angulo Gil
    Isaac Espinoza Hern&aacute;ndez
* \date 16/03/2026
* \code {.cpp}
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
    }catch(exception &error){
        cerr << "Error: " << error.what();
    }catch(...){
        cerr << "El programa tuvo un error inesperado." << endl;
    }
    return 0;
}
* \endcode
*/
#ifndef BANCO_HPP_INCLUDED
#define BANCO_HPP_INCLUDED

#include "Cola.hpp"
#include "Persona.hpp"

class Banco{
public:
    /** \brief Constructor por default de la clase 'Banco'
     *
     * \param n N&uacute;mero de cajas en el banco, 3 cajas por defecto
     *
     * \warning ADVERTENCIA: El constructor crea objetos con memoria din&aacute;mica, por lo cual puede tirar un error.
     * \throw ERROR: std::bad_alloc, error lanzado por la falta de memoria en el sistema, a lo cual el programa ya no puede crear nuevos elementos.
     */
    Banco(int n = 3);
    /** \brief Destructor de la clase 'Banco'
     *
     *
     */
    ~Banco(); // pues se usa memoria dinámica

    /** \brief M&eacute;todo que imprime el banco, lo que consiste en las cajas y la lista de personas en espera
     *
     * \param ms Que tanto milisegundos tienen que pasar para que se imprima de vuelta, por defecto 300 milisegundos
     * \return Nada
     *
     */
    void ImprimirBanco(int ms = 300);
    /** \brief M&eacute;todo que, al terminar la simulaci&oacute;n imprime las personas que fueron atendidas en cada caja y las personas no atendidas.
     *
     * \return Nada
     *
     */
    void ImprimirResumen();
    /** \brief M&eacute;todo que agrega una persona a la cola de espera.
     *
     * \return Nada
     *
     */
    void LlegaCliente();
    /** \brief Pasa el tiempo del banco en un minuto, tambi&eacute;n cambiando el tiempo de atenci&oacute;n de la persona.
     *
     * \return Nada
     *
     */
    void PasarTiempo();
    /** \brief M&eacute;todo que devuelve el tiempo que ha pasado atendiendo el banco.
     *
     * \return Tiempo que ha pasado.
     *
     */
    int ObtenerTiempoBanco();
    /** \brief M&eacute;todo que pasa a un cliente a alguna caja vac&iacute;a
     *
     * \return Nada
     *
     *
     * \warning ADVERTENCIA: El m&eacute;todo crea objetos con memoria din&aacute;mica, por lo cual puede tirar un error.
     * \throw ERROR: std::bad_alloc, error lanzado por la falta de memoria en el sistema, a lo cual el programa ya no puede crear nuevos elementos.
     */
    void PasarCliente();

private:
    int num_cajas; // pa generalizar chilo, por eso son punteros los otros. 3 porque así se pide.
    Persona **enCaja;
    Cola<Persona> enEspera;
    Cola<Persona> *historialCajas;
    int tiempoBanco;

};


// ======= útilidades ======== //
/** \brief Funci&oacute;n que duerme la consola un tiempo en milisegundos, cambiando de funci&oacute;n para dormir dependiendo si es Windows o Linux.
 *
 * \param ms Tiempo que pasar&aacute; dormida la consola
 * \return Nada
 *
 */
void Esperar(int ms);
/** \brief Funci&oacute;n que limpia la pantalla de la consola.
 *
 * \return Nada
 *
 */
void LimpiarPantalla();

/** \brief Pausa la ejecuci&oacute;n del programa hasta que se presione una tecla
 *
 * \return Nada
 *
 */
void Pausar();

#endif // BANCO_HPP_INCLUDED
