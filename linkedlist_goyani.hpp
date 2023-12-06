/*
Name: Prince Shaileshbhai Goyani
Date: 12/4/2023
Description: This amusing zombie conga list showcases a dynamic array of actions performed on randomly selected zombies. The implementation relies on a doubly linked list structure.

Usage:: Compile the program by entering "make" in the terminal, and execute it with "./Zombie." For more details, refer to the README.txt file included in the project documentation.
*/

#include <iostream>
using namespace std;

#include "Node.hpp"
template <typename T>

class LinkedList {
public:
    Node<T> *currentNode;
    
    // Constructor
    LinkedList() {
        currentNode = nullptr;
    }
    
    // Destructor
    ~LinkedList() {
        deleteLinkedList(currentNode);
    }

    // Deletes the linked list
    void deleteLinkedList(Node<T> *list) {
        if (list != nullptr) {
            while (list->getPrevious() != nullptr) {
                list = list->getPrevious();
            }

            Node<T> *current = list;

            while (current != nullptr) {
                Node<T> *nodeNow = current->getNext();
                delete current;
                current = nodeNow;
            }
            list = nullptr;
        }
    }
   
    // Move the current pointer to the last node in the list
    void LinkLastPointer() {
        while (currentNode->getNext() != nullptr) {
            currentNode = currentNode->getNext();
        }
    }

    // Move the current pointer to the first node in the list
    void LinkFirstPointer() {
        while (currentNode->getPrevious() != nullptr) {
            currentNode = currentNode->getPrevious();
        }
    }
    
    // Get the size of the linked list
    int Length() {
        if (currentNode == nullptr) {
            return 0;
        }
        if ((currentNode->getData()) == NULL) {
            cout << 2;
            return 0;
        }
        LinkFirstPointer();
        cout << 3;
        Node<T> *tempNode =  currentNode;
        int i = 1;
        while (currentNode->getNext() != nullptr) {
            currentNode = currentNode->getNext();
            i += 1;
        }
        cout << "L:";
        cout << i << endl;
        return i;
    }

    // Add a node with data to the front of the list
    void AddToFront(T receivedData) {
        try {
            Node<T> *tempNode =  new Node<T>();
            tempNode->setData(receivedData);
            if (currentNode == nullptr) {
                currentNode = tempNode;
            } else {
                LinkFirstPointer();
                tempNode->setNext(currentNode);
                currentNode->setPrevious(tempNode);
                currentNode = tempNode;
            }
        } catch(std::bad_alloc) {
            cout << "found" << endl;
        }
    }

    // Add a node with data to the end of the list
    void AddToEnd(T receivedData) {
        try {
            Node<T> *tempNode =  new Node<T>();
            tempNode->setData(receivedData);
            if (currentNode == nullptr) {
                currentNode = tempNode;
                cout << "d" << endl;
            } else {
                cout << "g" << endl;
                LinkLastPointer();
                currentNode->setNext(tempNode);
                tempNode->setPrevious(currentNode);
                currentNode = tempNode;
            }
        } catch(std::bad_alloc) {
            cout << "found" << endl;
        }
    }

    // Add a node with data at a specific index in the list
    void AddAtIndex(T receivedData, int index) {
        try {
            int size = Length();
            if (index < 0 || index > size) { 
                throw std::out_of_range("Out Of range index");
            }

            if (index == 0) {
                AddToFront(receivedData);
            } else if(index == size) {
                AddToEnd(receivedData);
            } else {
                Node<T> *tempNode =  new Node<T>();
                LinkFirstPointer();
                int i = 0;
                while (i < size) {
                    if (i == index) {
                        // Creating a new node to insert    
                        tempNode->setPrevious(currentNode->getPrevious());
                        tempNode->setData(receivedData);
                        tempNode->setNext(currentNode);

                        // Inserting it by changing previous and next node addresses of the nodes which are previous and next to the index
                        currentNode->getPrevious()->setNext(tempNode);
                        currentNode->setPrevious(tempNode);
                        currentNode = tempNode;
                        break;
                    }
                    currentNode = currentNode->getNext();
                    i += 1;
                }
            }
        } catch(std::bad_alloc) {
            cout << "found" << endl;
        } catch(std::out_of_range) {
            cout << "found" << endl;
            cout << "try again";
        }
    }

