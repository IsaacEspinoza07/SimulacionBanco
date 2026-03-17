/**
* \file Persona.hpp
* Este archivo contiene funciones y par&aacute;metros de la clase 'Persona'
* \authors
    David Armando Angulo Gil
    Isaac Espinoza Hern&aacute;ndez
* \date 16/03/2026
* \code {.cpp}
int main()
{
    Persona p("nombres.txt","apellidos.txt");

    cout << "Nombre de la persona que llego: " << p << endl;
    cout << "Tiempo que tendr\240 que esperar la persona: " << p.ObtenerTiempoEspera() << endl;
    while(p.ObtenerTiempoEspera() != 0){
        p.PasarTiempo();
    }

    return 0;
}
* \endcode
*/
#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <iostream>
#include <exception>
#include <string>
#include <vector>
using std::ostream, std::string, std::vector;

/**
 * Clase para poder "crear" personas, informaci&oacute; como nombre y apellido y el tiempo de espera.
 */
class Persona{
    // Cout para poder imprimirlo desde la cola
    /** \brief Operador amigo para la impresi&oacute;n de par&aacute;metros de la clase 'Persona' mediante funciones como 'cout'
     *
     * \param salida Par&aacute;metro perteneciente a la clase ostream
     * \param p Persona a imprimir
     * \return Elementos a imprimir
     *
     */
    friend ostream &operator<<(ostream &salida, const Persona &p);

public:
    /** \brief Constructor por Default para la clase 'Persona'.
     *
     * \param nombres Nombre que tendr&aacute; la persona
     * \param apellidos Apellido que tendr&aacute; la persona
     *
     */
    Persona(const string &nombres, const string &apellidos);
    /** \brief Constructor de Copias para la clase 'Persona'
     *
     * \param p Persona a copiar
     *
     */
    Persona(const Persona &p); // constructor de copias
    /** \brief Sobrecarga del operador de asignaci&oacute;n de la clase 'Persona'
     *
     * \param p Persona a copiar
     * \return La informaci&oacute;n de la persona copiada
     *
     */
    Persona &operator=(const Persona &p); // op =

    /** \brief M&eacute;todo que carga el nombre o el apellido de la persona desde un archivo txt
     *
     * \param texto Nombre del archivo
     * \return Nombre o apellido de la persona
     *
     * \warning ADVERTENCIA: Es posible que el archivo de nombres o de apellidos no llegue a abrir, a lo cual se tirara un error.
     * \throw ERROR: ArchivoCerrado, el archivo no se pudo abrir, a lo que se tira este error.
     */
    vector<string> CargarTextos(const string &texto);
    /** \brief M&eacute;todo que transforma el ascii en los archivos de texto a caracteres especiales, usado para los acentos y la &ntilde;.
     *
     * \param texto Texto a transformar.
     * \return El texto si no hay nada por transformar o el car&aacute;cter especial en caso de que se encuentre un ascii.
     *
     * \see CargarTextos
     */
    string ProcesoCaracteresEsp(const string &texto);

    /** \brief M&eacute;todo que regresa el tiempo de espera de la persona.
     *
     * \return El tiempo de espera.
     *
     */
    int ObtenerTiempoEspera();
    /** \brief Reduce el tiempo de espera de la persona.
     *
     * \return Nada
     *
     */
    void PasarTiempo();
    /**
    * Subclase para las excepciones que tratan los problemas con m&eacute;todos que necesitan abrir archivos.
    */
    class ArchivoCerrado : public std::exception
        {
          public:
            /** \brief Constructor por default de la subclase 'ArchivoCerrado'.
             *
             */
            ArchivoCerrado() noexcept;
            /** \brief M&eacute;todo que extiende la funci&oacute;n de la clase 'exception' de la librer&iacute;a del mismo nombre.
             *
             * \return El mensaje de error lanzado.
             *
             * \see [exception::what()](https://cplusplus.com/reference/exception/exception/what/)
             */
            virtual const char *what() const noexcept;
          private:
            const char *mensaje;
        };
private:
    int tiempoEspera;
    /** \brief Genera el tiempo de espera.
     *
     * \param tiempoMax Tiempo m&aacute;ximo que puede tardar el banco en atender a una persona.
     * \return Tiempo de espera.
     *
     */
    int GenerarTiempo(int tiempoMax);
    string nombre;
};

#endif // PERSONA_HPP_INCLUDED
