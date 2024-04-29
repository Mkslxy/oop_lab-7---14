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
        auto Mode = make_shared<Node<T>>(value);
        Mode->address = body;
        body = Mode;
        size++;
    }

    void addLast(T &value) {
        auto Mode = make_shared<Node<T>>(value);
        if (!body) {
            body = Mode;
        } else {
            auto Move = body;
            while (Move->address) {
                Move = Move->address;
            }
            Move->address = Mode;
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


};
