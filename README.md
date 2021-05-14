# Binary Search Tree
Node-based binary tree data structure which follows undermentioned properties:
* The left subtree of a node contains only nodes with keys logically lesser than the node’s key.
* The right subtree of a node contains only nodes with keys logically greater than the node’s key.
* Both the left and right subtree satisfies above conditions (are trees).

Read more details: 	[wiki](https://en.wikipedia.org/wiki/Binary_search_tree)

## Usage
Usage example:
```c++
    std::array<std::string, 5> arr {"Tom", "Rob", "Ann", "John", "Shaun"};
    BinarySearchTree<std::string> tree_str(arr.begin(), arr.end()); ///STL container initialization.

    tree_str.traverse([](auto str){ std::cout << str << '\t';} ); ///traversing the inordered tree with std::funtion. Prints the elements in ascending order.

    tree_str.remove(arr[0]); ///removes single element specified in parameter

    auto min { tree.minElement() }; ///returns minimum element
    auto max { tree.maxElement() };

    std::ofstream out_tree{ "tree.txt" };
    tree.print(out_tree); ///saves display of tree in human-readable format to file
    tree.print(); ///displays tree in human-readable format on standard console output


    tree.clear(); ///clears all the nodes and sets them to point nullptr
    auto empty { tree.empty() }; ///returns true if container is empty
```
