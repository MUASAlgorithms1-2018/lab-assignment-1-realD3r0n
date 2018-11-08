#include <iostream>
#include <cstring>
#include "Stack.h"


int main(int argc, char *argv[]) {

    if (argc > 1) {

        char *arr;
        Stack *A = new Stack(255);
        int n;


        arr = (char *) malloc(strlen(argv[1]) + 1);
        strcpy(arr, argv[1]);
        n = strlen(argv[1]);
        bool noWrongChar = true;


        for (int index = 0; index < n; index++) {
            if (arr[index] == '(') {
                A->push(arr[index]);
            } else if (arr[index] == ')' && A->size() > 0) {
                A->pop();
            } else {
                noWrongChar = false;
                break;
            }


        }
        if (A->size() < 1 && noWrongChar) {
            std::cout << "true";
        } else {
            std::cout << "false";
        }

    } else {
        std::cout << "true";
    }


    return 0;
}
