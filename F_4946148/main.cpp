#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

void factorize(unsigned long base, std::map<unsigned long, int> &fact) {

	for (unsigned val, ord, end = 0, i = 2; !end; ++ i) {
		if (i <= base / i) {
			if (base % i != 0) continue;
			val = i;
			ord = 1;
			while ((base /= i) % i == 0) ord += 1;
		}
		else {
			if (base == 1) break;
			val = base;
			ord = 1;
			end = 1;
		}
		fact[val] += ord;
	}
}

int main() {

	std::map<unsigned long, int> upper, lower;

	std::ifstream inp("input.txt");
	int num; inp >> num;
	for (int i = 0; i < num; ++ i) {
		unsigned long A, B; inp >> A >> B;
		factorize(A, upper);
		factorize(B, lower);
	}

	for (auto &itl: lower) {
		auto itu = upper.find(itl.first);
		if (itu == upper.end()) break;
		auto ord = std::min(
			itl.second, itu->second
		);
		itu->second -= ord;
		itl.second -= ord;
	}

	int cu2 = std::count_if(
		upper.begin(), upper.end(), [](const auto &it) { return it.second > 1; }
	);
	int cu1 = std::count_if(
		upper.begin(), upper.end(), [](const auto &it) { return it.second; }
	);
	int cl = std::any_of(
		lower.begin(), lower.end(), [](const auto &it) { return it.second; }
	);
	int ans = ((cl == 0)? (((cu1 <= 1) && !cu2)? (0): (1)): (2));

	std::ofstream out("output.txt");
	out << ans;

	return 0;
}
