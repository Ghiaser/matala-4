//ghia48.serhan@gmail.com
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <QApplication>

template <typename T>
class tree {
private:
    struct Node {
        T key;
        std::vector<Node*> children;

        Node(T value, size_t max_children) : key(value), children(max_children, nullptr) {}
    };

    Node* root;
    size_t max_children;

public:
    std::vector<std::tuple<T, int>> toQtTree() const;

    tree(size_t k = 2) : root(nullptr), max_children(k) {}
    void print(int argc, char *argv[]) const;
    void add_root(const T& key);
    void add_sub_node(const T& parent_key, const T& child_key);

    class BFSIterator {
    public:
        BFSIterator(Node* root);
        bool operator!=(const BFSIterator& other) const;
        T& operator*() const;
        BFSIterator& operator++();

    private:
        std::queue<Node*> queue;
    };

    class DFSIterator {
    public:
        DFSIterator(Node* root);
        bool operator!=(const DFSIterator& other) const;
        T& operator*() const;
        DFSIterator& operator++();

    private:
        std::stack<Node*> stack;
    };

    class PreOrderIterator {
    public:
        PreOrderIterator(Node* root, size_t max_children);
        bool operator!=(const PreOrderIterator& other) const;
        T& operator*() const;
        PreOrderIterator& operator++();

    private:
        std::stack<Node*> stack;
        bool is_binary;
    };

    class PostOrderIterator {
    public:
        PostOrderIterator(Node* root, size_t max_children);
        bool operator!=(const PostOrderIterator& other) const;
        T& operator*() const;
        PostOrderIterator& operator++();

    private:
        std::stack<Node*> stack;
        std::stack<Node*> output;
        bool is_binary;
        void traverse(Node* node);
    };

    class InOrderIterator {
    public:
        InOrderIterator(Node* root, size_t max_children);
        bool operator!=(const InOrderIterator& other) const;
        T& operator*() const;
        InOrderIterator& operator++();

    private:
        std::stack<Node*> stack;
        Node* current;
        bool is_binary;
        void pushLeft(Node* node);
    };
    class MinHeapIterator {
    public:
        MinHeapIterator(Node* root);
        bool operator!=(const MinHeapIterator& other) const;
        T& operator*() const;
        MinHeapIterator& operator++();

    private:
        std::vector<Node*> heap;
        size_t current;
        void buildHeap(Node* node);
        void heapifyDown(size_t index);
    };

    MinHeapIterator begin_min_heap();
    MinHeapIterator end_min_heap();
    BFSIterator begin_bfs();
    BFSIterator end_bfs();
    DFSIterator begin_dfs();
    DFSIterator end_dfs();
    PreOrderIterator begin_preorder();
    PreOrderIterator end_preorder();
    PostOrderIterator begin_postorder();
    PostOrderIterator end_postorder();
    InOrderIterator begin_in_order();
    InOrderIterator end_in_order();
};
