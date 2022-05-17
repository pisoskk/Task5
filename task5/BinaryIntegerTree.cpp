#include "BinaryIntegerTree.h"
// Õ¿◊¿ÀŒ —À”∆≈¡Õ€’
Node::Node(int info, Node* left, Node* right) {
    this->info = info;
    this->left = left;
    this->right = right;
}

BinaryIntegerTree::BinaryIntegerTree() {
    root = nullptr;
    size = 0;
}

BinaryIntegerTree::BinaryIntegerTree(int x) {
    root = new Node(x);
    size = 1;
}

BinaryIntegerTree::BinaryIntegerTree(const BinaryIntegerTree& copy) {
    if (!copy.root) {
        return;
    }
    size = copy.size;
    Node* copyroot = copy.root;
    copyTree(root, copyroot);
}

void BinaryIntegerTree::copyTree(Node* root, Node* copy) {
    if (!copy) {
        return;
    }
    root = new Node(copy->info);
    copyTree(root->left, copy->left);
    copyTree(root->right, copy->right);
}

BinaryIntegerTree& BinaryIntegerTree::operator=(const BinaryIntegerTree& obj) {
    if (this == &obj) { return *this; }
    this->deleteTree(root);
    root = new Node(obj.root->info);
    copyTree(root, obj.root);
    return *this;
}

void BinaryIntegerTree::deleteTree(Node* root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    if ((!root->left) && (!root->right)) {
        delete root;
    }
}

BinaryIntegerTree::BinaryIntegerTree(BinaryIntegerTree&& move) noexcept {
    std::swap(root, move.root);
    size = move.size;
}

BinaryIntegerTree& BinaryIntegerTree::operator=(BinaryIntegerTree&& obj) noexcept {
    std::swap(root, obj.root);
    size = obj.size;
    return *this;
}

BinaryIntegerTree::~BinaryIntegerTree() {
    deleteTree(root);
    root = nullptr;
}
//  ŒÕ≈÷ —À”∆≈¡Õ€’


void BinaryIntegerTree::addElem(int x, std::vector<int> path) {
    Node* current = root;
    if (!root && !path.empty()) {
        throw std::exception("BadPathException");
    }
    if (!root && path.empty()) {
        root = new Node(x);
        return;
    }
    if (path.empty()) {
        root->info = x;
        return;
    }
    for (int i = 0; i < (path.size() - 1); i++) {
        if (path[i] == 0) {
            current = current->left;
        }
        if (path[i] == 1) {
            current = current->right;
        }
        if (path[i] != 1 && path[i] != 0) {
            throw std::exception("BadPathException");
        }
    }
    if (!current || (path.back() != 1 && path.back() != 0)) {
        throw std::exception("BadPathException");
    }
    if (path.back() == 0) {
        if (!current->left) {
            current->left = new Node(x);
            size++;
        }
        else {
            current->left->info = x;
            return;
        }
    }
    if (path.back() == 1) {
        if (!current->right) {
            current->right = new Node(x);
            size++;
        }
        else {
            current->right->info = x;
            return;
        }
    }
}

std::ostream& operator<<(std::ostream& os, BinaryIntegerTree& obj) {
    obj.printTree(os, obj.root, 0);
    return os;
}

void BinaryIntegerTree::printTree(std::ostream& os, Node* root, int counter) {
    if (!root) {
        return;
    }
    for (int i = 0; i < counter; i++) {
        os << "\t";
    }
    os << root->info << std::endl;
    printTree(os, root->left, counter + 1);
    printTree(os, root->right, counter + 1);
}

int BinaryIntegerTree::getEvenCount(Node* root) {
    if (!root) { return 0; }
    if (root->info % 2 == 0) {
        return (1 + getEvenCount(root->left) + getEvenCount(root->right));
    }
    return (getEvenCount(root->left) + getEvenCount(root->right));

}

int BinaryIntegerTree::getEvenCount() {
    return getEvenCount(root);
}

bool BinaryIntegerTree::checkPositive(Node* root) {
    if (!root) {
        return true;
    }
    if (root->info <= 0) {
        return false;
    }
    if (!checkPositive(root->left)) {
        return false;
    }
    if (!checkPositive(root->right)) {
        return false;
    }
    return true;
}

bool BinaryIntegerTree::checkPositive() {
    return checkPositive(root);
}

bool BinaryIntegerTree::deleteAllLeafs(Node* root) {
    if (!root) { return false; }
    if (!root->left && !root->right) {
        delete root;
        return true;
    }
    else {
        if (deleteAllLeafs(root->left)) { root->left = nullptr; }
        if (deleteAllLeafs(root->right)) { root->right = nullptr; }
    }
    return false;
}

void BinaryIntegerTree::deleteAllLeafs() {
    deleteAllLeafs(root);
}

double BinaryIntegerTree::getSum(Node* root) {
    if (!root) { return 0; }
    return (root->info + getSum(root->left) + getSum(root->right));
}

double BinaryIntegerTree::getAverage() {
    return getSum(root) / size;
}

bool BinaryIntegerTree::findElem(Node* root, int x, std::vector<int>& path) {
    if (!root) { return false; }
    if (root->info == x) {
        return true;
    }
    path.push_back(0);
    if (findElem(root->left, x, path)) { return true; }
    path.pop_back();
    path.push_back(1);
    if (findElem(root->right, x, path)) { return true; }
    path.pop_back();
    return false;
}

std::vector<int> BinaryIntegerTree::findElem(int x) {
    std::vector<int> path = {};
    if (!findElem(root, x, path)) {
        throw std::exception("NoElemException");
    }
    return path;
}

bool BinaryIntegerTree::checkBinaryFindTree(Node* root, int min, int max) {
    if (!root) { return true; }
    if (root->info < min || root->info > max) {
        return false;
    }
    return !(root->info == min && root->left && this->root->info == root->info)
        && !(root->info == max && root->right && this->root->info == root->info) &&
        checkBinaryFindTree(root->left, min, root->info) && checkBinaryFindTree(root->right, root->info, max);
}

void BinaryIntegerTree::findMin(Node* root, int& min) {
    if (!root) { return; }
    if (root->info < min) {
        min = root->info;
    }
    findMin(root->left, min);
    findMin(root->right, min);
}

void BinaryIntegerTree::findMax(Node* root, int& max) {
    if (!root) { return; }
    if (root->info > max) {
        max = root->info;
    }
    findMax(root->left, max);
    findMax(root->right, max);
}

bool BinaryIntegerTree::checkBinaryFindTree() {
    int max = INT_MIN, min = INT_MAX;
    findMin(root->left, min);
    findMax(root->right, max);
    return checkBinaryFindTree(root, min, max);
}