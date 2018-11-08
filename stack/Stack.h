//
// Created by local on 06-Nov-18.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack {
private:
    int maxStackSize;
    int currentSize;
    char stackArray[];



public:
    Stack(int mSize) {
        maxStackSize = mSize;
        currentSize = 0;
    }



    int size() {
        return currentSize;
    }

    void push(char c){
        if (currentSize != maxStackSize){
            stackArray[currentSize++] = c;
        }
    }


    char pop(){
        char c = 'Q';

        if (currentSize>0){
            c = stackArray[currentSize];
            stackArray[currentSize--] = 0;
        }
        return c;
    }

};


#endif //STACK_STACK_H
