#ifndef CATALOGO_H
#define CATALOGO_H
//Se aseguran de que el contenido del archivo solo se incluirá una vez en el proceso de compilación


#include <iostream>
#include "monstruo.h"
#include "nodos.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Catalogo {
private: 
    Lista<Monstruo> monstruos; //Una lista que almacena objetos de la clase Monstruo
    

public:
    Catalogo(/* args */){
        srand(static_cast<unsigned>(time(nullptr))); //Inicializa la semilla del generador de números aleatorios utilizando la hora actual del sistema
    };
    

    bool loadFromCSV(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "No se pudo abrir el archivo CSV." << endl;
            return false;
        }

        string line;
        getline(file, line); // Leer la primera línea (encabezado) y descartarla

        while (getline(file, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() != 7) {
                cout << "Error en el formato de línea CSV: " << line << endl;
                continue;
            }

            string name = tokens[0];
            float cr = stof(tokens[1]);
            string type = tokens[2];
            string size = tokens[3];
            int ac = stoi(tokens[4]);
            int hp = stoi(tokens[5]);
            string align = tokens[6];

            Monstruo monstruo(name, cr, type, size, ac, hp, align);
            monstruos.InsertarNodo(monstruo);
        }

        file.close();
        return true;
    }

    Monstruo* getRandomMonster() {
        if (monstruos.IsEmpty()) {
            cerr << "El catálogo de monstruos está vacío." << endl;
            return nullptr;
        }
        else {
            int numMonstruos = monstruos.Size();
            int indiceAleatorio = rand() % numMonstruos;
            NodoLista<Monstruo>* nodo = monstruos.GetNodoEnPos(indiceAleatorio);
            if (nodo) {
                return &(nodo->info);
            }
        }
        // Si no se pudo seleccionar un monstruo aleatorio, se retorna un Monstruo vacio
        cerr << "Error al seleccionar un monstruo aleatorio." << endl;
        return nullptr;
    }
};


#endif // CATALOGO_H


