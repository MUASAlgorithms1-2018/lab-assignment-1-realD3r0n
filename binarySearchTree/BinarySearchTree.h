#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H


#include "vertex.h"
#include <iostream>

class BinarySearchTree {
private:
    vertex *topVertex;
    vertex *currentVertex;
    bool firstRun;

public:

    vertex *getTopVertex() {
        return topVertex;
    }


    BinarySearchTree(int value) {
        vertex *a = new vertex(value);
        this->topVertex = a;
        this->currentVertex = a;
    }

    BinarySearchTree() {
        this->topVertex = nullptr;
        this->currentVertex = nullptr;
    }

public:
    void insert(vertex *x) {
        if (topVertex == nullptr) {
            topVertex = x;
            currentVertex = topVertex;
            return;
        }


        if (currentVertex->getValueOfVertex() == x->getValueOfVertex()) {
            return;
        }


        if (currentVertex->getValueOfVertex() < x->getValueOfVertex()) {
            if (currentVertex->getRightVertex() == nullptr) {
                currentVertex->setRightVertex(x);
                x->setAboveVertex(currentVertex);
                currentVertex = topVertex;
            } else {
                currentVertex = currentVertex->getRightVertex();
                insert(x);
                return;
            }


        } else {
            if (currentVertex->getLeftVertex() == nullptr) {
                currentVertex->setLeftVertex(x);
                x->setAboveVertex(currentVertex);
                currentVertex = topVertex;
                return;
            } else {
                currentVertex = currentVertex->getLeftVertex();
                insert(x);
                return;
            }


        }
        currentVertex = topVertex;
    }

    void tprintTheNodesOrNone(vertex *currentVertex, bool *b) {
        if (!firstRun) {
            firstRun = true;

            if (currentVertex->getLeftVertex() != nullptr)
                tprintTheNodesOrNone(currentVertex->getLeftVertex(), b);
            if (currentVertex->getRightVertex() != nullptr)
                tprintTheNodesOrNone(currentVertex->getRightVertex(), b);

        } else {
            if (currentVertex->getAboveVertex() != nullptr) {
                if (currentVertex->getAboveVertex()->getValueOfVertex() % 5 == 0) {
                    std::cout << currentVertex->getValueOfVertex();
                    std::cout << " ";
                    *b = true;
                }
                if (currentVertex->getLeftVertex() != nullptr) {
                    tprintTheNodesOrNone(currentVertex->getLeftVertex(), b);
                }
                if (currentVertex->getRightVertex() != nullptr) {
                    tprintTheNodesOrNone(currentVertex->getRightVertex(), b);
                }
            }
        }
    }

};


#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
