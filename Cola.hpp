#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

template<typename T>
class Cola
{
    public:

        // ====== CONSTRUCTORES ====== //
        Cola(); // Por default
        ~Cola(); // Destructor
        Cola(const Cola &c);// Aqui ira el de Copias
        Cola &operator=(const Cola &c); //op =

        // ====== MÉTODOS ====== //
        void Agregar(T n);
        void Eliminar();
        T ObtenerCola() const;
        T ObtenerTope() const;
        int ObtenerTam() const;
        bool EstaVacia() const;
        void Vaciar();
        void Imprimir() const; // pa pruebas nomas.

        // === EXCEPCION DE LA CLASE === //
        class ColaVacia : public std::exception
        {
          public:
            ColaVacia() noexcept;
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
