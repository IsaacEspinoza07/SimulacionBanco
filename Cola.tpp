#include "Cola.hpp"
#include <exception>
#include <iostream>

using std::cout, std::endl;
/* ========= CONSTRUCTORES ========= */

// Constructor común y corriente
template<typename T>
Cola<T>::Cola(): num_elem(0), cola(nullptr) {}

// Constructor de copias
template<typename T>
Cola<T>::Cola(const Cola &c): num_elem(0), cola(nullptr)
{
    *this = c;
}

// Destructor
template<typename T>
Cola<T>::~Cola(){
    Vaciar();
}
// Operador =
template<typename T>
Cola<T> &Cola<T>::operator=(const Cola<T> &c)
{
    if(this == &c) return *this;

    Vaciar();

    Cola colaAux;
    Elemento *visitado = c.cola->siguiente;
    for(int i = 0; i < c.num_elem; ++i){
        this->Agregar(visitado->valor);
        visitado = visitado->siguiente;
    }

    return *this;
}

// Constuctor de los elementos
template<typename T>
Cola<T>::Elemento::Elemento(T n, Elemento *sig /*=nullptr*/): valor(n), siguiente(sig) {}



/* ========= MÉTODOS ========= */
template<typename T>
void Cola<T>::Agregar(T n)
{
    // Usaremos memoria dinámica, entonces tener cuidado
    try{
        // Si es el primer elemento, tanto la cola como la parte de enfrente le
        // deberian apuntar a el
        Elemento *nuevo = new Elemento(n);
        nuevo->siguiente = (EstaVacia()) ? nuevo : cola->siguiente;
        if( !EstaVacia() ) cola->siguiente = nuevo;
        cola = nuevo;


        // === Esto de aqui, es lo mismo, pero más explicito. Ambas son buenas. ===
        /*
        if(num_elem == 0){
            Elemento *nuevo = new Elemento(n);
        // Si se le asigna de una: Elemento(n,nuevo), truena, porque aún
        // no se define el valor de "Elemento *nuevo", pues apenas se esta creando
            nuevo->siguiente = nuevo;
            cola = nuevo;

        }
        else{
            Elemento *nuevo = new Elemento(n,cola->siguiente);
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        */

        ++num_elem;
    }catch(std::bad_alloc &){
        throw "Se acabo la memoria";
    }
}
/* ======================================= */
template<typename T>
void Cola<T>::Eliminar(){
    if( EstaVacia() ) throw ColaVacia();

    if(num_elem == 1){
        delete cola;
        cola = nullptr;

    }
    else{
        Elemento *aux = cola->siguiente;
        cola->siguiente = aux->siguiente;
        delete aux;
    }

    --num_elem;
}
/* ======================================= */
template<typename T>
T Cola<T>::ObtenerCola() const{
    return this->cola->valor;
}
/* ======================================= */
template<typename T>
T Cola<T>::ObtenerTope() const{
    return this->cola->siguiente->valor;
}
/* ======================================= */
template<typename T>
bool Cola<T>::EstaVacia() const
{
    return (cola == nullptr);
}
/* ======================================= */
template<typename T>
void Cola<T>::Vaciar(){

    while( !EstaVacia() ) Eliminar();
}
/* ======================================= */
template<typename T>
void Cola<T>::Imprimir() const
{
    if( EstaVacia() ){
        cout << "Tope-> ";
        return;
    }
    Elemento *explorador = cola->siguiente;

    cout << "Tope-> ";
    for(int i = 0; i < num_elem; ++i){
        cout << explorador->valor << ", ";
        explorador = explorador->siguiente;
    }
    cout << "\b\b ";

}

// ===== EXCEPCIÓN DE LA CLASE ===== //

template<typename T>
Cola<T>::ColaVacia::ColaVacia() noexcept {}

template<typename T>
const char *Cola<T>::ColaVacia::what() const noexcept
{
    return "La cola se encuentra vac\241a\n";
}

