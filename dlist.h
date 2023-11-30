#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <sstream>

template <typename T>
class DList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DList() : head(nullptr), tail(nullptr) {}

    // Function to insert an element at the end of the list
    void insertion(const T& value) {
        Node* newNode = new Node(value);
        //nodo es el elemento de la lista
        // esto es el nodo que vamos a agregar a la lista

        if (!head) {
            // Si la lista está vacía, el nuevo nodo se convierte en la cabeza y la cola
            head = newNode;
            tail = newNode;
        } else {
            // Enlazar el nuevo nodo al final de la lista
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to search for an element in the list
    T search(const T& value) const {
            Node* current = head;
        int index = 0;

        while (current) {
            if (current->data == value) {
                return index; // Se encontró el valor, se devuelve el índice
            }
        current = current->next;
        index++;
    }

    // El valor no se encontró en la lista
    return -1;
}

    // Function to update an element at a specific index
    void update(int index, const T& value) {
            if (index < 0) {
        // Índice negativo, no se puede actualizar
        return;
    }

    Node* current = head;
    int currentIndex = 0;

    while (current && currentIndex != index) {
        current = current->next;
        currentIndex++;
    }

    if (current) {
        // Se encontró el nodo en la posición especificada
        current->data = value; // Actualiza el valor del nodo
    }
    }

    // Function to delete an element at a specific index
    void deleteAt(int index) {
        if (index < 0) {
        // Índice negativo, no se puede eliminar
        return;
    }

    Node* current = head;
    int currentIndex = 0;

    while (current && currentIndex != index) {
        current = current->next;
        currentIndex++;
    }

    if (current) {
        // Se encontró el nodo en la posición especificada

        if (current->prev) {
            current->prev->next = current->next; // Actualiza el puntero "next" del nodo anterior
        } else {
            head = current->next; // Si es el primer nodo, actualiza la cabeza
        }

        if (current->next) {
            current->next->prev = current->prev; // Actualiza el puntero "prev" del nodo siguiente
        } else {
            tail = current->prev; // Si es el último nodo, actualiza la cola
        }

        delete current; // Libera la memoria del nodo eliminado
    }

    }

    // Destructor to clean up memory
    ~DList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to convert the list to a forward string representation
    std::string toStringForward() const {
        std::stringstream ss;
        ss << "[";
        Node* current = head;
        while (current) {
            ss << current->data;
            if (current->next) {
                ss << ", ";
            }
            current = current->next;
        }
        ss << "]";
        return ss.str();
    }

    // Function to convert the list to a backward string representation
    std::string toStringBackward() const {
        std::stringstream ss;
        ss << "[";
        Node* current = tail;
        while (current) {
            ss << current->data;
            if (current->prev) {
                ss << ", ";
            }
            current = current->prev;
        }
        ss << "]";
        return ss.str();
    }
};

#endif