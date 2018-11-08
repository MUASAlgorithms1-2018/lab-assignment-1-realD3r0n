#include <iostream>
#include <string>
#include <vector>


void bubble_sort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insert_sort(int a[], int n) {
    int temp;

    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            j = j - 1;
        }
    }
}


void merge(int *a, int *p, int size_of_p, int *q, int size_of_q) {

    int i = 0;
    int j = 0;
    int k = 0;



    while (i < size_of_p && j < size_of_q) {

        if (p[i] <= q[j]) {
            a[k++] = p[i++];
        } else {
            a[k++] = q[j++];
        }
    }

    while (i < size_of_p) {
        a[k++] = p[i++];
    }

    while (j < size_of_q) {
        a[k++] = q[j++];

    }
}

void merge_sort(int *a, int size) {
    if (size == 1) {
        return;
    }

    // var
    int start = 0;
    int end = start + size - 1;
    int mid = (start + end) / 2;
    int size_of_p = mid - start + 1;
    int size_of_q = end - mid;

    // new arrays
    int *p = new int[size_of_p];
    int *q = new int[size_of_q];

    // generate array p
    for (int i = start; i <= mid; i++) {
        p[i] = a[i];
    }

    // generate array p
    for (int i = mid + 1; i <= end; i++) {
        q[i - mid - 1] = a[i];
    }

    // dac till array only got 1 element at index 0,
    merge_sort(p, size_of_p);
    merge_sort(q, size_of_q);

    //merge arrays
    merge(a, p, size_of_p, q, size_of_q);

}


// print an array with length n to standard output
void print_array(int *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    std::string sort_type = std::string(argv[1]); // bubble // Was ist mit argv[0] ?
    int n = argc - 2; // do not count executable name or first argument
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 2]);
    }

    std::cout << "Original list: ";
    print_array(arr, n);
    if (sort_type == "bubble") {
        bubble_sort(arr, n);
        std::cout << "Sorted bubble list: ";
        print_array(arr, n);
    } else if (sort_type == "insertion") {
        insert_sort(arr, n);
        std::cout << "Sorted insertion list: ";
        print_array(arr, n);
    } else if (sort_type == "merge") {
        merge_sort(arr, n);
        std::cout << "Sorted merge list: ";
        print_array(arr, n);
    } else {
        std::cout << "Sorry,     " << sort_type << " sort is not implemented!" << std::endl;
    }
    delete[] arr;
    return 0;
}