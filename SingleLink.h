#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct Node {
    T data;
    shared_ptr<Node<T>> address;
    weak_ptr<Node<T>> tail;

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
        auto newNode = make_shared<Node<T>>(value);
        newNode->address = body;
        body = newNode;
        size++;
    }

    void addLast(const T &value) {
        auto newNode = make_shared<Node<T>>(value);
        if (!body) {
            body = newNode;
        } else {
            auto currentNode = body;
            while (currentNode->address) {
                currentNode = currentNode->address;
            }
            currentNode->address = newNode;
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

    void removeLast() {
        if (!body) {
            throw runtime_error("Empty");
        }
        if (!body->address) {
            body.reset();
        } else {
            auto currentNode = body;
            while (currentNode->address->address){
                currentNode = currentNode->address;
            }
            currentNode->address.reset();
        }
        size--;
    }

    T access(int index){
        if (index < 0 || index > size){
            throw out_of_range("Out of range");
        }
        auto currentNode = body;
        for (int i = 0; i < index; ++i) {
            currentNode = currentNode->address;
        }
        return currentNode->data;
    }

    void add(int index , T& value ){
        if (index < 0 || index > size){
            throw out_of_range("Out of range");
        }
        if (index == 0){
            addFirst(value);
        }else{
            auto currentNode = body;
            for (int i = 0; i < index - 1; ++i) {
                currentNode = currentNode->address;
            }
            auto newNode = make_shared<Node<T>>(value);
            newNode->address = currentNode->address;
            currentNode->address = newNode;
            size++;
        }
    }

    void remove(int index ){
        if (index < 0 || index > size){
            throw out_of_range("Out of range");
        }
        if (index == 0){
            removeFirst();
        }else{
            auto currentNode = body;
            for (int i = 0; i < index - 1; ++i) {
                currentNode = currentNode->address;
            }
            currentNode->address = currentNode->address->address;
            size--;
        }

    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        if (size > 0)return true;
        else return false;
    }
    bool contains(const T& value) const {
        auto currentNode = body;
        while (currentNode) {
            if (currentNode->data == value) {
                return true;
            }
            currentNode = currentNode->address;
        }
        return false;
    }

    void print() const {
        auto currentNode = body;
        while (currentNode) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->address;
        }
        std::cout << std::endl;
    }
};

