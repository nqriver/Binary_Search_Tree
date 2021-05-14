#include "BinarySearchTree.h"


template<typename data_t>
void BinarySearchTree<data_t>::insert(const data_t &key) {
    _insert(key, _root);
}

template<typename data_t>
void BinarySearchTree<data_t>::remove(const data_t& key) {
    _remove(key, _root);
}

template<typename data_t>
void BinarySearchTree<data_t>::print(std::ostream& out) {
    _print(out, ">", _root, false);
}

template<typename data_t>
void BinarySearchTree<data_t>::traverse(std::function<void(data_t)> action) {
    _traverse(action, _root);
}

template<typename data_t>
bool BinarySearchTree<data_t>::empty() const {
    return (_root == nullptr);
}

template<typename data_t>
data_t BinarySearchTree<data_t>::maxElement() {
    return _maxElement(_root);
}

template<typename data_t>
data_t BinarySearchTree<data_t>::minElement() {
    return _minElement(_root);
}


template<typename data_t>
bool BinarySearchTree<data_t>::contains(const data_t& key) {
    return _contains(key, _root);
}

template<typename data_t>
template<typename InputIterator>
BinarySearchTree<data_t>::BinarySearchTree(InputIterator first, InputIterator last) {
    while(first != last){
        insert( *first );
        ++first;
    }
}
