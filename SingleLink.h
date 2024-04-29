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

    void addFirst(const T &value) {
        auto move = make_shared<Node<T>>(value);
        move->address = body;
        body = move;
        size++;
    }

    void addLast(const T &value) {
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

    void removeFirst() {
        if (!body) {
            throw runtime_error("Empty");
        }
        body = body->address;
        size--;

    }

    void removeLast( T &value) {
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

    void add(int index , T& value ){
        if (index < 0 || index > size){
            throw std::out_of_range("Out of range");
        }
        if (index == 0){
            addFirst(value);
        }else{
            auto move = body;
            for (int i = 0; i < index - 1; ++i) {
                move = move->address;
            }
            auto Mode = make_shared<Node<T>>(value);
            Mode->address = move->address;
            move->address = Mode;
            size++;
        }
    }

    void remove(int index ){
        if (index < 0 || index > size){
            throw std::out_of_range("Out of range");
        }
        if (index == 0){
            removeFirst();
        }else{
            auto move = body;
            for (int i = 0; i < index - 1; ++i) {
                move = move->address;
            }
            move->address = move->address->address;
            size--;
        }

    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
    bool contains(const T& value) const {
        auto move = body;
        while (move) {
            if (move->data == value) {
                return true;
            }
            move = move->next;
        }
        return false;
    }

    void print() const {
        auto move = body;
        while (move) {
            std::cout << move->data << " ";
            move = move->next;
        }
        std::cout << std::endl;
    }
};

