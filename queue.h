#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>

class Node{
    public:
    T value;
    Node<T>* down = nullptr;
    Node(T x){
        value = x;
    }
};

template<typename T>

class Queue{
    public: 
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    Queue(T x){
        head = new Node(x);
        tail = head;
    }
    bool isEmpty(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
    T rear(){
        return tail->value;
    }
    T front(){
        return head->value;
    }
    void Enqueue(T x){
        if(tail == nullptr && head == nullptr){
            Node<T>* newNode = new Node(x);
            head = newNode;
            tail = newNode; 
        } else {
            Node<T>* newNode = new Node(x);
            tail->down = newNode;
            tail = newNode; 
            if (head == nullptr){
                head = tail;
            }
        }
    }
    T Dequeue(){
        assert(head != nullptr);
        T val = head->value;
        Node<T>* newNode = head;
        head = head->down;
        delete(newNode);
        return val;
    }
};