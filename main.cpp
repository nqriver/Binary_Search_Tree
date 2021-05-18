#include "BinarySearchTree.h"
#include <fstream>
#include <random>


int main() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distrib(1,1000);

    BinarySearchTree<int> tree;
    for (auto count { 0 }; count < 300; ++count){
        tree.insert(distrib(rng));
    }

    std::ofstream graphics_tree{ "tree.txt" };
    graphics_tree << "MAX DEPTH: " << tree.depth() << "\n\n";
    tree.print(graphics_tree);
    return 0;
}