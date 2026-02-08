#ifndef UTIL_H
#define UTIL_H

// init_ascending initializes the array arr of length n with 1...n
void init_ascending(int *arr, int n);

// init_descending initializes the array arr of length n with n...1
void init_descending(int *arr, int n);

// init_random initializes the array arr of length n with 1...n in random order
void init_random(int *arr, int n);

// init_reverse_partition initializes the array arr of length n for best-case
// quick sort; assumes that quick sort uses the right-most index as pivot
void init_reverse_partition(int *a, int n);

// swap swaps the values pointed to by a and b
void swap(int *a, int *b);

// mid computes the average of a and b without floating point arithmetic
int mid(int a, int b);

// {first,last,mid,random}_value outputs the respective values in the array arr
// of length n
int first_value(const int *arr, int n);
int last_value(const int *arr, int n);
int mid_value(const int *arr, int n);
int random_value(const int *arr, int n);

// f* computes c=1, logn, n, nlogn, n^2, and n^3
double fc(int n);
double flogn(int n);
double fn(int n);
double fnlogn(int n);
double fn2(int n);
double fn3(int n);

#endif
