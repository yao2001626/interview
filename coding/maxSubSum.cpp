#include <vector>
#include <iostream>
using namespace std;
int maxSubSum(std::vector<std::vector<int>> matrix, int n, int m) {
	int base_sum = 0;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			base_sum += matrix[i][j];
		}
	}
	int result = 0;
	for (unsigned int i = 0; i + n <= matrix[0].size(); i++) {
		if (i > 0) {
			for (int y = 0; y < m; y++) {
				base_sum += matrix[i + n - 1][y] - matrix[i - 1][y];
			}
		}
		int real_sum = base_sum;
		if (real_sum > result) {
			result = real_sum;
		}
		for (unsigned int j = 1; j + m <= matrix.size(); j++) {
			for (unsigned int x = i; x < i+n; x++) {
				real_sum += matrix[x][j + m - 1] - matrix[x][j - 1];
			}
			if (real_sum > result) {
				result = real_sum;
			}
		}
	}
	return result;
}
int main() {
	vector<vector<int>> matrix;
	vector<int> row;
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			row.push_back(rand()%100);

		}
		matrix.push_back(row);
	}
	for (size_t i = 0; i < 100; i++)
	{
		for (size_t j = 0; j < 100; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	cout << maxSubSum(matrix, 20, 20) << endl;
	return 0;
}
