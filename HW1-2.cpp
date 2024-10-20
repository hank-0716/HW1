#include<iostream>
#include<math.h>
#include<time.h>

using namespace std;

void powerset(int* set, int set_size) {
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	for (counter = 0; counter < pow_set_size; counter++) {
		cout << "{";
		for (j = 0; j < set_size; j++) {
			if (counter & (1 << j))
				cout << set[j]<<" ";
		}
		cout << " }" << endl;
	}
}

int main(){
	cout << "輸入集合大小" << endl;
	int n;
	while (cin >> n) {
		int* set = new int[n];
		for (int i = 0; i < n; i++) {
			set[i] = i + 1;
		}

		clock_t start = clock();
		powerset(set, n);

		clock_t end = clock();
		double duration = double(end - start) / CLOCKS_PER_SEC;
		cout << "運行時間: " << duration << " 秒" << endl;
	}

	return 0;
}