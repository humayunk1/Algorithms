#ifndef NODE_H
#define NODE_H


//Structure to represent a node of a linked list
template<class T>
struct Node {
        T val;
        Node *next;

        Node() {}
        Node(const T& t, Node *p) : val(t), next(p) {}

        //destructor
        ~Node() {
		delete next;
        }
};


#endif
