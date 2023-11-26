#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class StackNodo{
    public:
        T info;
        StackNodo<T> *next;
    
        StackNodo(T dato) : info(dato), next(nullptr) {}
};

template <typename T>
class stack
{
private:
    StackNodo<T> *top;
public:
    stack(){
        top = nullptr;
    }

    ~stack(){
        StackNodo<T> *actual = nullptr;
        StackNodo<T> *eliminar = nullptr;
        actual = top;
            
        while(actual){
            eliminar = actual;
            actual = actual -> next;
            delete eliminar;
        }
    };

    bool Push (T dato){
            StackNodo<T> *NuevoNodo = nullptr;
            NuevoNodo = new StackNodo<T>(dato);

            if (!NuevoNodo)// if(NuevoNodo == nullptr)
            {
                return false;
            }
            NuevoNodo -> next = top;
            top = NuevoNodo;
            return true;
        }

    bool Pop (){
        StackNodo<T> *actual = nullptr;
        StackNodo<T> *temporal = nullptr;
        
        actual = top;

        if(!top){
            return false;
        }
        else {
            temporal = top -> next;
            delete top;
            top = temporal;
            return true;
        }
    }

    StackNodo<T>* GetTop() const {
 
        if(!top){
            return nullptr;
        }
        else {
            return top;
        }
    }

    bool isEmpty() const{
        return !top;
        
    }

    void imprimir (){
        StackNodo<T> *actual = nullptr;
        actual = top;
        while(actual != nullptr){
            cout << actual -> info << " ";
            actual = actual -> next;
        }
        cout << endl;
    }

};

#endif







