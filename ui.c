#include "ui.h"
#include "io.h"
#include "analyze.h"
#include "util.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//
// Private
//
static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		// House keeping
		"Menu",
		"Exit\n",
		// Bubble sort
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",
		// Insertion sort
		"Insertion sort best case",
		"Insertion sort worst case",
		"Insertion sort average case\n",
		// Quick sort
		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort average case\n",
		// Linear search
		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",
		// Binary search
		"Binary search best case",
		"Binary search worst case",
		"Binary search average case",
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

static void ui_perf_head(char *info, char *h1, char *h2, char *h3)
{
	ui_line('*', COL_WIDTH/2 + COL_WIDTH*4);
	printf("%-*s%s\n", (COL_WIDTH/2+COL_WIDTH*4-(int)strlen(info))/2, "", info);
	ui_line('~', COL_WIDTH/2 + COL_WIDTH*4);
	printf("%-*s%-*s%-*s%-*s%-*s\n",
		COL_WIDTH/2, "size",
		COL_WIDTH, "time T(s)",
		COL_WIDTH, h1,
		COL_WIDTH, h2,
		COL_WIDTH, h3);
	ui_line('~', COL_WIDTH/2 + COL_WIDTH*4);
}

static void ui_perf_body(result_t *r, int n, double (*f1)(int),
	double (*f2)(int), double (*f3)(int))
{
	int i;

	for (i=0; i<n; i++) {
		printf("%-*d%-*.8lf%-*e%-*e%-*e\n",
			COL_WIDTH/2, r[i].size,
			COL_WIDTH, r[i].time,
			COL_WIDTH, r[i].time / f1(r[i].size),
			COL_WIDTH, r[i].time / f2(r[i].size),
			COL_WIDTH, r[i].time / f3(r[i].size));
	}
}

static void ui_show_perf(char *info, result_t *r, int n, char *h1, char *h2,
	char *h3, double (*f1)(int), double (*f2)(int), double (*f3)(int))
{
	ui_perf_head(info, h1, h2, h3);
	ui_perf_body(r, n, f1, f2, f3);
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				ui_show_perf("bubble sort: best", result, RESULT_ROWS,
					"T/logn", "T/n", "T/nlog", flogn, fn, fnlogn);
				break;
			case 'd':
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				ui_show_perf("bubble sort: worst", result, RESULT_ROWS,
					"T/nlogn", "T/n^2", "T/n^3", fnlogn, fn2, fn3);
				break;
			case 'e':
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				ui_show_perf("bubble sort: average", result, RESULT_ROWS,
					"T/nlogn", "T/n^2", "T/n^3", fnlogn, fn2, fn3);
				break;
			// Insertion sort
			case 'f':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				ui_show_perf("insertion sort: best", result, RESULT_ROWS,
					"T/logn", "T/n", "T/nlogn", flogn, fn, fnlogn);
				break;
			case 'g':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				ui_show_perf("insertion sort: worst", result, RESULT_ROWS,
					"T/nlogn", "T/n^2", "T/n^3", fnlogn, fn2, fn3);
				break;
			case 'h':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				ui_show_perf("insertion sort: average", result, RESULT_ROWS,
					"T/nlogn", "T/n^2", "T/n^3", fnlogn, fn2, fn3);
				break;
			// Quick sort
			case 'i':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				ui_show_perf("quick sort: best", result, RESULT_ROWS,
					"T/n", "T/nlogn", "T/n^2", fn, fnlogn, fn2);
				break;
			case 'j':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				ui_show_perf("quick sort: worst", result, RESULT_ROWS,
					"T/nlogn", "T/n^2", "T/n^3", fnlogn, fn2, fn3);
				break;
			case 'k':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				ui_show_perf("quick sort: average", result, RESULT_ROWS,
					"T/n", "T/nlogn", "T/n^2", fn, fnlogn, fn2);
				break;
			// Linear search
			case 'l':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				ui_show_perf("linear search: best", result, RESULT_ROWS,
					"T/c", "T/logn", "T/n", fc, flogn, fn);
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				ui_show_perf("linear search: worst", result, RESULT_ROWS,
					"T/logn", "T/n", "T/nlogn", flogn, fn, fnlogn);
				break;
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				ui_show_perf("linear search: average", result, RESULT_ROWS,
					"T/logn", "T/n", "T/nlogn", flogn, fn, fnlogn);
				break;
			// Binary search
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				ui_show_perf("binary search: best", result, RESULT_ROWS,
					"T/1", "T/logn", "T/n", fc, flogn, fn);
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				ui_show_perf("binary search: worst", result, RESULT_ROWS,
					"T/1", "T/logn", "T/n", fc, flogn, fn);
				break;
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				ui_show_perf("binary search: average", result, RESULT_ROWS,
					"T/1", "T/logn", "T/n", fc, flogn, fn);
				break;
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