    // Add a node with data before a given node
    void AddBefore(Node<T> *receivedNode, T receivedData) {
        if (currentNode == nullptr) {
            throw std::out_of_range("Current Node is empty");
        } 
        
        Node<T> *tempNode =  new Node<T>();
        if (currentNode->getPrevious() != nullptr) {
            tempNode->setPrevious(receivedNode->getPrevious());
        }
        
        tempNode->setData(receivedData);
        tempNode->setNext(receivedNode);

        // Inserting it by changing previous and next node addresses of the nodes which are previous and next to the given node
        if (receivedNode->getPrevious() != nullptr) {
            receivedNode->getPrevious()->setNext(tempNode);
        }
        receivedNode->setPrevious(tempNode);
        
        LinkFirstPointer();
    }

    // Add a node with data after a given node
    void AddAfter(Node<T> *receivedNode, T receivedData) {
        if (currentNode == nullptr) {
            LinkFirstPointer();
            throw std::out_of_range("Current Node is empty");
        } 
        
        Node<T> *tempNode =  new Node<T>();
        
        tempNode->setPrevious(receivedNode);
        tempNode->setData(receivedData);
        tempNode->setNext(receivedNode->getNext());

        // Inserting it by changing previous and next node addresses of the nodes which are previous and next to the given node
        if (receivedNode->getNext() != nullptr) {
            receivedNode->getNext()->setPrevious(tempNode);
        }
        receivedNode->setNext(tempNode);
        
        LinkFirstPointer();
    }

    // Remove the front node and return its data
    T RemoveFromFront() {
        LinkFirstPointer();
        Node<T> *tempNode =  currentNode;
        T collectData = currentNode->getData();
        currentNode = currentNode->getNext();
        currentNode->setPrevious(nullptr);
        delete tempNode;
        return collectData;
    }

    // Remove the last node and return its data
    T RemoveFromEnd() {
        LinkLastPointer();
        Node<T> *tempNode =  currentNode;
        T collectData = currentNode->getData();
        currentNode = currentNode->getPrevious();
        currentNode->setNext(nullptr);
        delete tempNode;
        return collectData;
    }

    // Remove the first occurrence of a specified data from the list
    void RemoveTheFirst(T receivedData) { 
        if (currentNode != nullptr) {
            LinkFirstPointer();
        }
        while (currentNode != nullptr) {
            if (currentNode->getData() == receivedData) {
                Node<T> *tempNode =  currentNode;
                if (currentNode->getPrevious() != nullptr) {
                    currentNode->getPrevious()->setNext(currentNode->getNext());
                }
                if (currentNode->getNext() != nullptr) {
                    currentNode->getNext()->setPrevious(currentNode->getPrevious());
                    currentNode = currentNode->getNext();
                } else {
                    currentNode = currentNode->getPrevious();
                }
                delete tempNode;
                break;
            }
            currentNode = currentNode->getNext();
        }
    }

    // Remove all nodes with a specified data
    void RemoveAllOf(T targetData) {
        LinkFirstPointer();
        Node<T> *head = currentNode;
        Node<T> *current = currentNode;
        Node<T> *previous = NULL;

        while (current != NULL) {
            if (current->data == targetData) {
                if (previous == NULL) { // if the node to be removed is the head node
                    head = current->nextT;
                    if (head != NULL) {
                        head->previousT = NULL;
                    }
                } else {
                    previous->nextT = current->nextT;
                    if (current->nextT != NULL) {
                        current->nextT->previousT = previous;
                    }
                }

                Node<T> *temp = current;
                current = current->nextT;
                delete temp;
            } else {
                previous = current;
                current = current->nextT;
            }
        }

        currentNode = head;
    }

