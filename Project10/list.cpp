#include "list.h"

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    clear();
}

List::List(const List& other) {
    head = tail = nullptr;
    size = 0;

    if (other.size == 0) {
        return;
    }

    Node* current = other.head;
    Node* x;
    Node* y = new Node(current->value);
    head = y;
    tail = y;
    size = other.size;
    current = current->next;

    while (current) {
        x = y;
        y = new Node(current->value);
        x->next = y;
        y->prev = x;
        tail = y;
        current = current->next;
    }
}

void List::push_back(int value) {
    if (head && tail) {
        Node* new_node = new Node(tail, value);
        tail->next = new_node;
        tail = new_node;
    }
    else {
        Node* new_node = new Node(value);
        head = new_node;
        tail = new_node;
    }
    size++;
}

void List::push_front(int value) {
    if (head && tail) {
        Node* new_node = new Node(value, head);
        head->prev = new_node;
        head = new_node;
    }
    else {
        Node* new_node = new Node(value);
        head = new_node;
        tail = new_node;
    }
    size++;
}

void List::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void List::show() const {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
