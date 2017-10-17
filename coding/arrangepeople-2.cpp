/*
 find the min number and distance to the last position. ret = min*n + distance
*/
// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int distance(int fpos, int lpos, int length) {
	return fpos <= lpos ? lpos - fpos : length - fpos + lpos;
}
void arrange(int arr[], int last_pos, int length) {
	//find min and index
	int min = arr[0];
	int index = 0;
	for (size_t i = 1; i < length; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
			index = i;
		}
	}
	int tol = length*min + distance(index+1, last_pos, length);
	for (size_t i = 0; i < length; i++)
	{
		if (i == index) {//index = total
			arr[i] = tol;
		}
		else if(distance(i+1,last_pos, length)<= tol%length ){//dis <= tol%length
			arr[i] -= min + 1;
		}
		else {//dis == index

			arr[i] -= min;
		}
	}
	return;
}

int main()
{
	int n, x;
	int ret = 0;
	cin >> n >> x ;
	int *array = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	arrange(array, x, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;

	return 0;
}

