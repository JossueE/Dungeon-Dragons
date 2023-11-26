#ifndef COLA_H
#define COLA_H
using namespace std;

template <typename T>
class NodoCola {
public:
    T info;
    NodoCola* next;

    NodoCola(T dato) {
        info = dato;
        next = nullptr;
    }
};

template <typename T>
class Cola {
private:
    NodoCola<T>* frente;
    NodoCola<T>* atras;

public:
    Cola() {
        frente = nullptr;
        atras = nullptr;
    }

    ~Cola() {
        while(!isEmpty()) {
            pop();
        }
    }

    bool push(T dato) {
        NodoCola<T>* NuevoCola = new NodoCola<T>(dato);
        if (!NuevoCola) {
            return false;
        }
        if (atras != nullptr) {
            atras->next = NuevoCola;
        }
        atras = NuevoCola;
        if (frente == nullptr) {
            frente = atras;
        }
        return true;
    }

    bool pop(){
        if (frente == nullptr) {
            return false;
        }
        NodoCola<T>* tmp = frente;
        frente = frente->next;
        if (frente == nullptr) {
            atras = nullptr;
        }
        delete tmp;
        return true;
    }

    NodoCola<T>* getfront(){
        return frente;
    }

    bool isEmpty(){
        return frente == nullptr;
    }

    void print_q(){
        NodoCola<T>* actual = frente;

        while (actual != nullptr) {
            cout << actual->info << " ";
            actual = actual->next;
        }
        cout << endl;
    }
};

#endif