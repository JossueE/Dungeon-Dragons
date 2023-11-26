#ifndef MONSTRUO_H
#define MONSTRUO_H
//Se aseguran de que el contenido del archivo solo se incluirá una vez en el proceso de compilación

#include <iostream>
using namespace std;

    class Monstruo {
    private:
    
        string name;
        double cr;
        string type;
        string size;
        int ac;
        int hp;
        string align;
    public:
        

        Monstruo(string _name, float _cr, string _type, string _size, int _ac, int _hp, string _align) 
    : name(_name), cr(_cr), type(_type), size(_size), ac(_ac), hp(_hp), align(_align) {}
        Monstruo(){}

        //Aquí definimos varios métodos para poder acceder a nuestros valores.
        string getNombre() const { return name; }
        double getCR() const { return cr; }
        string getTipo() const { return type; }
        string getTamano() const { return size; }
        int getAC() const { return ac; }
        int getHP() const { return hp; }
        string getAlineacion() const { return align; }

        unsigned int hash(){
            unsigned int size = 0, hashValue = 0;

            size = name.size();
            for(unsigned int i = 0; i < size; i++)
                hashValue += (unsigned int)name[i];
            return hashValue;
        }

        // Esta función permite asignar valores a los atributos de un objeto Monstruo. Lo hacemos fuera del constructor y a este lo dejamos como Default.
        void assignAtributes (string _name, float _cr, string _type, string _size, int _ac, int _hp, string _align) {
            name = _name;
            cr = _cr;
            type = _type;
            size = _size;
            ac = _ac;
            hp = _hp;
            align = _align;
        }



        //Sobrecarga el operador de inserción (<<) para que se pueda imprimir un objeto Monstruo desde la consola
        friend ostream& operator<<(ostream& os, const Monstruo& monstruo){
            os << monstruo.name << " ac: " << monstruo.getAC() << " hp: " << monstruo.getHP();
            return os;
        }
    

    };

#endif




