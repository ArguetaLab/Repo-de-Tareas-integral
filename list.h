#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <sstream>

template <class T>
class Link {
public:
    T value;
    Link<T>* next;
    Link(T val) : value(val), next(nullptr) {}
};

template <class T>
class List {
private:
    Link<T>* head;

public:
    List() : head(nullptr) {}   

    void insertion(T val)  {
    Link<T>* newVal = new Link<T>(val); // Create a new value with the given value

    if (head == nullptr) {
        head = newVal;
    } else {
        Link<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newVal;
    }
}
    int search(T val) {
        Link<T> *current = head;
        int index = 0;
        while (current) {
            if (current->value == val) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Element not found
    }

    void update(int index, T val) {
        Link<T> *current = head;
        int currentIndex = 0;
        while (current) {
            if (currentIndex == index) {
                current->value = val;
                return;
            }
            current = current->next;
            currentIndex++;
        }
    }

     void deleteAt(int index) {
        if (index == 0) {
            Link<T> *temp = head;
            head = head->next;
            delete temp;
        } else {
            Link<T> *current = head;
            int currentIndex = 0;
            while (current) {
                if (currentIndex == index - 1) {
                    Link<T> *temp = current->next;
                    current->next = temp->next;
                    delete temp;
                    return;
                }
                current = current->next;
                currentIndex++;
            }
        }
    }

    std::string toString() const {
        std::stringstream aux;
        Link<T>* p = head;
        aux << "[";
        while (p != nullptr) {
            aux << p->value;
            if (p->next != nullptr) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }
};

#endif /* LIST_H */