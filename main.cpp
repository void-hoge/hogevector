#include "vector.hpp"
#include <iostream>
// #include <vector>

int main() {
	voidhoge::vector<int> hoge;
	for (int i = 0; i < 1<<10; i++) {
		hoge.push_back(i);
	}
	for (int i = 0; i < hoge.size(); i++) {
		std::cout << hoge.at(i) << ' ';
	}
	std::cout << '\n';
	return 0;
}
