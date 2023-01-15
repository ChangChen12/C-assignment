#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>
#include <utility>
 
using std::initializer_list;


// TODO your code goes here:
template<typename T>
class LinkedList {
public:
    int sizee;
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() {
        sizee = 0;
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(const initializer_list<T> & initializeListIn) {
        sizee = 0;
        head = nullptr;
        tail = nullptr;
        for (auto & n : initializeListIn) {
            push_back(n);
        }
    }



    ~LinkedList(){
        if(sizee != 0){
        Node<T>* temp;
        Node<T>* node = head->next;
        while (node != nullptr)
        {
            temp = node;
            node = node->next;
            delete temp;
        }
       delete head;
       }
    }

    void push_front(const T& dataIn) {
        if (sizee == 0) {
            head = new Node<T>(dataIn);
            tail = head;
            sizee++;
        }
        else {
            Node<T>* newNode = new Node<T>(dataIn);
            Node<T>* oldHead = head;
            newNode->next = oldHead;
            oldHead->previous = newNode;
            head = newNode;
            sizee++;
        }

    }

    const T& front() const {
        return head->data;
    }

    void push_back(const T& dataIn) {
        if (sizee == 0) {
            tail = new Node<T>(dataIn);
            head = tail;
            sizee++;
        }
        else {
            Node<T>* newNode = new Node<T>(dataIn);
            Node<T>* oldTail = tail;
            newNode->previous = oldTail;
            oldTail->next = newNode;
            tail = newNode;
            sizee++;
        }
    }

    const T& back() {
        return tail->data;
    }

    int size() const {
        return sizee;
    }

    NodeIterator<T> begin() {

        NodeIterator<T> itr(head);

        return itr;
    }

    const NodeIterator<T> begin() const {

        NodeIterator<T> itr(head);

        return itr;
    }

    NodeIterator<T> end() {

        NodeIterator<T> itr(tail->next);
        return itr;
    }

    const NodeIterator<T> end() const {

        NodeIterator<T> itr(tail->next);
        return itr;
   }


    void reverse(){
       Node<T>* current = head;
       Node<T>* tone = nullptr;
       Node<T>* ttwo = nullptr;
       while (current != nullptr) {
           tone = current->previous;
           ttwo = current->next;
           current->next = tone;
           current->previous = ttwo;
           current = ttwo;
        }
       Node<T>* temp = head;
       head = tail;
       tail = temp;
    }

    NodeIterator<T> erase(NodeIterator<T> iterator){
        if(head == iterator.getPtrOfCurrent()){
            Node<T>* node = head;
            head = node->next;
            head->previous = nullptr;
            delete node;
            sizee--;
            return NodeIterator<T>(head);
        }else{
        Node<T>* node = iterator.getPtrOfCurrent();
        Node<T>* nextOne = node->next;
        nextOne->previous = node->previous;
        node->previous->next = nextOne;
        delete node;
        sizee--;
        return NodeIterator<T>(nextOne);
        }
    }

    NodeIterator<T> insert(NodeIterator<T> iterator, T takeIn){
        Node<T>* node = new Node<T>(takeIn);
        Node<T>* shouldBeNext = iterator.getPtrOfCurrent();
        node->previous = shouldBeNext->previous;
        node->next = shouldBeNext;
        node->previous->next = node;
        shouldBeNext->previous = node;
        sizee++;
        return NodeIterator<T>(node);
    }

};



// do not edit below this line

#endif