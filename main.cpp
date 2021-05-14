#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include <clocale>
#include <ctime>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);
    srand(time(nullptr));


    std::vector<int> vec { 1,23,4,5 };
    BinarySearchTree<int> tree(vec.begin(), vec.end());
    tree.print();

    BinarySearchTree<float> treeFloat;
    try {
        treeFloat.maxElement();
    }
    catch (const std::exception& exc){
        std::cerr << exc.what();
    }

    for (int k{ 0 }; k < 20; ++k){
        auto randInt { std::rand()%100 };
        tree.insert(randInt);
    }

    tree.traverse([](const auto& elem) { std::cout << elem << '\t';} );

    std::ofstream out{"tree1.txt"};
    tree.print(out);
    std::cout << std::endl;
    tree.print();
    int val;
    std::cout << "Enter element to remove:\n";
    std::cin>>val;
    tree.remove(val);
    std::cout << std::endl;
    tree.print();
    std::cout << '\n' << tree.maxElement();

    tree.clear();
    tree.insert(2);
    tree.print();
    std::cout << std::boolalpha << tree.empty();
    std::cout << std::boolalpha << tree.empty();
    return 0;
}