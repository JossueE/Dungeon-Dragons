#ifndef NODOS_H
#define NODOS_H
#include <iostream>
using namespace std;

template <typename T>
class NodoLista{
    public:
        T info;
        NodoLista<T> *next;
        NodoLista<T> *prev;

        NodoLista(T dato) : info(dato), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Lista{
    private:
        NodoLista<T> *head;
        NodoLista<T> *tail;
        int size;

    public:
        Lista(){
            head = nullptr;
            tail = nullptr;
            size = 0;   
        }

        ~Lista(){
            borrar();
        };

        bool InsertarNodo(T dato){
            NodoLista<T> *NuevoNodo = nullptr;
            NuevoNodo = new NodoLista<T>(dato);

            if (!NuevoNodo)// if(NuevoNodo == nullptr)
            {
                return false;
            }
                
            if(head){
                head -> prev = NuevoNodo;
            }
            NuevoNodo -> next = head;
            head = NuevoNodo;
            size++;
            return true;
        }

        int Size (){
            return size;
        }

        bool InsertarTail(T dato){
            NodoLista<T> *NuevoNodo = new NodoLista<T>(dato);
            if(head == nullptr){
                head = NuevoNodo;
                head -> next = nullptr;
                head -> prev = nullptr;
                size++;
                return true;
            }

            NodoLista<T> *actual = head;
            while(actual -> next != nullptr){
                actual = actual -> next;
            }

            actual -> next = NuevoNodo;
            actual -> prev = actual;
            NuevoNodo -> next = nullptr;
            size++;
            return true;
        }

        void imprimir (){
            NodoLista<T> *actual = head;

            while(actual != nullptr){
                cout << actual -> info << " ";
                actual = actual -> next;
            }
            cout << endl;
        }

        NodoLista<T>* GetNodoEnPos(unsigned int posicion) {
            // Verifica si la posición está dentro de los límites de la lista
            if (posicion < 0 || posicion >= Size()) {
                return nullptr; // Posición fuera de rango
            }   

            NodoLista<T>* nodoActual = head;
            int indice = 0;

            // Avanzar a través de la lista hasta llegar a la posición deseada
            while (nodoActual && indice < posicion) {
                nodoActual = nodoActual->next;
                indice++;
            }

            return nodoActual;
        }

        NodoLista<T>* buscar(T dato){
            NodoLista<T> *actual = head;

            while (actual != nullptr){
                if (dato == actual -> info){
                    return actual;
                    }
                actual = actual -> next;
                
            }
            return nullptr;
        }

        NodoLista<T>* GetHead() const {
            if(head == nullptr){
                return nullptr;
            }
            else{
                return head;
            }
        }

        bool eliminar (T dato){
            /*
            *
            * Descripción: Busca un dato puntual y lo elimina.
            * Entrada:  El dato a buscar
            * Salida: bool
            * Precondición: La lista no debe estar vacía.
            * Postcondición: Se actualizan los valores de memoria
            * Complejidad: O(n)
            *
            */
            NodoLista<T> *actual = nullptr;

            actual = head;
            while(actual && actual->info != dato)
                actual = actual->next;

            if(!actual)
                return false;

            if(actual->prev)
                actual->prev->next = actual->next;
            if(actual->next)
                actual->next->prev = actual->prev;

            if(actual == head)
                head = actual->next;

            delete actual;
            size --;
            return true;

            
        }

        bool eliminarhead(){
            /*
            *
            * Descripción: Elimina el primer dato del arreglo.
            * Entrada:  Ninguna
            * Salida: bool
            * Precondición: La lista no debe estar vacía.
            * Postcondición: Se actualizan los valores de memoria
            * Complejidad: O(1)
            *
            */
            NodoLista<T> *temporal = head -> next;

            if(!head){
                return false;
            }
            
            else {
                
                if(temporal) {
                    temporal->prev = nullptr;
                }
                delete head;
                head = temporal;
                size--;
                return true;
            }
        }

        bool eliminartail() {
            /*
            *
            * Descripción: Elimina el último dato del arreglo.
            * Entrada:  Ninguna
            * Salida: bool
            * Precondición: Si la lista está vacía o si contiene solo un elemento.
            * Postcondición: Se actualizan los valores de memoria
            * Complejidad: O(n)
            *
            */

           // Para revisar si la lista esta vacia
           if (!head) {
                return false; 
            }
            // para un solo elemento
            if (!head->next) {
                delete head;
                head = nullptr;
                size--;
                return true;
            }

            NodoLista<T> *ultimo = tail;
            NodoLista<T> *anterior = ultimo -> prev;

            
            anterior -> next = nullptr;
            tail = anterior;

            delete ultimo;
            size--;
            return true;
        }

        bool IsEmpty() const {
            if (head == nullptr){
                return true;
            }
            else{
                return false;
            }
            
        }

        void borrar(){
            while(head) {
                NodoLista<T> *siguiente = nullptr;

                siguiente = head->next;
                delete head;
                head = siguiente;
            }
            size = 0;
        }



    class iterator {
    public:
        iterator(NodoLista<T>* node) : current(node) {}

        T& operator*() {
            return current->info;
        }

        iterator& operator++() {
            if(current)
                current = current->next;
            return *this;
        }

        bool operator==(const iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const {
            return current != other.current;
        }

    private:
        NodoLista<T>* current;
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }
    
};


#endif


    
