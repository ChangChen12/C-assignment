#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {

public:

    const Key k;
    Value v;

    // TODO your code for KeyValuePair goes here
public:
    KeyValuePair(const Key& keyIn, const Value& ValueIn)
        :k(keyIn), v(ValueIn) {}

    KeyValuePair(const Key& keyIn)
        :k(keyIn) {}

    bool operator<(const KeyValuePair<Key, Value>& kv) const {
        return k < kv.k;
    }


};



template<typename Key, typename Value>
ostream& operator<< (ostream& o, const KeyValuePair<Key, Value>& kv) {
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {

private:
    BinarySearchTree<KeyValuePair<Key, Value> > tree;

public:

    KeyValuePair<Key, Value>* insert(const Key& k, const Value& v) {
        return &(tree.insert(KeyValuePair<Key, Value>(k, v))->data);
    }

    void write(ostream& o) const {
        tree.write(o);
    }

    KeyValuePair<Key, Value>* find(const Key& k) {
        if(tree.find(KeyValuePair<Key, Value>(k)) == nullptr){
            return nullptr;
        }
        return &(tree.find(KeyValuePair<Key, Value>(k))->data);
    }

    // TODO your code for TreeMap goes here:




};


// do not edit below this line

#endif
