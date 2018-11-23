#ifndef BINARYSEARCHTREE_VERTEX_H
#define BINARYSEARCHTREE_VERTEX_H


class vertex {
private:
    int valueOfVertex;
    vertex *leftVertex;
    vertex *rightVertex;
    vertex *aboveVertex;

public:

    vertex *getAboveVertex() const {
        return aboveVertex;
    }

    vertex(int valueOfVertex) {
        this->valueOfVertex = valueOfVertex;
        this->leftVertex = nullptr;
        this->rightVertex = nullptr;
        this->aboveVertex = nullptr;

    }

    bool isEmpty() {
        if (leftVertex == nullptr && rightVertex == nullptr) {
            return true;
        }
        return false;
    }

    vertex *addVertex(int value) {
        if (this->getValueOfVertex() > value) {
            this->leftVertex = new vertex(value);
            return this->leftVertex;
        } else if (this->getValueOfVertex() < value) {
            this->rightVertex = new vertex(value);
            return this->rightVertex;
        }

    }

    vertex *getLeftVertex() const {
        return leftVertex;
    }

    void setLeftVertex(vertex *leftVertex) {
        vertex::leftVertex = leftVertex;
    }

    vertex *getRightVertex() const {
        return rightVertex;
    }

    void setRightVertex(vertex *rightVertex) {
        vertex::rightVertex = rightVertex;
    }


    void setAboveVertex(vertex *aboveVertex) {
        vertex::aboveVertex = aboveVertex;
    }

    vertex(int value, vertex *topVertex) {
        this->valueOfVertex = value;
        this->aboveVertex = topVertex;
    }

    int getValueOfVertex() const {
        return valueOfVertex;
    }

    void setValueOfVertex(int valueOfVertex) {
        vertex::valueOfVertex = valueOfVertex;
    }
};


#endif //BINARYSEARCHTREE_VERTEX_H
