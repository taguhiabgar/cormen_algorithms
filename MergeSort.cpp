#include <iostream>
#include <vector>

using namespace std;

// Merge Sort
// "Introduction to Algorithms", page 56
vector<int> mergeSort(vector<int>);
vector<int> combine(vector<int>, vector<int>);
void testMergeSort();

int main() {
	testMergeSort();
	return 0;
}

void testMergeSort() {
	vector<int> vec = {5, 4, 8, 2, 1, 7};
	vector<int> sorted = mergeSort(vec);
	for (int i = 0; i < sorted.size(); i++) {
		cout << sorted[i] << ' ';
	}
	cout << endl;
}

// divides vector into to parts and sorts them recursively
vector<int> mergeSort(vector<int> vec) {
	if(vec.size() <= 1) {
		return vec;
	}
	vector<int>::iterator middle = vec.begin() + vec.size() / 2;
	vector<int> left = vector<int>(vec.begin(), middle);
	vector<int> right = vector<int>(middle, vec.end());
	return combine(mergeSort(left), mergeSort(right));
}

// merges sorted vectors first and second
vector<int> combine(vector<int> first, vector<int> second) {
	vector<int> combined;
	int flag1 = 0;
	int flag2 = 0;
	while(combined.size() < first.size() + second.size()) {
		if (flag1 >= first.size()) {
			combined.push_back(second[flag2++]);
			continue;
		}
		if (flag2 >= second.size()) {
			combined.push_back(first[flag1++]);
			continue;
		}
		if (first[flag1] < second[flag2]) {
			combined.push_back(first[flag1++]);
		} else {
			combined.push_back(second[flag2++]);
		}
	}
	return combined;
}


