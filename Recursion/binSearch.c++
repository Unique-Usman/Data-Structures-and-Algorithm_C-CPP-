#include <bits/stdc++.h>

using namespace std;

int bin(int arr[], int target, int start, int end)
{
	int mid = (start + end) / 2;
	if (start > end)
		return -1;
	else if (arr[mid] > target)
		return bin(arr,target, start, mid - 1);
	else if (arr[mid] < target)
		return bin(arr,target, mid + 1, end);
	return mid;

}
int main()
{
	int arr[] = {1,2,3,5,6,88};
	cout << bin(arr, 20, 0, sizeof(arr)/ sizeof(arr[0]) - 1);
}
