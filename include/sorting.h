#pragma once

//comparison based sorting algorithms
//basics
void selection_sort(int *array, int len);
void insertion_sort(int *array, int len);
void bubble_sort(int *array, int len);

//advanced (divide et impera)
void quick_sort(int *array, int low, int high);
int partition(int *array, int low, int high);

void merge_sort(int *array, int start, int end);
void merge(int *array, int start, int m, int end);

//integer sorting algorithms
void integer_sort(int *array, int len);