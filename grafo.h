#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "nodos.h"
#include "queue.h"
#include "stack.h"

template <typename T>
class Vertex{
public:
    T data;
    Lista<int> edges;
    bool visited;
    Vertex() : visited(false){}
};

template <typename T>
class Graph{
private:
    Vertex<T> *vertices;
    unsigned int *previous;
    unsigned int size;
    Lista<unsigned int> npath;

public:
    Graph(){
        vertices = nullptr;
        size = 0;
        previous = 0;
    }
    ~Graph(){
        erase();
    }

    bool createGraph(unsigned int nSize) {
        if(nSize == 0 || vertices)
            return false;

        vertices = new(std::nothrow) Vertex<T>[nSize];
        if(!vertices)
            return false;
        previous = new(std::nothrow) unsigned int[size];
        if (!previous) {
            delete[] vertices;
            return false;
        }
        for (unsigned int j = 0; j < size; j++){
            previous[j] = UINT_MAX;
        }
        
        size = nSize;
        return true;
    }

    bool setVertex(unsigned int vertex, T dato){
        if(!size || vertex >= size){
            return false;
        }
        vertices[vertex].data = dato;
        return true;
    }
    
    bool insertEdge(unsigned int vert1, unsigned int vert2){
        if(!vertices)
            return false;

        if(vert1 >= size || vert2 >= size)
            return false;
        
        if(vertices[vert1].edges.buscar(vert2))
            return false;

        if(!vertices[vert1].edges.InsertarTail(vert2))
            return false;
        return true;
    }

    Vertex<T>& getVertex(unsigned int vertex) {
        if (vertex < size) {
            return vertices[vertex];
        } else {

            throw std::out_of_range("Índice de vértice fuera de rango");
        }
    }

    void erase() {
        if(!size)
            return;
        
        if(previous) {
            delete [] previous;
            previous = nullptr;
            size = 0;
        }

        if(vertices) {
            delete [] vertices;
            vertices = nullptr;
            size = 0;
        }   
    }

    void print() {
        for(unsigned int i = 0; i < size; i++) {
            std::cout << "[" << i << "]" << vertices[i].data << ": ";
            vertices[i].edges.imprimir();
        }
    }

    bool saveFile(std::string filename) {
        std::ofstream    file;

        if(!size)
            return false;

        file.open(filename, std::ios::out);
        if (!file.is_open()) {
            std::cerr << "Error al guardar al archivo: " << filename << std::endl;
            return false;
        }
        // El encabezado es una palabra
        file << "Grafo\n";
        // seguido de la cantidad de vertices
        file << size << "\n";

        // luego la lista a agregar de aristas
        for(unsigned int i = 0; i < size; i++) {
            Lista<unsigned int>::iterator j(nullptr);

            for (j = vertices[i].edges.begin(); j != vertices[i].edges.end(); ++j)
                file << *j << " ";
            file << "\n";
        }

        file.close();

        return true;
    }

    bool loadFile(std::string filename)  {
        std::ifstream   file;
        std::string     line;
        unsigned int    vertex = 0, nSize = 0;

        file.open(filename, std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Error al cargar el archivo: " << filename << std::endl;
            return false;
        }
        // Leer encabezado
        if(!getline(file, line)) {
            file.close();
            return false;
        }
        
        if(line != "Grafo") {
            file.close();
            return false;
        }

        // Obtener cantidad de vertices
        if(!getline(file, line)) {
            file.close();
            return false;
        }

        if(!isValidNumeric(line)) {
            file.close();
            return false;
        }

        nSize = std::stod(line);
        if(nSize <= 0) {
            file.close();
            return false;
        }

        // Borrar el grafo actual
        erase();

        // crear nuevos vertices
        if(!createGraph(nSize)) {
            file.close();
            return false;
        }

        for(vertex = 0; vertex < size; vertex ++) {
            // Obtener las aristas
            if(!getline(file, line)) {
                file.close();
                return false;
            }

            // revisar si hay contenido
            if(line.length()) {
                std::stringstream    ss(line);
                std::string          cell;

                while (getline(ss, cell, ' ')) {
                    int destino = 0;

                    if(!isValidNumeric(cell)) {
                        file.close();
                        return false;
                    }

                    destino = std::stod(cell);
                    if(!insertEdge(vertex, destino)) {
                        file.close();
                        return false;
                    }
                }
            }
        }
        
        file.close();

        return true;
    }

    

    bool BFS(unsigned int startVertex, unsigned int finalVertex) {
        if (startVertex < 0 || startVertex >= size || finalVertex < 0 || finalVertex >= size) {
            std::cout << "Los vértices de inicio y final deben estar dentro de los límites del grafo." << std::endl;
            return false;
        }

        clearVisited();
        Cola<unsigned int> cola;
        stack<unsigned int> path;
        
        
        

        cola.push(startVertex);
        vertices[startVertex].visited = true;

        while (!cola.isEmpty()) {
            unsigned int vertex = cola.getfront()->info;  
            cola.pop();

            if (vertex == finalVertex) {
                npath.InsertarNodo(vertex);
                return true;
            }

            Lista<int>::iterator it = vertices[vertex].edges.begin();
            while (it != vertices[vertex].edges.end()) {
                if (*it == finalVertex) {
                    previous[*it] = vertex;
                    unsigned int i = finalVertex;
                    while (i != UINT_MAX){
                        path.Push(i);
                        i = previous[i];
                    }
                    while(!path.isEmpty()){
                        npath.InsertarNodo(path.GetTop()->info);
                        path.Pop();
                    }
                    npath.imprimir();
                    return true;
                }

                if (!vertices[*it].visited) {
                    cola.push(*it);
                    vertices[*it].visited = true;
                    previous[*it] = vertex;
                }
                ++it;
            }
        }

        return false; // Si no se encuentra el vértice final, se retorna la lista vacía.
    }

    unsigned int getnSize(){
        return size;
    }
    
    Lista<unsigned int> *getPath(){
        return &npath;
    }

private:
    void clearVisited() {
        for (size_t i = 0; i < vertices->edges.Size(); ++i) {
            vertices[i].visited = false;
        }
    }

    bool isValidNumeric(const std::string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

};
