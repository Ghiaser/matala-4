//ghia48.serhan@gmail.com
#include "Tree.cpp"
#include "TreeWidget.h"
#include <QApplication>

#include <cassert>
#include <iostream>
class Complex {
public:
    Complex(double real = 0.0, double imag = 0.0) : real_(real), imag_(imag) {}

    double real() const { return real_; }
    double imag() const { return imag_; }

    bool operator==(const Complex &other) const {
        return real_ == other.real_ && imag_ == other.imag_;
    }

    bool operator<(const Complex &other) const {
        return real_ < other.real_ || (real_ == other.real_ && imag_ < other.imag_);
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
        os << "(" << c.real_ << ", " << c.imag_ << ")";
        return os;
    }

private:
    double real_;
    double imag_;
};
void test_complex_tree(int argc, char *argv[]) {
    tree<Complex> complexTree;

    // Add the root and some children
    complexTree.add_root(Complex(1.0, 1.0));
    complexTree.add_sub_node(Complex(1.0, 1.0), Complex(2.0, 2.0));
    complexTree.add_sub_node(Complex(1.0, 1.0), Complex(3.0, 3.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(5.0, 5.0));
    complexTree.add_sub_node(Complex(3.0, 3.0), Complex(6.0, 6.0));
    complexTree.add_sub_node(Complex(3.0, 3.0), Complex(7.0, 7.0));

    // BFS test for complex tree
    std::vector<Complex> expected_bfs = {
        Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(3.0, 3.0),
        Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(6.0, 6.0),
        Complex(7.0, 7.0)};
    std::vector<Complex> actual_bfs;
    for (auto it = complexTree.begin_bfs(); it != complexTree.end_bfs(); ++it) {
        actual_bfs.push_back(*it);
    }
    assert(expected_bfs == actual_bfs);

    std::cout << "Complex Tree BFS: ";
    for (const auto &val : actual_bfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // DFS test for complex tree
    std::vector<Complex> expected_dfs = {
        Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(4.0, 4.0),
        Complex(5.0, 5.0), Complex(3.0, 3.0), Complex(6.0, 6.0),
        Complex(7.0, 7.0)};
    std::vector<Complex> actual_dfs;
    for (auto it = complexTree.begin_dfs(); it != complexTree.end_dfs(); ++it) {
        actual_dfs.push_back(*it);
    }
    assert(expected_dfs == actual_dfs);

    std::cout << "Complex Tree DFS: ";
    for (const auto &val : actual_dfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Pre-Order test for complex tree
    std::vector<Complex> expected_preorder = {
        Complex(1.0, 1.0), Complex(2.0, 2.0), Complex(4.0, 4.0),
        Complex(5.0, 5.0), Complex(3.0, 3.0), Complex(6.0, 6.0),
        Complex(7.0, 7.0)};
    std::vector<Complex> actual_preorder;
    for (auto it = complexTree.begin_preorder(); it != complexTree.end_preorder(); ++it) {
        actual_preorder.push_back(*it);
    }
    assert(expected_preorder == actual_preorder);

    std::cout << "Complex Tree Pre-Order: ";
    for (const auto &val : actual_preorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Post-Order test for complex tree
    std::vector<Complex> expected_postorder = {
        Complex(4.0, 4.0), Complex(5.0, 5.0), Complex(2.0, 2.0),
        Complex(6.0, 6.0), Complex(7.0, 7.0), Complex(3.0, 3.0),
        Complex(1.0, 1.0)};
    std::vector<Complex> actual_postorder;
    for (auto it = complexTree.begin_postorder(); it != complexTree.end_postorder(); ++it) {
        actual_postorder.push_back(*it);
    }
    assert(expected_postorder == actual_postorder);

    std::cout << "Complex Tree Post-Order: ";
    for (const auto &val : actual_postorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // In-Order test for complex tree
    std::vector<Complex> expected_inorder = {
        Complex(4.0, 4.0), Complex(2.0, 2.0), Complex(5.0, 5.0),
        Complex(1.0, 1.0), Complex(6.0, 6.0), Complex(3.0, 3.0),
        Complex(7.0, 7.0)};
    std::vector<Complex> actual_inorder;
    for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
        actual_inorder.push_back(*it);
    }
    assert(expected_inorder == actual_inorder);

    std::cout << "Complex Tree In-Order: ";
    for (const auto &val : actual_inorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
void test_binary_tree() {
    tree<int> binaryTree;

    // Add the root and some children
    binaryTree.add_root(1);
    binaryTree.add_sub_node(1, 2);
    binaryTree.add_sub_node(1, 3);
    binaryTree.add_sub_node(2, 4);
    binaryTree.add_sub_node(2, 5);
    binaryTree.add_sub_node(3, 6);
    binaryTree.add_sub_node(3, 7);

    // Print the binary tree
    std::cout << "Binary Tree:" << std::endl;
    // binaryTree.print();

    // BFS test for binary tree
    std::vector<int> expected_bfs = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> actual_bfs;
    for (auto it = binaryTree.begin_bfs(); it != binaryTree.end_bfs(); ++it) {
        actual_bfs.push_back(*it);
    }
    assert(expected_bfs == actual_bfs);

    std::cout << "Binary Tree BFS: ";
    for (const auto &val : actual_bfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // DFS test for binary tree
    std::vector<int> expected_dfs = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> actual_dfs;
    for (auto it = binaryTree.begin_dfs(); it != binaryTree.end_dfs(); ++it) {
        actual_dfs.push_back(*it);
    }
    assert(expected_dfs == actual_dfs);

    std::cout << "Binary Tree DFS: ";
    for (const auto &val : actual_dfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Pre-Order test for binary tree
    std::vector<int> expected_preorder = {1, 2, 4, 5, 3, 6, 7};
    std::vector<int> actual_preorder;
    for (auto it = binaryTree.begin_preorder(); it != binaryTree.end_preorder(); ++it) {
        actual_preorder.push_back(*it);
    }
    assert(expected_preorder == actual_preorder);

    std::cout << "Binary Tree Pre-Order: ";
    for (const auto &val : actual_preorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Post-Order test for binary tree
    std::vector<int> expected_postorder = {4, 5, 2, 6, 7, 3, 1};
    std::vector<int> actual_postorder;
    for (auto it = binaryTree.begin_postorder(); it != binaryTree.end_postorder(); ++it) {
        actual_postorder.push_back(*it);
    }
    assert(expected_postorder == actual_postorder);

    std::cout << "Binary Tree Post-Order: ";
    for (const auto &val : actual_postorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // In-Order test for binary tree
    std::vector<int> expected_inorder = {4, 2, 5, 1, 6, 3, 7};
    std::vector<int> actual_inorder;
    for (auto it = binaryTree.begin_in_order(); it != binaryTree.end_in_order(); ++it) {
        actual_inorder.push_back(*it);
    }
    assert(expected_inorder == actual_inorder);

    std::cout << "Binary Tree In-Order: ";
    for (const auto &val : actual_inorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void test_ternary_tree() {
    tree<int> ternaryTree(3); // specify a 3-ary tree

    // Add the root and some children
    ternaryTree.add_root(1);
    ternaryTree.add_sub_node(1, 2);
    ternaryTree.add_sub_node(1, 3);
    ternaryTree.add_sub_node(1, 4);
    ternaryTree.add_sub_node(2, 5);
    ternaryTree.add_sub_node(2, 6);
    ternaryTree.add_sub_node(3, 7);
    ternaryTree.add_sub_node(3, 8);
    ternaryTree.add_sub_node(4, 9);

    // Print the ternary tree
    std::cout << "Ternary Tree:" << std::endl;
    // ternaryTree.print();

    // BFS test for ternary tree
    std::vector<int> expected_bfs = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> actual_bfs;
    for (auto it = ternaryTree.begin_bfs(); it != ternaryTree.end_bfs(); ++it) {
        actual_bfs.push_back(*it);
    }
    assert(expected_bfs == actual_bfs);

    std::cout << "Ternary Tree BFS: ";
    for (const auto &val : actual_bfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // DFS test for ternary tree
    std::vector<int> expected_dfs = {1, 2, 5, 6, 3, 7, 8, 4, 9};
    std::vector<int> actual_dfs;
    for (auto it = ternaryTree.begin_dfs(); it != ternaryTree.end_dfs(); ++it) {
        actual_dfs.push_back(*it);
    }
    assert(expected_dfs == actual_dfs);

    std::cout << "Ternary Tree DFS: ";
    for (const auto &val : actual_dfs) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Pre-Order test for ternary tree (should be the same as DFS)
    std::vector<int> expected_preorder = {1, 2, 5, 6, 3, 7, 8, 4, 9};
    std::vector<int> actual_preorder;
    for (auto it = ternaryTree.begin_preorder(); it != ternaryTree.end_preorder(); ++it) {
        actual_preorder.push_back(*it);
    }
    for (auto i : actual_preorder) {
        std::cout << i << " ";
    }
    assert(expected_preorder == actual_preorder);

    std::cout << "Ternary Tree Pre-Order (DFS): ";
    for (const auto &val : actual_preorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Post-Order test for ternary tree (should be the same as DFS)
    std::vector<int> expected_postorder = {1, 2, 5, 6, 3, 7, 8, 4, 9};
    std::vector<int> actual_postorder;
    for (auto it = ternaryTree.begin_postorder(); it != ternaryTree.end_postorder(); ++it) {
        actual_postorder.push_back(*it);
    }
    assert(expected_postorder == actual_postorder);

    std::cout << "Ternary Tree Post-Order (DFS): ";
    for (const auto &val : actual_postorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // In-Order test for ternary tree (should be the same as DFS)
    std::vector<int> expected_inorder = {1, 2, 5, 6, 3, 7, 8, 4, 9};
    std::vector<int> actual_inorder;
    for (auto it = ternaryTree.begin_in_order(); it != ternaryTree.end_in_order(); ++it) {
        actual_inorder.push_back(*it);
    }
    assert(expected_inorder == actual_inorder);

    std::cout << "Ternary Tree In-Order (DFS): ";
    for (const auto &val : actual_inorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
void test_binary_tree_heap_iterator() {
    // Test case 1
    tree<int> binaryTree1;

    // Add the root and some children
    binaryTree1.add_root(4);
    binaryTree1.add_sub_node(4, 2);
    binaryTree1.add_sub_node(4, 6);
    binaryTree1.add_sub_node(2, 1);

    // Print the binary tree
    std::cout << "Binary Tree 1:" << std::endl;
    // binaryTree1.print();

    // Min Heap test for binary tree 1
    std::vector<int> expected_min_heap1 = {1, 2, 6, 4};
    std::vector<int> actual_min_heap1;
    for (auto it = binaryTree1.begin_min_heap(); it != binaryTree1.end_min_heap(); ++it) {
        actual_min_heap1.push_back(*it);
        std::cout << *it << " ";
    }
    assert(expected_min_heap1 == actual_min_heap1);

    std::cout << "Binary Tree 1 Min Heap: ";
    for (const auto &val : actual_min_heap1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Test case 2
    tree<int> binaryTree2;

    // Add the root and some children
    binaryTree2.add_root(8);
    binaryTree2.add_sub_node(8, 5);
    binaryTree2.add_sub_node(8, 10);
    binaryTree2.add_sub_node(5, 3);
    binaryTree2.add_sub_node(5, 7);
    binaryTree2.add_sub_node(10, 9);
    binaryTree2.add_sub_node(10, 12);

    // Print the binary tree
    std::cout << "Binary Tree 2:" << std::endl;
    // binaryTree2.print();

    // Min Heap test for binary tree 2
    std::vector<int> expected_min_heap2 = {3, 5, 9, 8, 7, 10, 12};
    std::vector<int> actual_min_heap2;
    for (auto it = binaryTree2.begin_min_heap(); it != binaryTree2.end_min_heap(); ++it) {
        actual_min_heap2.push_back(*it);
        std::cout << *it << " ";
    }
    assert(expected_min_heap2 == actual_min_heap2);

    std::cout << "Binary Tree 2 Min Heap: ";
    for (const auto &val : actual_min_heap2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    test_binary_tree();
    test_ternary_tree();
    test_binary_tree_heap_iterator();
    tree<int> binaryTree;
    binaryTree.add_root(1);
    binaryTree.add_sub_node(1, 2);
    binaryTree.add_sub_node(1, 3);
    binaryTree.add_sub_node(2, 4);
    binaryTree.add_sub_node(2, 5);
    binaryTree.add_sub_node(3, 6);
    binaryTree.add_sub_node(3, 7);

    binaryTree.print(argc, argv);
    test_complex_tree(argc, argv);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
