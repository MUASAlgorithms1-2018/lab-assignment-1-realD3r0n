#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"


int main(int argc, char *argv[]) {
    BinarySearchTree *binarySearchTree = new BinarySearchTree();

    for (int i = 1; i < argc; i++) {
        binarySearchTree->insert(new vertex(atoi((argv[i]))));
    }

    bool printed = false;
    vertex* top = binarySearchTree->getTopVertex();

    binarySearchTree->tprintTheNodesOrNone(top, &printed);
    if (!printed) {
        std::cout << "None";
    }
    return 0;

}

