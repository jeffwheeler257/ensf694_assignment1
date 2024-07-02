#include "MyArray.h"

int search(const MyArray* myArray, int obj){
    for (int i = 0; i < SIZE; i++){
        if (myArray->array[i] == obj){
            return i;
        }
    }
    return -1;
}

void initialize(MyArray* myArray) {
    myArray->list_size = 0;
}

int retrieve_at(MyArray* myArray, int pos){
    return myArray->array[pos];
}

int count(MyArray* myArray, int obj){
    int count = 0;
    for (int i = 0; i < myArray->list_size; i++){
        if (myArray->array[i] == obj){
            count++;
        }
    }
    return count;
}

void append(MyArray* myArray, int array[], int n) {
    if ((myArray->list_size + n) <= SIZE){
        for (int i = 0; i < n; i++){
            myArray->array[myArray->list_size + i] = array[i];
        }
    }
}

void insert_at(MyArray* myArray, int pos, int val) {
    for (int i = SIZE - 1; i > pos; i--){
        myArray->array[i] = myArray->array[i-1];
    }
    myArray->array[pos] = val;
    myArray->list_size++;
}

int remove_at(MyArray* myArray, int pos) {
    int removed = myArray->array[pos];
    for (int i = pos; i < SIZE; i++){
        myArray->array[i] = myArray->array[i+1];
    }
    myArray->list_size--;
    return removed;
}

int remove_all(MyArray* myArray, int value) {
    int removed = 0;
    for (int i = myArray->list_size - 1; i >= 0; i--){
        myArray->array[i] = 0;
        removed++;
    }
    return removed;
}

void display_all(MyArray* myArray) {
    for (int i = 0; i < myArray->list_size; i++){
        cout << myArray->array[i] << " ";
    }
}

bool is_full(MyArray* myArray){
    if (myArray->list_size == SIZE){
        return true;
    }
    return false;
}

bool isEmpty(MyArray* myArray){
    if (myArray->list_size == 0){
        return true;
    }
    return false;
}

int size(MyArray* myArray){
    return myArray->list_size;
}
