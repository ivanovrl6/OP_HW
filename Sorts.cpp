#include <iostream>
#include "Sorts.h"

void insertSort(int* a, int n){
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            std::swap(a[j - 1], a[j]);
        }
    }
}
void test_Sort(int* arr, int size) {
    for (int k = 0; k < size - 1; k++) {
        if ((arr[k + 1] - arr[k]) < 0) {
            std::cout << "test 1 is BAD" << std::endl;
            break;
        }
    }
}
void bubbleSort (int* arr, int size){
    for(int k=0;k<size;k++){
        for(int j=0;j<k;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j+1]=arr[j];
                arr[j+1]=temp;
            }
        }
    }
}

void countSort(int* ar, int n) {
    int* arr1 = new int[n];
    int x = ar[0];

    for (int i = 1; i < n; i++) {
        if (ar[i] > x)
            x = ar[i];
    }

    int* count_arr = new int[x+1];

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[ar[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[ar[i]] - 1] = ar[i];
        count_arr[ar[i]]--;
    }

    for (int i = 0; i < n; i++) {
        ar[i] = arr1[i];
    }
    delete[] arr1;
    delete[] count_arr;
}
int partition(int* arr, int first, int last) {
    int i = first, j = last;
    int pivot = arr[(first + last) / 2];

    while (true) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return j;
}
void quickSort1(int* arr, int first, int last) {
    if (first < last) {
        int p = partition(arr, first, last);
        quickSort1(arr, first, p);
        quickSort1(arr, p + 1, last);
    }
}
void quickSort(int* arr, int size){
    quickSort1(arr,0,size-1);
}

void merge(int* array, int const left, int const mid,
           int const right)
{
    int const sizeOne = mid - left + 1;
    int const sizeTwo = right - mid;
    int *leftArray = new int[sizeOne], *rightArray = new int[sizeTwo];
    for (int i = 0; i < sizeOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < sizeOne
           && indexOfSubArrayTwo < sizeTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < sizeOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < sizeTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort1(int* array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort1(array, begin, mid);
    mergeSort1(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void mergeSort(int*arr,int size){
    mergeSort1(arr,0,size-1);
}

void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

//
// Created by User on 21.03.2023.
//
