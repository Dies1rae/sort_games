#pragma once
#include <vector>
#include <random>
#include <iostream>

int irnd(int a){
	srand(a);
	long rnd_hld = rand();
	return (((rnd_hld = rnd_hld * 214013L + 2531011L) >> 16) & 0x7fff);
}
 std::vector<int> do_rnd_bse_() {
	std::vector<int> res;
	for (int ptr = 0; ptr < 500; ptr++) {
		int tmp = irnd(ptr);
		res.push_back(tmp);
	}
	return res;
}
