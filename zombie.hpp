/*
Name: Prince Shaileshbhai Goyani
Date: 12/4/2023
Description: This amusing zombie conga list showcases a dynamic array of actions performed on randomly selected zombies. The implementation relies on a doubly linked list structure.

Usage:: Compile the program by entering "make" in the terminal, and execute it with "./Zombie." For more details, refer to the README.txt file included in the project documentation.
*/
#include <iostream>
using namespace std;

class Zombie {
public:
    char type;

    // Default constructor
    Zombie() {
        type = '\0';
    }

    // Parameterized constructor
    Zombie(char receivedType) {
        type = receivedType;
    }

    // Getter for zombie type
    char getType() {
        return type;
    }

    // Overloaded equality operator to compare two zombies
    bool operator == (const Zombie &receivedType) {
        return (receivedType.type == type);
    }
};
