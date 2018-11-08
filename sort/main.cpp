#include <iostream>

void bubble_sort(int a[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insert_sort(int a[], int n) {
    int temp = 0;
    int j = 0;

    for (int i = 1; i < n; i++) {
        j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j = j - 1;
        }
    }

}

void select_sort(int a[], int n) {
    int temp;
    int minIndex = 0;
    int minValue = 0;

    for (int i = 0; i < n; i++) {
        minValue = 2147483647;

        for (int j = i; j < n; j++) {
            if (a[j] < minValue) {
                minValue = a[j];
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

void merge(int *a, int sizeA, int p[], int sizeP, int q[], int sizeQ){

    int i = 0;
    int j = 0;
    int k = 0;



    while (i < sizeP && j < sizeQ) {

        if (p[i] <= q[j]) {
            a[k++] = p[i++];
        } else {
            a[k++] = q[j++];
        }
    }

    while (i < sizeP) {
        a[k++] = p[i++];
    }
    while (j < sizeQ) {
        a[k++] = q[j++];

    }

}


void merge_sort(int a[], int size) {


    if (size != 1) {

        // var
        int end = size - 1;
        int mid = end / 2;
        int sizeP = mid + 1;
        int sizeQ = end - mid;

        //new arrays
        int *p = new int[sizeP];
        int *q = new int[sizeQ];


        // fill arrays
        for (int index = 0; index <= mid; index++) {
            p[index] = a[index];
        }

        for (int index = sizeP; index <= end; index++) {
            q[index - mid - 1] = a[index];
        }


        merge_sort(p, sizeP);
        merge_sort(q, sizeQ);

        merge(a, size, p, sizeP, q, sizeQ);
    }

    return;

}


// print an array with length n to standard output
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char *argv[]) {
    std::string sort_type = std::string(argv[1]);
    int n = argc - 2;   // do not count executable name or first argument
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }
    std::cout << "Original list: ";
    print_array(arr, n);
    if (sort_type == "bubble") {
        bubble_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    } else if (sort_type == "insert") {
        insert_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    } else if (sort_type == "select") {
        select_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    } else if (sort_type == "merge") {
        merge_sort(arr, n);
        std::cout << "Sorted list: ";
        print_array(arr, n);
    } else {
        std::cout << "Sorry, " << sort_type << " sort is not implemented!" << std::endl;
    }
    delete[] arr;
}