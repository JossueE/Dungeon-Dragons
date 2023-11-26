#include <iostream>
#include "grafo.h"
#include "catalogo.h" 
#include <string> 
using namespace std;

class Cuarto {
private:
    Monstruo monstruo; //Esto declara un miembro de datos llamado monstruo que es una instancia de la clase Monstruo.
public:
    Cuarto() {}  //La clase contiene dos constructores, uno que tomo a un monstruo como elemento y otra que no.
    Cuarto(const Monstruo _monstruo) : monstruo(_monstruo) {}

    const Monstruo& getMonstruo() const {
        return monstruo;
    }
    // definimos el overloader

    friend std::ostream& operator<<(std::ostream& os, const Cuarto& cuarto) {
        os << "Cuarto con " << cuarto.getMonstruo();
        return os;
    }
};


class Dungeon {
private:
    Graph<Cuarto> grafoCuartos;
    Lista<unsigned int> path; 
public:
    Dungeon() {}

    bool createDungeon(string filename){
        if(grafoCuartos.loadFile("dungeon.txt")){
            return true;
        }
        return false;
    }

    int getSize(){
        return grafoCuartos.getnSize();
    }

    bool createRoom(unsigned int c, Cuarto cuarto){
        if(grafoCuartos.setVertex(c, cuarto)){
            return true;
        }
        else{
            cout << "No se pudieron insertar datos en el cuarto" << endl;
            return false;
        }        
    }

    void imprimeCuartos(){
        grafoCuartos.print();
    }

    bool trazaRuta(unsigned int inicio, unsigned int fin) {
        if (grafoCuartos.BFS(inicio, fin)) {
            path = *grafoCuartos.getPath();
            
            if (!path.IsEmpty()) {
                std::cout << "Camino encontrado: ";
                path.imprimir();
                return true;
            } else {
                std::cout << "No se encontró un camino." << std::endl;
                return false;
            }
        } else {
            std::cout << "Error al buscar la ruta." << std::endl;
            return false;
        }
    }

    Cuarto* cuartoActualRuta() {
        if (!path.IsEmpty()) {
            unsigned int topIndex = path.GetHead()->info;
            return &grafoCuartos.getVertex(topIndex).data;
        }
        return nullptr;
    }

    bool avanzaRuta() {
        
        if (!path.IsEmpty()) {
            path.eliminartail();
            return true;
        }
        return false;
        return true;
    }
};

