#include "util.h"
#include "algorithm.h"
#include <stdlib.h>
#include <math.h>

//
// Private
//
static void reverse_partition(int *a, int lo, int hi)
{
	if (lo < hi) {
		reverse_partition(a, lo, mid(lo,hi) - 1);
		reverse_partition(a, mid(lo,hi) + 1, hi);
		swap(&a[mid(lo,hi)], &a[hi]);
	}
}

static void shuffle(int *a, int n)
{
	int i;

	for (i=0; i<n; i++) {
		swap(&a[i], &a[rand() % n]);
	}
}


//
// Public
//
void init_ascending(int *a, int n)
{
	int i;

	for (i=0; i<n; i++) {
		a[i] = i+1;
	}
}

void init_descending(int *a, int n)
{
	int i;
	
	for (i=0; i<n; i++) {
		a[i] = n-i;
	}
}

void init_random(int *a, int n)
{
	init_ascending(a, n);
	shuffle(a, n);
}

void init_reverse_partition(int *a, int n)
{
	init_ascending(a, n);
	reverse_partition(a, 0, n-1);
}

int mid(int a, int b)
{
	return (a+b)/2;
}

int first_value(const int *a, int n)
{
	return a[0];
}

int last_value(const int *a, int n)
{
	return a[n-1];
}

int mid_value(const int *a, int n)
{
	return a[mid(0,n-1)];
}

int random_value(const int *a, int n)
{
	return a[rand()%n];
}

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

double fc(int n)
{
	return 1;
}

double flogn(int n)
{
	return log(n);
}

double fn(int n)
{
	return n;
}

double fnlogn(int n)
{
	return n*log(n);
}

double fn2(int n)
{
	return pow(n,2);
}

double fn3(int n)
{
	return pow(n,3);
}
