#include "vector.hpp"
#include <iostream>
// #include <vector>

int main() {
	voidhoge::vector<int> hoge;
	for (int i = 0; i < 1<<10; i++) {
		hoge.push_back(i);
	}
	std::cout << hoge << '\n';
	return 0;
}
