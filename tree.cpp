//ghia48.serhan@gmail.com
#include "tree.h"
#include "TreeWidget.h"
#include <QApplication>

// Add the root node to the tree
template <typename T>
void tree<T>::add_root(const T& key) {
    root = new Node(key, max_children);
}

// Add a child to a parent node
template <typename T>
void tree<T>::add_sub_node(const T& parent_key, const T& child_key) {
    if (!root) throw std::runtime_error("Root not set");

    std::queue<Node*> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();

        if (current->key == parent_key) {
            for (size_t i = 0; i < max_children; ++i) {
                if (!current->children[i]) {
                    current->children[i] = new Node(child_key, max_children);
                    return;
                }
            }
            throw std::runtime_error("Maximum children exceeded");
        }

        for (Node* child : current->children) {
            if (child) queue.push(child);
        }
    }

    throw std::runtime_error("Parent not found");
}

// BFS Iterator
template <typename T>
tree<T>::BFSIterator::BFSIterator(Node* root) {
    if (root) queue.push(root);
}

template <typename T>
bool tree<T>::BFSIterator::operator!=(const BFSIterator& other) const {
    return !queue.empty();
}

template <typename T>
T& tree<T>::BFSIterator::operator*() const {
    return queue.front()->key;
}

template <typename T>
typename tree<T>::BFSIterator& tree<T>::BFSIterator::operator++() {
    Node* current = queue.front();
    queue.pop();

    for (Node* child : current->children) {
        if (child) queue.push(child);
    }

    return *this;
}

template <typename T>
typename tree<T>::BFSIterator tree<T>::begin_bfs() {
    return BFSIterator(root);
}

template <typename T>
typename tree<T>::BFSIterator tree<T>::end_bfs() {
    return BFSIterator(nullptr);
}

// DFS Iterator
template <typename T>
tree<T>::DFSIterator::DFSIterator(Node* root) {
    if (root) stack.push(root);
}

template <typename T>
bool tree<T>::DFSIterator::operator!=(const DFSIterator& other) const {
    return !stack.empty();
}

template <typename T>
T& tree<T>::DFSIterator::operator*() const {
    return stack.top()->key;
}

template <typename T>
typename tree<T>::DFSIterator& tree<T>::DFSIterator::operator++() {
    Node* current = stack.top();
    stack.pop();

    for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
        if (*it) stack.push(*it);
    }

    return *this;
}

template <typename T>
typename tree<T>::DFSIterator tree<T>::begin_dfs() {
    return DFSIterator(root);
}

template <typename T>
typename tree<T>::DFSIterator tree<T>::end_dfs() {
    return DFSIterator(nullptr);
}

// Pre-Order Iterator
template <typename T>
tree<T>::PreOrderIterator::PreOrderIterator(Node* root, size_t max_children) {
    if (root) stack.push(root);
    is_binary = (max_children == 2);
}

template <typename T>
bool tree<T>::PreOrderIterator::operator!=(const PreOrderIterator& other) const {
    return !stack.empty();
}

template <typename T>
T& tree<T>::PreOrderIterator::operator*() const {
    return stack.top()->key;
}

template <typename T>
typename tree<T>::PreOrderIterator& tree<T>::PreOrderIterator::operator++() {
    Node* current = stack.top();
    stack.pop();

    if (is_binary) {
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it) stack.push(*it);
        }
    } else {
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it) stack.push(*it);
        }
    }

    return *this;
}

template <typename T>
typename tree<T>::PreOrderIterator tree<T>::begin_preorder() {
    return PreOrderIterator(root, max_children);
}

template <typename T>
typename tree<T>::PreOrderIterator tree<T>::end_preorder() {
    return PreOrderIterator(nullptr, max_children);
}

// Post-Order Iterator
template <typename T>
void tree<T>::PostOrderIterator::traverse(Node* node) {
    if (!node) return;
    stack.push(node);
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        output.push(current);
        for (Node* child : current->children) {
            if (child) stack.push(child);
        }
    }
}

template <typename T>
tree<T>::PostOrderIterator::PostOrderIterator(Node* root, size_t max_children) {
    is_binary = (max_children == 2);
    if (root) {
        if (is_binary) {
            traverse(root);
        } else {
            stack.push(root);
        }
    }
}

template <typename T>
bool tree<T>::PostOrderIterator::operator!=(const PostOrderIterator& other) const {
    return is_binary ? !output.empty() : !stack.empty();
}

