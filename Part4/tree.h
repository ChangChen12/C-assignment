#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree{
    private:
    unique_ptr<TreeNode<T>> root;

    public:
    BinarySearchTree(){}

    BinarySearchTree(const BinarySearchTree<T> & other){
        TreeNode<T>* getRoot = other.copy();
        root.reset(getRoot);
    }

    


    void write(ostream & oIn) const{
        
        root->write(oIn);
    }

    TreeNode<T>* insert(const T& valueIn) {
        if (root) {
            TreeNode<T>* node = root->insert(valueIn);
            TreeNode<T>* oneparent = node->parent;
            TreeNode<T>* grandParent = oneparent->parent;
            if (grandParent != nullptr) {
                int balance = getBalanceFactor(grandParent);
                if (balance == 2 || balance == -2) {
                    if (oneparent->leftChild == nullptr && grandParent->leftChild == nullptr) {
                        return leftRotation(grandParent);
                    }else if(oneparent->rightChild == nullptr && grandParent->rightChild == nullptr) {
                        return rightRotation(grandParent);
                    }else if(grandParent->leftChild != nullptr && oneparent->rightChild != nullptr) {
                        TreeNode<T>* putIn = leftRotation(oneparent);
                        return rightRotation(putIn->parent);
                         
                    }else{
                        TreeNode<T>* putIn = rightRotation(oneparent);
                        return leftRotation(putIn->parent);
                    }

                }

            }
           
        }
        else {
            root.reset(new TreeNode<T>(valueIn));
            return root.get();
        }
        return nullptr;

    }

    TreeNode<T>* find(const T & valueIn){
        if(root&&root->data < valueIn == false&&valueIn < root->data == false){
            return root.get();
        }
        else{
            return root->find(valueIn);
        }
        
    }
    
     TreeNode<T>* leftRotation(TreeNode<T>* node) {
        TreeNode<T>* temp = node->parent;
        TreeNode<T>* right = node->rightChild.get();
        right->parent = temp;
        node->parent = nullptr;
        node->leftChild.release();
        node->rightChild.release();
        right->leftChild.reset(node);
        node->parent = right;
        
        if (temp != nullptr) {
            if (temp->rightChild.get() == node) {
                temp->rightChild.release();
                temp->rightChild.reset(right);
            }
            else {
                temp->leftChild.release();
                temp->leftChild.reset(right);
            }
        }
        else {
            root.release();
            root.reset(right);
        }
        return right;

    }

    TreeNode<T>* rightRotation(TreeNode<T>* node) {
        TreeNode<T>* temp = node->parent;
        TreeNode<T>* left = node->leftChild.get();
        left->parent = temp;
        node->parent = nullptr;
        node->leftChild.release();
        node->rightChild.release();
        left->rightChild.reset(node);
        node->parent = left;

        if (temp != nullptr) {
            if (temp->rightChild.get() == node) {
                temp->rightChild.release();
                temp->rightChild.reset(left);
            }
            else {
                temp->leftChild.release();
                temp->leftChild.reset(left);
            }
        }
        else {
            root.release();
            root.reset(left);
        }
        
        return left;

    }

    TreeNode<T>* copy() const {
        if (root) {
            TreeNode<T>* node = new TreeNode<T>(root->data);
            root->copy(node);
            return node;
        }
        else {
            return nullptr;
        }
    }

    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& copyIn){
        
        root.reset(nullptr);
                TreeNode<T>* copyRoot = copyIn.copy();
                root.reset(copyRoot);
          
            return *this;
        }

     TreeNodeIterator<T> begin() {
        TreeNode<T>* left = root->leftMost();
        TreeNodeIterator<T> itr(left);
        return itr;
    }

     TreeNodeIterator<T> end() {
        TreeNode<T>* right = root->rightMost();
        TreeNodeIterator<T> itr(nullptr);
        return itr;
    }

    int maxDepth(TreeNode<T>* node){
    if(node == nullptr){
        return 0;
    }
    int left = maxDepth(node->leftChild.get());
    int right = maxDepth(node->rightChild.get());
    if(left>right){
        return left+1;
    }else{
        return right+1;
    }
    
}

    int maxDepth(){
        int max = maxDepth(root.get());
        return max;
    }

    int getBalanceFactor(TreeNode<T>* node) {
        int balanceFactor = 0;
        balanceFactor = maxDepth(node->rightChild.get()) - maxDepth(node->leftChild.get());
        return balanceFactor;
    }

    
    

};



// do not edit below this line

#endif
