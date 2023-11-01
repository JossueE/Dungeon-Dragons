#include <iostream>
#include "catalogo.h"
using namespace std;

class Cuarto {
private:
    Monstruo monstruo; //Esto declara un miembro de datos llamado monstruo que es una instancia de la clase Monstruo.
public:
    Cuarto() {}  //La clase contiene dos constructores, uno que tomo a un monstruo como elemento y otra que no.
    Cuarto(Monstruo _monstruo) : monstruo(_monstruo) {}
    Monstruo getMonstruo() {
        return monstruo;
    }

};


class Dungeon {
private:
    Lista<Cuarto> listaCuartos; //Representa un calabozo. Es un template y se espera que se le proporcione un tipo concreto (como Cuarto) cuando se instancia.

public:
    Dungeon() {}

    bool createRoom(Cuarto cuarto) {
        listaCuartos.InsertarNodo(cuarto); //Usamos las funciones de nuestro nodos.h
        return true;
        }

    void imprimeCuartos() {
        NodoLista<Cuarto>* actual = listaCuartos.GetHead(); //Tuvimos que implementar la función GetHead en nuestra DLlist
        while (actual != nullptr) {
            Monstruo monstruo = actual->info.getMonstruo();
            cout << "Cuarto con Monstruo: " << monstruo.getNombre() << endl;
            actual = actual->next;
        }
    };

};
