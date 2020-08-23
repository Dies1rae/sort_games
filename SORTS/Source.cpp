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
	while (ptrL <= ptrR) {
		while (main[ptrL] < mid_) {
			ptrL++;
		}
		while (main[ptrR] > mid_) {
			ptrR--;
		}
		if (ptrL <= ptrR) {
			swap_(main[ptrL++], main[ptrR--]);
		}
	} 
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
		main[ptr] = tmp_array[ptr - B];
	}
	
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


	return 0;
}

