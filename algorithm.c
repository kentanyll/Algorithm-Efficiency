#include <stdio.h>
#include "algorithm.h"
#include "util.h"

//
// Private
//
static int partition(int *a, int low, int high){
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j < high; j++){
		if(a[j] < pivot){
			swap(&a[++i], &a[j]);
		}
	}
	swap(&a[++i], &a[high]);
	return i;
}
static void the_secret_quick_sort(int *a, int low, int high){
	if(low < high){
		int part = partition(a, low, high);
		the_secret_quick_sort(a, low, part - 1);
		the_secret_quick_sort(a, part + 1, high);
	}
	return;
}
//
// Public
//
void bubble_sort(int *a, int n)
{
		bool swapped;
		int j = 0;
		do{
			swapped = false;
			for(int i = 1; i < n - j; i++){
				if(a[i-1] > a[i]){
					swap(&a[i-1], &a[i]);
					swapped = true;
				}
			}
			j++;
		}while(swapped);
	return;
}

void insertion_sort(int *a, int n)
{
	for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
	return;
}

void quick_sort(int *a, int n)
{
	// Needed to use low and high for recursion without changing function's inputs, thus there another quicksort
	the_secret_quick_sort(a, 0, n - 1);
	return;
}

bool linear_search(const int *a, int n, int v)
{
	for(int i = 0; i < n; i++){
		if(a[i] == v){
			return true;
		}
	}
	return false;
}

bool binary_search(const int *a, int n, int v)
{
	int min = 0;
	int max = n-1;
	while(min <= max){
        int mid = (min + max) / 2;
        if(a[mid] == v){
            return true;
        }
        if(a[mid] < v){
            min = mid + 1;
        }else{
            max = mid - 1;
        }}
	return false;
}
