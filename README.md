
# Monster Catalog and Dungeon in C++

This project aims to implement the knowledge obtained about search algorithms and data structure, also is presented the UML diagram to show how OOP has been aplicated. This project is made in C++, its objective is and consists of a system that creates a catalog of monsters and then fills a dungeon with random monsters from that catalog. This documentation describes how the code works and how you can use it.

## Repository Content

- **main.cpp:** The main file that contains the main function, which is the entry point of the program. In this file, a monster catalog is created, and a dungeon is filled with random monsters.

- **catalogo.h:** The header file that defines the Catalogo class, which is used to load and manage the monster catalog from a CSV file.

- **nodos.h:** The header file that defines the NodoLista and Lista classes, which implement a generic double-linked list used in the Catalogo class.

- **monstruo.h:** The header file that defines the Monstruo class, representing a monster with various attributes.

- **monsters.csv:** An example file containing monster data in CSV format. This file is loaded into the monster catalog.

## Usage

1. Clone the repository or download the files to your computer.

2. Ensure you have a C++ development environment set up on your system.

3. Compile the code, including all source files (.cpp) and headers (.h), along with any test files if necessary.

4. Run the main program using the generated executable file.

5. The program will load the monster catalog from the "monsters.csv" file and fill a dungeon with random monsters. It will then print information about the rooms and the monsters in the dungeon.

## Project Structure

The project is divided into several classes and modules:

- **Catalogo** (catalogo.h):
    - This class is responsible for loading the monster catalog from a CSV file.
    - It provides methods to obtain a random monster from the catalog.
    - It uses a generic double-linked list to store the monsters.

- **Monstruo** (monstruo.h):
    - This class represents a monster with attributes such as name, challenge rating, type, size, armor class, hit points, and alignment.
    - It allows access to these attributes through methods.

- **Lista** (nodos.h):
    - This class defines a generic double-linked list used in the Catalogo class.
    - It provides functions to insert nodes at the head and tail, search for nodes, delete nodes, and more.

- **Jugador** (jugador.h):
    - Currently Empty

 ## Customization
 
 If you want to customize this code, you can do the following:

- Modify the "monsters.csv" file to add, remove, or edit monsters in the catalog.
- Expand the functionality of existing classes or add new classes as needed.
- Customize how monster information is displayed in the dungeon.
