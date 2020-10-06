#include "BASE.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <chrono>
using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
using Diff = std::chrono::microseconds;


template <typename T>
void swap_(T& a, T& b) {
	T tmp_ = a;
	a = b;
	b = tmp_;
}

template <typename T>
void buble_sort_(std::vector<T>& main) {
	for (size_t ptrL = 0; ptrL < main.size(); ptrL++) {
		for (size_t ptrR = ptrL+1; ptrR < main.size(); ptrR++) {
			if (main[ptrL] >= main[ptrR]) {
				swap_(main[ptrL], main[ptrR]);
			}
		}
	}
}

template <typename T>
void binary_sort_(std::vector<T>& main, int L, int R) {
	int ptrL = static_cast<int>(L), ptrR = static_cast<int>(R);
	int mid_ = main[static_cast<int>((ptrL + ptrR)/2)];
	do {
		while (main[ptrL] > mid_) {
			ptrL++;
		}
		while (main[ptrR] < mid_) {
			ptrR--;
		}
		if (ptrL <= ptrR) {
			swap_(main[ptrL++], main[ptrR--]);
		}
	} while (ptrL <= ptrR);
	if (L < ptrR) {
		binary_sort_(main, L, ptrR);
	}
	if (R > ptrL) {
		binary_sort_(main, ptrL, R);
	}
}

template <typename T>
void merge_sort_(std::vector<T>& main, size_t B, size_t S) {
	if (S - B < 2) {
		return;
	}
	if (S - B == 2) {
		if (main[B] > main[B+1]) {
			swap_(main[B], main[B+1]);
		}
		return;
	}
	
	merge_sort_(main, B, B + (S - B ) / 2);
	merge_sort_(main, B + (S - B) / 2, S);
	std::size_t b1 = B, e1 = B + (S - B) / 2, b2 = e1;
	std::vector<T> tmp_array;
	while (tmp_array.size() < S - B) {
		if (b1 >= e1 || (b2 < S && main[b2] <= main[b1])) {
			tmp_array.push_back(main[b2]);
			++b2;
		}
		else {
			tmp_array.push_back(main[b1]);
			++b1;
		}
	}
	for (size_t ptr = B; ptr < S; ++ptr) {
		main[ptr] = tmp_array[ptr-B];
	}
	
}

template <typename T>
void insertion_sort_(std::vector<T>& main) {
	for (std::size_t ptr = 1; ptr < main.size(); ptr++) {
		for (std::size_t ptr2 = ptr; ptr2 > 0 && main[ptr2 - 1] > main[ptr2]; ptr2--) {
			swap_(main[ptr2 - 1], main[ptr2]);
		}
	}
}


template <typename T>
void quick_sort_(std::vector<T>& main, int L, int H) {
	int ptr_l = L, ptr_r = H, ptr_tmp_, pivot = main[int(H+L/2)];
	while (ptr_l <= ptr_r) {
		while (main[ptr_l] < pivot) {
			ptr_l++;
		}
		while (main[ptr_r] > pivot) {
			ptr_r--;
		}
		if (ptr_l <= ptr_r) {
			swap_(main[ptr_l++], main[ptr_r--]);
		}
	}
	if (L < ptr_r) {
		quick_sort_(main,L,ptr_r);
	}
	if (ptr_l < H) {
		quick_sort_(main, ptr_l, H);
	}
}

template <typename T>
void selection_sort_(std::vector<T>& main, std::size_t S) {
	std::size_t min_indx;
	for (std::size_t ptr = 0; ptr < S-1; ptr++) {
		min_indx = ptr;
		for (std::size_t ptr2 = ptr+1; ptr2 < S; ptr2++) {
			if (main[ptr2] < main[min_indx]) {
				min_indx = ptr2;
			}
			swap_(main[min_indx], main[ptr]);
		}
	}
}


int main() {
	std::vector<int> BASE = do_rnd_bse_();
	
	//------
	std::cout << "1)BUBLE_SORT_ ALGO:" << std::endl;
	std::vector<int>a(BASE.begin(), BASE.end());
	Time t1 = std::chrono::steady_clock::now();
	buble_sort_(a);
	Time t2 = std::chrono::steady_clock::now();
	Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);
	std::cout << "Sort time: " << diff.count() << " mcro" << std::endl;
	std::cout << std::endl;
	//------

	
	std::cout << "2)BINARY_SORT_ ALGO:" << std::endl;
	std::vector<int>b(BASE.begin(), BASE.end());
	int L = 0;
	int R = b.size() - 1;
	Time t3 = std::chrono::high_resolution_clock::now();
	binary_sort_(b, L, R);
	Time t4 = std::chrono::high_resolution_clock::now();
	Diff diff1 = std::chrono::duration_cast<Diff>(t4 - t3);
	std::cout << "Sort time: " << diff1.count() << " mcro" << std::endl;
	std::cout << std::endl;
	//------
	
	std::cout << "3)MERGE_SORT ALGO:" << std::endl;
	std::vector<int>c(BASE.begin(), BASE.end());
	Time t5 = std::chrono::high_resolution_clock::now();
	merge_sort_(c, 0, c.size());
	Time t6 = std::chrono::high_resolution_clock::now();
	Diff diff2 = std::chrono::duration_cast<Diff>(t6 - t5);
	std::cout << "Sort time: " << diff2.count() << " mcro" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "4)INSERTION_SORT ALGO:" << std::endl;
	std::vector<int>d(BASE.begin(), BASE.end());
	Time t7 = std::chrono::high_resolution_clock::now();
	insertion_sort_(d);
	Time t8 = std::chrono::high_resolution_clock::now();
	Diff diff3 = std::chrono::duration_cast<Diff>(t8 - t7);
	std::cout << "Sort time: " << diff3.count() << " mcro" << std::endl;
	std::cout << std::endl;
	//------

	/*
	std::cout << "5)QUICK_SORT ALGO:" << std::endl;
	std::vector<int>e(BASE.begin(), BASE.end());
	Time t9 = std::chrono::high_resolution_clock::now();
	quick_sort_(e, 0, e.size());
	Time t10 = std::chrono::high_resolution_clock::now();
	Diff diff4 = std::chrono::duration_cast<Diff>(t10 - t9);
	std::cout << "Sort time: " << diff4.count() << " mcro" << std::endl;
	std::cout << std::endl;
	//------
	*/

	std::cout << "6)SELECTION_SORT_ ALGO:" << std::endl;
	std::vector<int>ff(BASE.begin(), BASE.end());
	Time t11 = std::chrono::high_resolution_clock::now();
	selection_sort_(ff, ff.size());
	Time t12 = std::chrono::high_resolution_clock::now();
	Diff diff5 = std::chrono::duration_cast<Diff>(t12 - t11);
	std::cout << "Sort time: " << diff5.count() << " mcro" << std::endl;
	
	return 0;
}

