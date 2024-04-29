#include <iostream>
#include "SingleLink.h"
#include <memory>

using namespace std;

template<typename T>
class DoubleLink : public SingleLink<T> {
public:
    void AddFirst(const T &value) {
        auto newNode = make_shared<Node<T>>(value);
        if (this->body) {
            newNode->address = this->body;
            this->body->tail = newNode;
        }
        this->body = newNode;
        this->size++;
    }

    void AddLast(const T &value) {
        auto newNode = make_shared<Node<T>>(value);
        if (!this->body) {
            this->body = newNode;
        } else {
            auto currentNode = this->body;
            while (currentNode->address) {
                currentNode = currentNode->address;
            }
            currentNode->address = newNode;
            newNode->tail = currentNode;
        }
        this->size++;
    }


};
