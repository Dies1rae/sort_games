#include "BASE.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <chrono>



template <typename T>
void swap_(T& a, T& b) {
	T tmp_ = a;
	a = b;
	b = tmp_;
}

template <typename T>
std::vector<T> buble_sort_(std::vector<T> main) {
	for (size_t ptrL = 0; ptrL < main.size(); ptrL++) {
		for (size_t ptrR = ptrL+1; ptrR < main.size(); ptrR++) {
			if (main[ptrL] >= main[ptrR]) {
				swap_(main[ptrL], main[ptrR]);
			}
		}
	}
	return main;
}

template <typename T>
void binary_sort_(std::vector<T>& main, size_t L, size_t R) {
	size_t ptrL = L, ptrR = R;
	T mid_ = main[(ptrL + ptrR)/2];
	do {
		while (main[ptrL] < mid_) {
			ptrL++;
		}
		while (main[ptrR] > mid_) {
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
std::vector<T> insertion_sort_(std::vector<T> main) {
	for (std::size_t ptr = 1; ptr < main.size(); ptr++) {
		for (std::size_t ptr2 = ptr; ptr2 > 0 && main[ptr2 - 1] > main[ptr2]; ptr2--) {
			swap_(main[ptr2 - 1], main[ptr2]);
		}
	}
	return main;
}


template <typename T>
void quick_sort_(std::vector<T>& main, size_t L, size_t H) {
	std::size_t ptr_l = L, ptr_r = H, ptr_tmp_, pivot = main[std::floor((L+H)/2)];
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
std::vector<T> selection_sort_(std::vector<T> main, std::size_t S) {
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
	return main;
}


int main() {
	using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
	using Diff = std::chrono::milliseconds;
	

	//------
	std::cout << "1)NO SORT:" << std::endl;
	for (const auto& ptr : BASE) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	std::cout << std::endl;
	//------
	std::cout << "2)BUBLE_SORT_ ALGO:" << std::endl;
	Time t1 = std::chrono::high_resolution_clock::now();
	for (const auto& ptr : buble_sort_(BASE)) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	Time t2 = std::chrono::high_resolution_clock::now();
	Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);
	std::cout << "Sort + cout time: " << diff.count() << " ms" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "3)BINARY_SORT_ ALGO:" << std::endl;
	std::vector<int>res(BASE.begin(), BASE.end());
	size_t L = 0;
	size_t R = res.size() - 1;
	Time t3 = std::chrono::high_resolution_clock::now();
	binary_sort_(res, L, R);
	for (const auto& ptr : res) {
		std::cout << ptr << ' ';
	} 
	std::cout << std::endl;
	Time t4 = std::chrono::high_resolution_clock::now();
	Diff diff1 = std::chrono::duration_cast<Diff>(t4 - t3);
	std::cout << "Sort + cout time: " << diff1.count() << " ms" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "3)MERGE_SORT ALGO:" << std::endl;
	std::vector<int>res1(BASE.begin(), BASE.end());
	Time t5 = std::chrono::high_resolution_clock::now();
	merge_sort_(res1, 0, res1.size());
	for (const auto& ptr : res1) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	Time t6 = std::chrono::high_resolution_clock::now();
	Diff diff2 = std::chrono::duration_cast<Diff>(t6 - t5);
	std::cout << "Sort + cout time: " << diff2.count() << " ms" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "4)INSERTION_SORT ALGO:" << std::endl;
	Time t7 = std::chrono::high_resolution_clock::now();
	for (const auto& ptr : insertion_sort_(BASE)) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	Time t8 = std::chrono::high_resolution_clock::now();
	Diff diff3 = std::chrono::duration_cast<Diff>(t8 - t7);
	std::cout << "Sort + cout time: " << diff3.count() << " ms" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "5)QUICK_SORT ALGO:" << std::endl;
	std::vector<int>res2(BASE.begin(), BASE.end());
	size_t l = 0;
	size_t r = res2.size() - 1;
	Time t9 = std::chrono::high_resolution_clock::now();
	quick_sort_(res2, l, r);
	for (const auto& ptr : res2) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	Time t10 = std::chrono::high_resolution_clock::now();
	Diff diff4 = std::chrono::duration_cast<Diff>(t10 - t9);
	std::cout << "Sort + cout time: " << diff4.count() << " ms" << std::endl;
	std::cout << std::endl;
	//------

	std::cout << "6)SELECTION_SORT_ ALGO:" << std::endl;
	Time t11 = std::chrono::high_resolution_clock::now();
	for (const auto& ptr : selection_sort_(BASE,BASE.size())) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
	Time t12 = std::chrono::high_resolution_clock::now();
	Diff diff5 = std::chrono::duration_cast<Diff>(t12 - t11);
	std::cout << "Sort + cout time: " << diff.count() << " ms" << std::endl;
	std::cout << std::endl;



	return 0;
}

