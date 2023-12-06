/*
Name: Prince Shaileshbhai Goyani
Date: 12/4/2023
Description: This amusing zombie conga list showcases a dynamic array of actions performed on randomly selected zombies. The implementation relies on a doubly linked list structure.

Usage:: Compile the program by entering "make" in the terminal, and execute it with "./Zombie." For more details, refer to the README.txt file included in the project documentation.
*/

#include <iostream>
using namespace std;

#include "zombie.hpp"
#include "linkedlist_goyani.hpp"

class Conga
{
public:
    LinkedList<Zombie> *cong;

    // Constructor initializes the conga linked list
    Conga()
    {
        cong = new LinkedList<Zombie>();
    }

    // Engine action adds a zombie to the front of the conga
    void engine_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->LinkFirstPointer();
        list->AddToFront(receivedZomb);
    }

    // Caboose action adds a zombie to the end of the conga
    void caboose_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->LinkLastPointer();
        list->AddToEnd(receivedZomb);
    }

    // Jump-in action adds a zombie at a random index in the conga
    void jump_in_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        int randomIndex = rand() % list->Length();
        list->AddAtIndex(receivedZomb, randomIndex);
    }

    // Everyone-out action empties the conga
    void everyone_out_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->Empty();
    }

    // You-out action removes the first occurrence of a zombie from the conga
    void you_out_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->RemoveTheFirst(receivedZomb);
    }

    // Brains action adds a zombie to the front, end, and middle of the conga
    void brains_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->AddToFront(receivedZomb);
        list->AddToEnd(receivedZomb);
        int mid_size = (list->Length() / 2);
        list->AddAtIndex(receivedZomb, mid_size);
        list->PrintList();
    }

    // Rainbow action adds a zombie to the front and appends zombies with different colors
    void rainbow_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        list->AddToFront(receivedZomb);
        list->PrintList();
        cout << "a" << endl;

        char arr[] = {'R', 'Y', 'G', 'B', 'M', 'C'};
        int length = sizeof(arr) / sizeof(char);
        int i = 0;
        while (i < length)
        {
            Zombie tempZomb(arr[i]);
            list->AddToEnd(tempZomb);
            list->PrintList();
            cout << "b" << endl;
            i++;
        }
    }

    // Friends action adds a zombie before or after an existing zombie in the conga
    void friends_action(LinkedList<Zombie> *list, Zombie receivedZomb)
    {
        if (list->Find(receivedZomb) == nullptr)
        {
            caboose_action(list, receivedZomb);
        }
        else
        {
            if (rand() % 2 == 0)
            {
                list->AddBefore(list->Find(receivedZomb), receivedZomb);
            }
            else
            {
                list->AddAfter(list->Find(receivedZomb), receivedZomb);
            }
        }
    }
};
