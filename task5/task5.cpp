#include "BinaryIntegerTree.h"
#include "locale.h"

int main() {
    BinaryIntegerTree tree;
    std::vector<int> v = {};
    tree.addElem(10, v);
    v = { 1 };
    tree.addElem(21, v);
    v = { 0 };
    tree.addElem(7, v);
    v = { 0, 0 };
    tree.addElem(4, v);
    v = { 0, 1 };
    tree.addElem(9, v);
    v = { 0, 0, 0 };
    tree.addElem(2, v);
    v = { 1, 0 };
    tree.addElem(16, v);
    v = { 1, 0, 1 };
    tree.addElem(19, v);
    std::cout << tree << std::endl;
    std::cout << "even elements count - " << tree.getEvenCount() << std::endl;
    std::cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << std::endl;
    std::cout << "arithmetic average - " << tree.getAverage() << std::endl;
    std::cout << "binary search? - " << (tree.checkBinaryFindTree() ? "Yes" : "No") << std::endl;
    v = tree.findElem(16);
    std::cout << "find elem(16) path: " << v[0] << " " << v[1] << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    v = { 0, 0, 0 };
    tree.addElem(-1, v);
    v = {};
    tree.addElem(45, v);
    std::cout << tree << std::endl;
    std::cout << "even elements count - " << tree.getEvenCount() << std::endl;
    std::cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << std::endl;
    std::cout << "arithmetic average - " << tree.getAverage() << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    tree.deleteAllLeafs();
    std::cout << tree << std::endl;
    std::cout << "even elements count - " << tree.getEvenCount() << std::endl;
    std::cout << "all elements positive? - " << (tree.checkPositive() ? "Yes" : "No") << std::endl;
    std::cout << "arithmetic average - " << tree.getAverage() << std::endl;
    std::cout << "binary search? - " << (tree.checkBinaryFindTree() ? "Yes" : "No") << std::endl;
    return 0;
}