#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> address;
    weak_ptr<Node<T>> previous;

    Node(T value) : data(value), address(nullptr) {}
};

template<typename T>
class SingleLink {
protected:
    shared_ptr<Node<T>> body;
    int size;
public:
    SingleLink() : body(nullptr), size(0) {}

    void addFirst(T &value) {
        auto move = make_shared<Node<T>>(value);
        move->address = body;
        body = move;
        size++;
    }

    void addLast(T &value) {
        auto Mode = make_shared<Node<T>>(value);
        if (!body) {
            body = Mode;
        } else {
            auto move = body;
            while (move->address) {
                move = move->address;
            }
            move->address = Mode;
        }
        size++;
    }

    void removeFirst(T &value) {
        if (!body) {
            throw runtime_error("Empty");
        }
        body = body->address;
        size--;

    }

    void removeLast(T &value) {
        if (!body) {
            throw runtime_error("Empty");
        }
        if (!body->address) {
            body.reset();
        } else {
            auto move = body;
            while (move->address->address){
                move = move->address;
            }
            move->address.reset();
        }
        size--;
    }

    T access(int index){
        if (index < 0 || index > size){
            throw std::out_of_range("Out of range");
        }
        auto move = body;
        for (int i = 0; i < index; ++i) {
            move = move->address;
        }
        return move->data;
    }

};
