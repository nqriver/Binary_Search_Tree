#include "gtest/gtest.h"
#include "../BinarySearchTree.h"

#include <vector>
#include <array>
#include <algorithm>

TEST(BST_test, VectorInitialization) {
    auto vec = std::vector<float> { 11.9, 12.3, 14.66, 1.101 };
    BinarySearchTree<float> tree(vec.begin(), vec.end());
    EXPECT_EQ (static_cast<float>(1.101), tree.minElement());
    EXPECT_EQ (static_cast<float>(14.66), tree.maxElement());
    EXPECT_FALSE(tree.empty());
    tree.clear();
    EXPECT_TRUE (tree.empty());
}


TEST (BST_test, ArrayInitialization) {
    std::array str_representation{"In", "Out", "Back", "Behind", "Underneath", "Alongside", "Up", "Front"};
    BinarySearchTree<std::string> tree_str(str_representation.begin(), str_representation.end());
    ASSERT_TRUE(tree_str.contains("In"));
    tree_str.remove("In");
    ASSERT_FALSE(tree_str.contains("In"));
    ASSERT_EQ ("Alongside", tree_str.minElement());
    ASSERT_TRUE(tree_str.contains("Behind"));
}

TEST (BST_test, Manipulators) {
    std::vector<int> numbers {12, 32, 41, 124, 1, 11, 15, 1421, 124, 145, 140, 199, 121, 10};
    BinarySearchTree<int> int_tree;
    for (auto number : numbers){
        int_tree.insert(number);
    }
    std::sort(numbers.begin(), numbers.end());
    numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end()); //removes duplicates

    EXPECT_EQ(*numbers.begin(), int_tree.minElement());
    EXPECT_EQ(*std::prev(numbers.end()), int_tree.maxElement());
    decltype(numbers) sorted_tree;
    int_tree.traverse([&](auto tree_element){ sorted_tree.push_back(tree_element); });
    EXPECT_TRUE(std::equal(numbers.begin(), numbers.end(), sorted_tree.begin(), sorted_tree.end()) );
    int_tree.clear();
    EXPECT_TRUE(int_tree.empty());
    EXPECT_ANY_THROW(int_tree.maxElement());
    EXPECT_ANY_THROW(int_tree.remove( numbers[0] ));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

