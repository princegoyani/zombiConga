#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;            // Data
    Node* previousT;   // Pointer to the previous node
    Node* nextT;       // Pointer to the next node

    // Default constructor
    Node() {
        data = NULL;
        previousT = nullptr;
        nextT = nullptr;
    }

    // Parameterized constructor with initial data
    Node(T receivedData) {
        data = receivedData;
        previousT = nullptr;
        nextT = nullptr;
    }

    // Parameterized constructor with initial data, previous, and next nodes
    Node(Node* receivedPrevious, T receivedData, Node* receivedNext) {
        data = receivedData;
        previousT = receivedPrevious;
        nextT = receivedNext;
    }

    // Getter for node data
    T getData() {
        return data;
    }

    // Setter for node data
    void setData(T receivedData) {
        data = receivedData;
    }

    // Getter for the next node
    Node<T>* getNext() {
        return nextT;
    }

    // Setter for the next node
    void setNext(Node* receivedNext) {
        nextT = receivedNext;
    }

    // Getter for the previous node
    Node<T>* getPrevious() {
        return previousT;
    }

    // Setter for the previous node
    void setPrevious(Node* receivedPrevious) {
        previousT = receivedPrevious;
    }
};
