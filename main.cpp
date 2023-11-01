#include <iostream>
#include "catalogo.h"
#include "dungeon.h"

using namespace std;

#define NUM_CUARTOS 20

int main(){
    Catalogo    miCatalogo;
    Dungeon   miDungeon;

    if(!miCatalogo.loadFromCSV("monsters.csv")){
        cout << "No se puede crear catalogo"<< endl;
    }

    cout << "Creando Dungeon..." << endl;
    for(int c = 0; c < NUM_CUARTOS; c++){
        Monstruo *pMonster = nullptr, copiaMonstruo;

        pMonster = miCatalogo.getRandomMonster();
        if(!pMonster){
            cout << "No se pudo cargar el monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if(!miDungeon.createRoom(copiaMonstruo)){
            cout << "No se puede insertar cuarto con monstruo al calabozo" << endl;
            return 0;
        }
    }

    miDungeon.imprimeCuartos();

    return 0;
}