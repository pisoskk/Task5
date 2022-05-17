#pragma once

#include "iostream"
#include "vector"
#include "climits"

struct Node {
    int info;
    Node* left, * right;

    explicit Node(int info, Node* left = nullptr, Node* right = nullptr);
};

class BinaryIntegerTree {
private:
    Node* root;
    int size;

    void copyTree(Node* root, Node* copy);

    void deleteTree(Node* root);

    void printTree(std::ostream& os, Node* root, int counter);

    int getEvenCount(Node* root);

    bool checkPositive(Node* root);

    bool deleteAllLeafs(Node* root);

    double getSum(Node* root);

    bool findElem(Node* root, int x, std::vector<int>& path);

    bool checkBinaryFindTree(Node* root, int min, int max);

    void findMin(Node* root, int& min);

    void findMax(Node* root, int& max);

public:
    BinaryIntegerTree();

    explicit BinaryIntegerTree(int x);

    BinaryIntegerTree(const BinaryIntegerTree& copy);

    BinaryIntegerTree(BinaryIntegerTree&& move) noexcept;

    ~BinaryIntegerTree();

    BinaryIntegerTree& operator=(const BinaryIntegerTree& copy);

    BinaryIntegerTree& operator=(BinaryIntegerTree&& copy) noexcept;

    void addElem(int x, std::vector<int> path);

    friend std::ostream& operator<<(std::ostream& os, BinaryIntegerTree& obj);

    int getEvenCount();

    bool checkPositive();

    void deleteAllLeafs();

    double getAverage();

    bool checkBinaryFindTree();

    std::vector<int> findElem(int x);
};
