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

    public:
        Lista(){
            head = nullptr;
            tail = nullptr;   
        }

        ~Lista(){
            NodoLista<T> *actual = nullptr;
            NodoLista<T> *eliminar = nullptr;
            actual = head;
            
            while(actual){
                eliminar = actual;
                actual = actual -> next;
                delete eliminar;
            }
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
            return true;
        }

        int Size (){
            NodoLista<T> *actual = head;

            if(head == nullptr){
                return 0;
            }
            int count = 0;
            while(actual -> next != nullptr){
                actual = actual -> next;
                count ++;
            }
            return count;
        }

        bool InsertarTail(T dato){
            NodoLista<T> *NuevoNodo = new NodoLista<T>(dato);
            if(head == nullptr){
                head = NuevoNodo;
                head -> next = nullptr;
                head -> prev = nullptr;
                return true;
            }

            NodoLista<T> *actual = head;
            while(actual -> next != nullptr){
                actual = actual -> next;
            }

            actual -> next = NuevoNodo;
            actual -> prev = actual;
            NuevoNodo -> next = nullptr;
            return true;
        }

        void imprimir (){
            NodoLista<T> *actual = head;

            while(actual != nullptr){
                cout << actual -> info << " " << endl;
                actual = actual -> next;
            }
        }

        NodoLista<T>* GetNodoEnPos(int posicion) {
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

        NodoLista<T>* GetHead(){
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
            NodoLista<T> *actual = head;
            NodoLista<T> *temporal = nullptr;
            NodoLista<T> *anterior = nullptr;

            if(!head){
                return false;
            }
            if(head -> info == dato){
                temporal = head -> next;
                if (temporal) {
                    temporal->prev = nullptr;
                }
                delete head;
                head = temporal;
                return true;
            }

            while (actual){
                if(actual -> info == dato){
                    temporal = actual->next;
                    if (temporal) {
                        temporal->prev = anterior;
                    }
                    anterior->next = temporal;
                    delete actual;
                    return true;
                }

                anterior = actual;
                actual = actual -> next;
            }
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
            
            if(!head){
                return false;
            }
            
            else {
                NodoLista<T> *temporal = head -> next;
                if (temporal) {
                    temporal->prev = nullptr;
                }

                delete head;
                head = temporal;
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
                return true;
            }

            NodoLista<T> *ultimo = tail;
            NodoLista<T> *anterior = ultimo -> prev;

            
            anterior -> next = nullptr;
            tail = anterior;

            delete ultimo;
            return true;
        }

        bool IsEmpty(){
            if (head == nullptr){
                return true;
            }
            else{
                return false;
            }
            
        }

        void BorrarElementos(){
            delete this;
        }
};


    