    // Remove the node before a given node
    Node<T> *RemoveBefore(Node<T> *received) {
        if (received == nullptr || received->previousT == nullptr) {
            return nullptr;
        } else {
            Node<T> *temp = received->previousT;
            Node<T> *preNode = temp->previousT;

            received->nextT = preNode;
            if (preNode != nullptr) {
                preNode->previousT = received;
            }

            return temp;
        }
    }

    // Remove the node after a given node
    Node<T> *RemoveAfter(Node<T> *currentNode) {
        if (currentNode == nullptr || currentNode->nextT == nullptr) {
            return nullptr;
        } else {
            Node<T> *temp = currentNode->nextT;
            Node<T> *nextNode = temp->nextT;

            currentNode->nextT = nextNode;
            if (nextNode != nullptr) {
                nextNode->previousT = currentNode;
            }

            return temp;
        }
    }

    // Check if an element with given data exists in the list
    bool ElementExists(T receivedData) {
        if (currentNode == nullptr) return false;
        if (currentNode->getData() == receivedData) {
            LinkFirstPointer();
            return true;
        }
        while(currentNode->getNext() != nullptr) {
            if (currentNode->getNext()->getData() == receivedData) {
                return true;
            }
            currentNode = currentNode->getNext();
        }
        LinkFirstPointer();
        return false;
    }

    // Find a node with a given data
    Node<T>* Find(T receivedData) {
        if (currentNode == nullptr) return nullptr;
        LinkFirstPointer();
        if (currentNode->getData() == receivedData) return currentNode;
        while(currentNode->getNext() != nullptr) {
            if (currentNode->getNext()->getData() == receivedData) {
                return currentNode->getNext();
            }
            currentNode = currentNode->getNext();
        }
        LinkFirstPointer();
        return nullptr;
    }

    // Get the index of the first occurrence of a specified data
    int IndexOf(T receivedData) {
        if (currentNode == nullptr) {
            cout << 1;
            return -1;
        }
        LinkFirstPointer();
        if (currentNode->getData() == receivedData) {
            return 0;
        };
        cout << 1;
        cout << 2;
        int i = 1;
        cout << 3;
        while(currentNode->getNext() != nullptr) {
            cout << 4;
            if (currentNode->getNext()->getData() == receivedData) {
                return i;
            }
            currentNode = currentNode->getNext();
            i += 1;
        }
        cout << 5;
        return -1;
    }

    // Retrieve the data of the front node
    T RetrieveFront() {
        LinkFirstPointer();
        return currentNode->getData();
    }

    // Retrieve the data of the end node
    T RetrieveEnd() {
        LinkLastPointer();
        T collected = currentNode->getData();
        LinkFirstPointer();
        return collected;
    }

    // Retrieve the data at a specified index
    T Retrieve(int receivedIndex) {
        LinkFirstPointer();
        int size = Length();
        if (receivedIndex < 0 || receivedIndex > size - 1) throw std::out_of_range("Out of range provided index");
        if (receivedIndex == 0 ) return currentNode->getData();
        if (receivedIndex == size - 1 ) {
            LinkLastPointer();
            return currentNode->getData();
        }
        int i = 1;
        while (currentNode->getNext() != nullptr) {
            if (i == receivedIndex) {
                return currentNode->getNext()->getData();
            }
            currentNode = currentNode->getNext();
        }
        currentNode->getData();
        return NULL;
    }

    // Empty the linked list
    void Empty() {
        deleteLinkedList(currentNode);
        LinkFirstPointer();
    }

    // Print the linked list
    void PrintList() {
        LinkFirstPointer();
        Node<T> *tempNode = currentNode;
        int i = 1;
        while(tempNode != nullptr) {
            T tempData = tempNode->getData();
            cout << "[" ;
            cout << tempData.getType(); 
            cout << "]";
            tempNode = tempNode->getNext();
            if (tempNode!= nullptr) {
                cout << "=";
            }
            i = i +1;
        }
    }
};