template <typename T>
T& tree<T>::PostOrderIterator::operator*() const {
    return is_binary ? output.top()->key : stack.top()->key;
}

template <typename T>
typename tree<T>::PostOrderIterator& tree<T>::PostOrderIterator::operator++() {
    if (is_binary) {
        output.pop();
    } else {
        Node* current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it) stack.push(*it);
        }
    }
    return *this;
}

template <typename T>
typename tree<T>::PostOrderIterator tree<T>::begin_postorder() {
    return PostOrderIterator(root, max_children);
}

template <typename T>
typename tree<T>::PostOrderIterator tree<T>::end_postorder() {
    return PostOrderIterator(nullptr, max_children);
}

// In-Order Iterator
template <typename T>
void tree<T>::InOrderIterator::pushLeft(Node* node) {
    while (node) {
        stack.push(node);
        node = node->children[0];
    }
}

template <typename T>
tree<T>::InOrderIterator::InOrderIterator(Node* root, size_t max_children) : current(root) {
    is_binary = (max_children == 2);
    if (is_binary) {
        pushLeft(current);
    } else {
        if (current) stack.push(current);
    }
}

template <typename T>
bool tree<T>::InOrderIterator::operator!=(const InOrderIterator& other) const {
    return !stack.empty();
}

template <typename T>
T& tree<T>::InOrderIterator::operator*() const {
    return stack.top()->key;
}

template <typename T>
typename tree<T>::InOrderIterator& tree<T>::InOrderIterator::operator++() {
    if (is_binary) {
        Node* node = stack.top();
        stack.pop();
        if (node->children.size() > 1) {
            pushLeft(node->children[1]);
        }
    } else {
        Node* current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            if (*it) stack.push(*it);
        }
    }
    return *this;
}

template <typename T>
typename tree<T>::InOrderIterator tree<T>::begin_in_order() {
    return InOrderIterator(root, max_children);
}
template <typename T>
std::vector<std::tuple<T, int>> tree<T>::toQtTree() const {
    std::vector<std::tuple<T, int>> nodes;
    if (!root) return nodes;

    std::queue<std::pair<Node*, int>> queue;
    queue.push({root, 0});

    while (!queue.empty()) {
        auto [current, depth] = queue.front();
        queue.pop();

        nodes.emplace_back(current->key, depth);

        for (Node* child : current->children) {
            if (child) queue.push({child, depth + 1});
        }
    }

    return nodes;
}

template <typename T>
typename tree<T>::InOrderIterator tree<T>::end_in_order() {
    return InOrderIterator(nullptr, max_children);
}
// Minimum Heap Iterator

template <typename T>
void tree<T>::MinHeapIterator::buildHeap(Node* node) {
    if (!node) return;
    std::queue<Node*> queue;
    queue.push(node);
    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();
        heap.push_back(current);
        for (Node* child : current->children) {
            if (child) queue.push(child);
        }
    }
}
template <typename T>
void tree<T>::print(int argc, char *argv[]) const {
    QApplication app(argc, argv);

    TreeWidget treeWidget;
    treeWidget.setTreeData(toQtTree());
    treeWidget.resize(800, 600);
    treeWidget.show();

    app.exec();
}

template <typename T>
void tree<T>::MinHeapIterator::heapifyDown(size_t index) {
    size_t smallest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < heap.size() && heap[left]->key < heap[smallest]->key)
        smallest = left;

    if (right < heap.size() && heap[right]->key < heap[smallest]->key)
        smallest = right;

    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }
}

template <typename T>
tree<T>::MinHeapIterator::MinHeapIterator(Node* root) : current(0) {
    buildHeap(root);
    for (int i = heap.size() / 2 - 1; i >= 0; i--)
        heapifyDown(i);
}

template <typename T>
bool tree<T>::MinHeapIterator::operator!=(const MinHeapIterator& other) const {
    return current < heap.size();
}

template <typename T>
T& tree<T>::MinHeapIterator::operator*() const {
    return heap[current]->key;
}

template <typename T>
typename tree<T>::MinHeapIterator& tree<T>::MinHeapIterator::operator++() {
    current++;
    return *this;
}

template <typename T>
typename tree<T>::MinHeapIterator tree<T>::begin_min_heap() {
    return MinHeapIterator(root);
}

template <typename T>
typename tree<T>::MinHeapIterator tree<T>::end_min_heap() {
    return MinHeapIterator(nullptr);
}
