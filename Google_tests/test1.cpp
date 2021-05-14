#include "gtest/gtest.h"
#include "../BinarySearchTree.h"

#include <vector>
#include <array>
#include <map>

TEST(BST_test, VectorInitialization) {
    auto vec = std::vector<float> { 11.9, 12.3, 14.66, 1.101 };
    BinarySearchTree<float> tree(vec.begin(), vec.end());
    EXPECT_EQ (static_cast<float>(1.101), tree.minElement());
    EXPECT_EQ (static_cast<float>(14.66), tree.maxElement());
    EXPECT_EQ (false, tree.empty());
    tree.clear();
    EXPECT_EQ (true, tree.empty());
}

TEST (SquareRootTest, ArrayInitialization) {
    std::array strs {"In", "Out", "Back", "Behind", "Underneath", "Alongside", "Up", "Front"};
    BinarySearchTree<std::string> tree_str(strs.begin(), strs.end());
    ASSERT_EQ(true, tree_str.contains("In"));
    tree_str.remove("In");
    ASSERT_EQ(false, tree_str.contains("In"));
    ASSERT_EQ ("Alongside", tree_str.minElement());
    ASSERT_EQ(true, tree_str.contains("Behind"));
}



int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

