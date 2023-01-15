#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

//TODO your code for the TreeNode class goes here:
template<typename T>
class TreeNode{
    public:
    T data;
    unique_ptr<TreeNode<T>> leftChild;
    unique_ptr<TreeNode<T>> rightChild;
    TreeNode<T>* parent;
    
    public:
    TreeNode(const T & dataIn)
    :data(dataIn){
        
        parent = nullptr;

    }


    void setLeftChild(TreeNode<T>* child){
        leftChild.reset(child);
        leftChild->parent = this;
    }

    void setRightChild(TreeNode<T>* child){
        rightChild.reset(child);
        rightChild->parent = this;
    }

    TreeNode<T>* find(const T & dataIn){
        if (dataIn < data) {
            if (leftChild) {
                return leftChild->find(dataIn);
            }
        }else if(data < dataIn) {
            if (rightChild) {
                return rightChild->find(dataIn);
            }
        }else{
            return this;
        }
        return nullptr;
        
    }
    
    TreeNode<T>* insert(const T & dataIn){
        if (dataIn < data) {
            if (leftChild) {
                return leftChild->insert(dataIn);
            } else {
                leftChild.reset(new TreeNode<T>(dataIn));
                leftChild->parent = this;
                return leftChild.get();
            }
        }else if(data < dataIn) {
            if (rightChild) {
                return rightChild->insert(dataIn);
            } else {
                rightChild.reset(new TreeNode<T>(dataIn));
                rightChild->parent = this;
                return rightChild.get();
            }
        }else{
            return this;
        }
    }

    void write(ostream & o) const {
        
        if (leftChild){
            leftChild->write(o);
        }
        o <<" "<< data << " ";
        if (rightChild) {
            rightChild->write(o);
        }
   
}
    void copy(TreeNode<T>* newNode) const {
    
    if(leftChild){
         TreeNode<T>* newChild = new TreeNode<T>(leftChild->data);
         newNode->setLeftChild(newChild);
         leftChild->copy(newNode->leftChild.get());
         
     }
     if(rightChild){
         TreeNode<T>* newChild = new TreeNode<T>(rightChild->data);
         newNode->setRightChild(newChild);
         rightChild->copy(newNode->rightChild.get());
         }
}   
    TreeNode<T>* leftMost(){
        if(this == nullptr){
            return nullptr;
        }
        if(leftChild){
               return leftChild->leftMost();
        }
        
        return this;
        } 

    TreeNode<T>* rightMost(){
        if(this == nullptr){
            return nullptr;
        }
        if(rightChild){
               return rightChild->rightMost();
        }
        
        return this->rightChild.get();
        }    

};

template<typename T>
class TreeNodeIterator{

private:
TreeNode<T>* current;


public:
TreeNodeIterator(TreeNode<T>* nodeIn)
:current(nodeIn){}


T & operator*() {
        return current->data;
    }



bool operator==(const TreeNodeIterator<T> & other) const {
            return (current == other.current);
        }

bool operator!=(const TreeNodeIterator<T> & other) const {
            return (current != other.current);
        }

void operator++(){
    if(current->rightChild != nullptr){
        TreeNode<T>* Child = current->rightChild.get();
        while(Child->leftChild != nullptr){
            Child = Child->leftChild.get();}
        current = Child;
        
    }else{
    TreeNode<T>* Child = current;
    TreeNode<T>* nowParent = current->parent;
    while(nowParent != nullptr && Child == nowParent->rightChild.get()){
            Child = nowParent;
           nowParent = nowParent->parent;
        }
        current = nowParent;
    }
}


};



#endif
