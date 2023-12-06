/*
Name: Prince Shaileshbhai Goyani
Date: 12/4/2023
Description: This amusing zombie conga list showcases a dynamic array of actions performed on randomly selected zombies. The implementation relies on a doubly linked list structure.

Usage: Compile the program by entering "make" in the terminal, and execute it with "./Zombie." For more details, refer to the README.txt file included in the project documentation.
*/
#include <iostream>
using namespace std;

#include "Conga.hpp"

// Function to generate a random zombie
Zombie generateZombie()
{
    char arr[] = {'R', 'Y', 'G', 'B', 'M', 'C'}; // HERE R = RED , Y = YELLOW , G = GREEN, B = BLUE , M = MAGENTA, C = CYAN
    int randomGen = rand() % 6;
    cout << "r" << endl;
    cout << randomGen << endl;
    char chosenZomb = arr[randomGen];
    Zombie newZombie(chosenZomb);
    return newZombie;
}

int main(int argc, char **argv)
{
    srand(time(0));
    if (argc == 3)
    {
        char *a = argv[2];
        int intTime = atoi(a);
        srand(intTime);
    }

    Conga *newCong = new Conga();

    Zombie newZomb = generateZombie();
    newCong->rainbow_action(newCong->cong, newZomb);

    for (int i = 0; i < 3; i++)
    {
        newCong->brains_action(newCong->cong, generateZombie());
    }

    int numberOfRounds;
    cout << "Hello, Welcome to ZOMBI CONGA.. Start with rounds :- ";
    cin >> numberOfRounds;

    int size = 0;

    for (int i = 0; i <= numberOfRounds; i++)
    {
        if (numberOfRounds % 5 == 0)
        {
            newCong->cong->RemoveFromFront();
            newCong->cong->RemoveFromEnd();
        }

        int randomAction = rand() % 8;

        if (randomAction == 0)
        {
            newCong->engine_action(newCong->cong, generateZombie());
            cout << "Engine Acted" << endl;
        }

        if (randomAction == 1)
        {
            newCong->caboose_action(newCong->cong, generateZombie());
            cout << "Caboose Acted" << endl;
        }

        if (randomAction == 2)
        {
            newCong->jump_in_action(newCong->cong, generateZombie());
            cout << "Jump Acted" << endl;
        }
        if (randomAction == 3)
        {
            newCong->everyone_out_action(newCong->cong, generateZombie());
            cout << "Out Acted" << endl;
        }

        if (randomAction == 4)
        {
            newCong->you_out_action(newCong->cong, generateZombie());
            cout << "you Out Acted" << endl;
        }

        if (randomAction == 5)
        {
            newCong->brains_action(newCong->cong, generateZombie());
            cout << "Brain Acted" << endl;
        }

        if (randomAction == 6)
        {
            newCong->rainbow_action(newCong->cong, generateZombie());
            cout << "rainbow Acted" << endl;
        }

        if (randomAction == 7)
        {
            newCong->friends_action(newCong->cong, generateZombie());
            cout << "Friend Acted" << endl;
        }

        cout << "Conga line : " << endl;

        int size = newCong->cong->Length();
        if (size == 0)
        {
            cout << "Party is over" << endl;
        }
        else
        {
            cout << "Size: " << size << " :: ";
            newCong->cong->PrintList();
            cout << "**************************************************" << endl;
        }
    }

    char option;
    cout << "Want to want to play again (Y/N): ";
    cin >> option;

    if (toupper(option) == 'Y')
    {
        main(argc, argv);
    }

    return 0;
}
