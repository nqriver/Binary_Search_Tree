#ifndef BINARY_SEARCH_TREE_BINARYTREE_H
#define BINARY_SEARCH_TREE_BINARYTREE_H

#include <memory>
#include <iostream>
#include <functional>
#include <exception>

template <typename data_t>
class BinarySearchTree {

public:
    BinarySearchTree() = default;
    template<typename InputIterator>
    BinarySearchTree(InputIterator first, InputIterator last);

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator =(const BinarySearchTree&) = delete;

    BinarySearchTree(BinarySearchTree&&) noexcept;
    BinarySearchTree& operator =(BinarySearchTree&&) noexcept;


    bool empty() const;
    void clear();
    void insert(const data_t& key);
//    void insert(data_t&& key);
    void remove(const data_t& key);
    void remove(const data_t&& key);
    bool contains(const data_t& key);

    void traverse(std::function<void(data_t)> action);
    void print(std::ostream& out = std::cout);

    std::size_t depth();
    data_t maxElement();
    data_t minElement();

private:
    struct Node{
        data_t data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    std::unique_ptr<Node> _root;

//private helper functions
    void _insert(const data_t& data, std::unique_ptr<Node>& node) {
        if (!node){
            node.reset( new Node{ data } );
            return;
        }
        else if (data > node->data){
            _insert(data, node->right);
        }
        else if (data < node->data){
            _insert(data, node->left);
        }
    }

    void _insert(const data_t&& data, std::unique_ptr<Node>& node) {
        if (!node){
            node.reset( new Node{ data } );
            return;
        }
        _insert( std::forward<data_t>(data),
                data > node->data ? node->right : node->left
                );
    }

    void _remove(const data_t& key, std::unique_ptr<Node>& node) {
        if (!node) {
            throw std::invalid_argument("In remove function: value not found");
        }
        else if (key > node->data) {
            _remove(key, node->right);
        }
        else if (key < node->data) {
            _remove(key, node->left);
        }
        else {      //found node matching to key
            if (node->left == nullptr && node->right == nullptr) {
                node.reset();
            }
            else if (node->left == nullptr){
                auto& temp { node->right };
                node.reset( temp.release() );
            }
            else if (node->right == nullptr){
                auto& temp { node->left };
                node.reset( temp.release() );
            }
            else {
                auto min { _minElement(node->right) };
                node->data = min;
                _remove(min, node->right);
            }
        }
    }

    void _remove(const data_t&& key, std::unique_ptr<Node>& node) {
        if (!node) {
            throw std::invalid_argument("In remove function: value not found");
        }
        else if (key > node->data) {
            _remove(std::forward<data_t>(key), node->right);
        }
        else if (key < node->data) {
            _remove(std::forward<data_t>(key), node->left);
        }
        else {      //found node matching to key
            if (node->left == nullptr && node->right == nullptr) {
                node.reset();
            }
            else if (node->left == nullptr){
                auto& temp { node->right };
                node.reset( temp.release() );
            }
            else if (node->right == nullptr){
                auto& temp { node->left };
                node.reset( temp.release() );
            }
            else {
                auto min { _minElement(node->right) };
                node->data = min;
                _remove(std::forward<data_t>(min), node->right);
            }
        }
    }

    data_t _maxElement(std::unique_ptr<Node>& node) {
        if (!node){
            throw std::runtime_error("In maxElement function: Container is empty.");
        }
        return ( node->right == nullptr ? node->data : _maxElement(node->right) );
    }

    data_t _minElement(std::unique_ptr<Node>& node) {
        if (!node) {
            throw std::runtime_error("In min element function: Container is empty.");
        }
        return ( node->left == nullptr ? node->data : _minElement(node->left) );
    }

    bool _contains(const data_t& key, std::unique_ptr<Node>& node) {
        if (!node){
            return false;
        }
        else if (node->data == key){
            return true;
        }
        return ( key > node->data ? _contains(key, node->right) : _contains(key, node->left) );
    }

    void _clear(std::unique_ptr<Node>& node){
        if (!node) return;
        _clear(node->left);
        _clear(node->right);
        node.reset(nullptr);
    }

    std::size_t _depth(std::unique_ptr<Node>& node) {
        if (!node){
            return 0;
        }
        return ( std::max(_depth(node->left), _depth(node->right)) + 1 );
    }

    void _traverse(std::function<void(data_t)> action, std::unique_ptr<Node>& node) {
        if (node == nullptr)
            return;
        _traverse(action, node->left);
        action(node->data);
        _traverse(action, node->right);
    }

    void _print(std::ostream& out, const std::string& prefix, std::unique_ptr<Node>& node, bool isLeft) {
        if (node != nullptr) {
            out << prefix;
            out << (isLeft ? "├──" : "└──" );
            // print the value of the node
            out << node->data << std::endl;
            // enter the next tree level - left and right branch
            _print(out, prefix + (isLeft ? "|   " : "    "), node->left, true);
            _print(out, prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }
};

#include "BinarySearchTree.tpp"

#endif //BINARY_SEARCH_TREE_BINARYTREE_H