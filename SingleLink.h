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



};
