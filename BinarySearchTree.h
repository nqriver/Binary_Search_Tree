#ifndef BINARY_SEARCH_TREE_BINARYTREE_H
#define BINARY_SEARCH_TREE_BINARYTREE_H

#include <memory>
#include <iostream>
#include <fstream>
#include <functional>

template <typename data_t>
class BinarySearchTree {

private:
    struct Node{
        data_t data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    std::unique_ptr<Node> _root;
    void _insert(const data_t& data, std::unique_ptr<Node>& node){
        if (node == nullptr){
            node.reset( new Node{ data } );
        }
        else if (data > node->data){
            _insert(data, node->right);
        }
        else if (data < node->data){
            _insert(data, node->left);
        }
    }

    data_t _maxElement(std::unique_ptr<Node>& node){
        if (node && node->right == nullptr) return node->data;
        else return _maxElement(node->right);
    }

    data_t _minElement(std::unique_ptr<Node>& node){
        if (node && node->left == nullptr) return node->data;
        else return _minElement(node->left);
    }

    void _remove(const data_t& key, std::unique_ptr<Node>& node){
        if (node == nullptr) {
            return;
        }
        else if (key > node->data) {
            _remove(key, node->right);
        }
        else if (key < node->data) {
            _remove(key, node->left);
        }
        else {      //found node matching to key
            if (node->left == nullptr && node->right == nullptr){
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

    bool _contains(const data_t& key, std::unique_ptr<Node>& node){
        if (!node){
            return false;
        }
        else if (node->data == key){
            return true;
        }
        return ( key > node->data ? _contains(key, node->right) : _contains(key, node->left) );
    }

    void _traverse(std::function<void(data_t)> action, std::unique_ptr<Node>& node) {
        if (node == nullptr)
            return;
        _traverse(action, node->left);
        action(node->data);
        _traverse(action, node->right);
    }

    void _print(std::ostream& out, const std::string& prefix, std::unique_ptr<Node>& node, bool isLeft)
    {
        if (node != nullptr)
        {
            out << prefix;

            out << (isLeft ? "├──" : "└──" );

            // print the value of the node
            out << node->data << std::endl;

            // enter the next tree level - left and right branch
            _print(out, prefix + (isLeft ? "|   " : "    "), node->left, true);
            _print(out, prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }



public:
    BinarySearchTree() = default;
    BinarySearchTree(const BinarySearchTree &) = delete;
    BinarySearchTree& operator =(const BinarySearchTree&) = delete;

    bool empty() const;
    void insert(const data_t& key);
    void remove(const data_t& key);
    bool contains(const data_t& key);

    void traverse(std::function<void(data_t)> action);

    void print();
    void printToFile(const std::string& name);

    data_t maxElement();
    data_t minElement();
};

#include "BinarySearchTree.tpp"

#endif //BINARY_SEARCH_TREE_BINARYTREE_H