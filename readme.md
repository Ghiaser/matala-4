//ghia48.serhan@gmail.com
## README

# Tree Visualization and Iterators with Qt

This project provides a `tree` class template in C++ with various traversal iterators (BFS, DFS, Pre-Order, Post-Order, In-Order, MinHeap) and a Qt-based visualization tool to display the tree structure. The project includes test cases to demonstrate the functionality of the tree and its iterators.

## Project Structure

```
.
├── main.cpp
├── tree.h
├── tree.tpp
├── TreeWidget.h
├── TreeWidget.cpp
├── Tree.cpp
└── README.md
```

### File Descriptions

- **main.cpp**: The main file that runs the test cases and visualizes the trees.
- **tree.h**: Header file for the `tree` class template.
- **tree.tpp**: Implementation file for the `tree` class template.
- **TreeWidget.h**: Header file for the Qt widget used to visualize the tree.
- **TreeWidget.cpp**: Implementation file for the `TreeWidget` class.
- **Tree.cpp**: Implementation of the `tree` class template and its methods.
- **README.md**: This README file.

## Class and Methods Description

### `tree` Class

The `tree` class template represents a general tree structure with a specified maximum number of children per node.

#### Methods

- **Constructor**: Initializes the tree with a specified maximum number of children (`max_children`).
- **add_root**: Adds a root node to the tree.
- **add_sub_node**: Adds a child node to a specified parent node.
- **toQtTree**: Converts the tree structure into a format suitable for Qt visualization.
- **print**: Visualizes the tree using Qt.

### Iterator Classes

The `tree` class includes several nested iterator classes for different types of tree traversals:

- **BFSIterator**: Breadth-First Search iterator.
- **DFSIterator**: Depth-First Search iterator.
- **PreOrderIterator**: Pre-Order traversal iterator.
- **PostOrderIterator**: Post-Order traversal iterator.
- **InOrderIterator**: In-Order traversal iterator.
- **MinHeapIterator**: Minimum Heap traversal iterator.

Each iterator class includes the following methods:

- **Constructor**: Initializes the iterator starting from the root node.
- **operator!=**: Checks if the iterator has reached the end.
- **operator***: Dereferences the iterator to access the current node's key.
- **operator++**: Advances the iterator to the next node.

### `TreeWidget` Class

The `TreeWidget` class is a custom Qt widget used to visualize the tree structure.

#### Methods

- **Constructor**: Initializes the widget.
- **setTreeData**: Sets the data for the tree to be visualized.
- **paintEvent**: Handles the painting of the tree visualization in the widget.

## Implementation Details

### `tree` Class Implementation

- **add_root**: Sets the root node of the tree.
- **add_sub_node**: Searches for the parent node and adds the child node to the first available position. Throws an error if the parent is not found or if the maximum number of children is exceeded.
- **toQtTree**: Performs a level-order traversal to convert the tree into a list of tuples containing the node key and its depth.
- **print**: Initializes a Qt application, sets up the `TreeWidget` with the tree data, and displays the widget.

### Iterator Implementation

Each iterator class manages its traversal using appropriate data structures (`queue` for BFS, `stack` for DFS and other depth-based traversals). The iterators traverse the tree according to their specific traversal algorithms and provide standard iterator functionality.

### `TreeWidget` Class Implementation

- **setTreeData**: Stores the tree data and triggers a repaint.
- **paintEvent**: Calculates the positions of the nodes based on their depth and key, then draws the nodes and connecting lines. Centers the tree within the widget for better visualization.

## How to Build and Run

import the files to QT and build and run the project

