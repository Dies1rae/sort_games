#include "BASE.h"
#include <iostream>
#include <vector>

template <typename T>
void show_container_(const std::vector<T> main) {
	for (const auto& ptr : main) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;
}
template <typename T>
void swap_(T& a, T& b) {
	T tmp_ = a;
	a = b;
	b = tmp_;
}

template <typename T>
std::vector<T> buble_sort_(std::vector<T> main) {
	for (int ptrL = 0; ptrL < main.size(); ptrL++) {
		for (int ptrR = ptrL+1; ptrR < main.size(); ptrR++) {
			if (main[ptrL] > main[ptrR]) {
				swap_(main[ptrL], main[ptrR]);
			}
		}
	}
	return main;
}

template <typename T>
void binary_sort_(std::vector<T>& main, int L, int R) {
	int ptrL = L, ptrR = R;
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




int main() {

	std::cout << "1)NO SORT:" << std::endl;
	show_container_(BASE);
	std::cout << std::endl;
	std::cout << "2)BUBLE_SORT_ ALGO:" << std::endl;
	show_container_(buble_sort_(BASE));
	std::cout << std::endl;
	std::cout << "3)BINARY_SORT_ ALGO:" << std::endl;
	std::vector<int>res(BASE.begin(), BASE.end());
	int L = 0;
	int R = res.size() - 1;
	binary_sort_(res, L, R);
	for (const auto& ptr : res) {
		std::cout << ptr << ' ';
	}
	std::cout << std::endl;

	return 0;
}

