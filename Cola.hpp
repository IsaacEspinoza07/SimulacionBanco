/**
* \file Cola.hpp
* Este archivo contiene funciones y par&aacute;metros de la clase 'Cola'
* \authors
    David Armando Angulo Gil
    Isaac Espinoza Hern&aacute;ndez
* \date 16/03/2026
* \code {.cpp}
int main()
{
    Cola<int> c;

    c.Agregar(2);
    c.Agregar(-3);

    cout << "La cola al inicio (imprimiendo mediante Imprimir()): " << endl;
    c.Imprimir();

    cout << "\nEl valor que se encuentra en la cola de c es " << c.ObtenerCola() << endl;
    cout << "El valor que se encuentra en el tope de c es " << c.ObtenerTope() << endl;

    Cola<int> c2;
    c2 = c;

    cout << "La segunda cola al inicio (imprimiendo mediante Imprimir()): " << endl;
    c2.Imprimir();

    c.Eliminar();

    cout << "El n\242mero de elementos de c es " << c.ObtenerTam << endl;

    if(!EstaVacia()) c.Eliminar();

    cout << "La cola al final (imprimiendo mediante ImprimirLista())" << endl;
    c.ImprimirLista();

    cout << "La segunda cola al final (imprimiendo mediante ImprimirLista())" << endl;
    c2.ImprimirLista();

    return 0;
}
* \endcode
*/
#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include <exception>

template<typename T>
/**
 * Clase de Cola, aplicando la metodolog&iacute;a de una Cola circular.
 */
class Cola
{
    public:

        // ====== CONSTRUCTORES ====== //
        /** \brief Constructor por default de la clase 'Cola'.
         */
        Cola(); // Por default
        /** \brief Destructor de la clase 'Cola'
         */
        ~Cola(); // Destructor
        /** \brief Constructor de copias de la clase 'Cola'
         *
         * \param c Cola a copiar
         *
         */
        Cola(const Cola &c);// Aqui ira el de Copias
        /** \brief Operaci&oacute;n de asignaci&oacute;n de la clase 'Cola'.
         *
         * \param c Cola a copiar
         * \return Cola copiada
         *
         */
        Cola &operator=(const Cola &c); //op =

        // ====== MÉTODOS ====== //
        /** \brief M&eacute;todo para agregar un elemento a la cola elegida por el usuario.
         *
         * \tparam T Par&aacute;metro elegido por el usuario para la cola
         * \param n Valor a agregar
         * \return Nada
         *
         * \warning ADVERTENCIA: Por la naturaleza del m&eacute;todo de crear nuevos elementos con memoria din&aacute;mica, puede lanzar un error.
         * \throw ERROR: std::bad_alloc, error lanzado por la falta de memoria en el sistema, a lo cual el programa ya no puede crear nuevos elementos.
         */
        void Agregar(T n);
        /** \brief M&eacute;todo para eliminar el elemento en el frente de la cola.
         *
         * \return Nada
         *
         * \pre RECOMENDACI&Oacute;N: La cola debe tener alg&uacute;n elemento previo al usar la funci&oacute;n
         * \warning ADVERTENCIA: Si es que la cola esta vac&iacute;a, el programa no podr&aacute; ning&uacute;n elemento, a lo cual tirar&aacute; un error.
         * \throw ERROR: ColaVacia, error lanzado por el intento de hacer una operaci&oacute;n que ocupe que la cola tenga un elemento o mas, sin embargo, est&eacute; vac&iacute;a.
         */
        void Eliminar();
        /** \brief M&eacute;todo para obtener el valor que se encuentra al final de la cola.
         *
         * \tparam T Par&aacute;metro elegido por el usuario para la cola
         * \return Valor encontrado en el final de la cola
         *
         */
        T ObtenerCola() const;
        /** \brief M&eacute;todo para obtener el valor que se encuentra al frente de la cola.
         *
         * \tparam T Par&aacute;metro elegido por el usuario para la cola
         * \return Valor encontrado en el frente de la cola
         *
         */
        T ObtenerTope() const;
        /** \brief M&eacute;todo para obtener el n&uacute;mero de elementos en la cola.
         *
         * \return N&uacute;mero de elementos de la cola
         *
         */
        int ObtenerTam() const;
        /** \brief M&eacute;todo que avisa si la cola se encuentra vac&iacute;a.
         *
         * \return Estado de la cola, si se encuentra vac&iacute;a o no
         *
         */
        bool EstaVacia() const;
        /** \brief M&eacute;todo que vac&iacute;a la cola por completo.
         *
         * \return Nada
         *
         * \pre \pre RECOMENDACI&Oacute;N: La cola debe tener alg&uacute;n elemento previo al usar la funci&oacute;n
         * \warning ADVERTENCIA: Si es que la cola esta vac&iacute;a, el programa no podr&aacute; ning&uacute;n elemento, a lo cual tirar&aacute; un error.
         * \throw ERROR: ColaVacia, error lanzado por el intento de hacer una operaci&oacute;n que ocupe que la cola tenga un elemento o mas, sin embargo, est&eacute; vac&iacute;a.
         * \see El m&eacute;todo de 'Eliminar'.
         */
        void Vaciar();
        /** \brief M&eacute;todo que imprime la cola, se&ntilde;ala el tope de la cola, incluso si est&aacute; vac&iacute;a.
         *
         * \return Nada
         *
         */
        void Imprimir() const; // pa pruebas nomas.
        /** \brief M&eacute;todo que imprime la cola.
         *
         * \return Nada
         *
         */
        void ImprimirLista() const;

        // === EXCEPCION DE LA CLASE === //
        /**
         * Subclase para las excepciones que tratan los problemas con m&eacute;todos que no pueden ejecutarse si la cola est&aacute; vac&iacute;a.
         */
        class ColaVacia : public std::exception
        {
          public:
            /** \brief Constructor por default de la subclase 'ColaVacia'
             *
             */
            ColaVacia() noexcept;
            /** \brief M&eacute;todo que extiende la funci&oacute;n de la clase 'exception' de la librer&iacute;a del mismo nombre.
             *
             * \return El mensaje de error lanzado
             *
             * \see [exception::what()](https://cplusplus.com/reference/exception/exception/what/)
             */
            virtual const char *what() const noexcept;
          private:
            const char *mensaje;
        };


    private:
        int num_elem;

        // ====== ELEMENTOS DE LA COLA ====== //
        struct Elemento{
            T valor;

            Elemento *siguiente;
            Elemento(T valor,Elemento *sig=nullptr); // Constructor de Elemento
        }*cola;




};


#include "Cola.tpp"

#endif // COLA_HPP_INCLUDED
