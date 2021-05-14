#include <iostream>
#include "BinarySearchTree.h"
#include <clocale>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    srand(time(nullptr));


    BinarySearchTree<int> tree;

    for (int k{ 0 }; k < 20; ++k){
        auto randInt { std::rand()%100 };
        tree.insert(randInt);
    }

    tree.traverse([](const auto& elem) { std::cout << elem << '\t';} );

    tree.printToFile("tree1.txt");
    std::cout << std::endl;
    tree.print();
    int val;
    std::cout << "Enter element to remove:\n";
    std::cin>>val;
    tree.remove(val);
    std::cout << std::endl;
    tree.print();
    std::cout << '\n' << tree.maxElement();
    return 0;
}