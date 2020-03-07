#include<iostream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;

const int SIZE = 5;

//QUESTION 1
//Recursion fuction that calculate and return the sum of all digit in a string
int r_sum(string str, int size) {
	string temp;

	//Base case
	if (size < 1)
		return 0;
	//Recursion
	if (isdigit(str[size - 1])) {
		temp = str[size - 1];
		return stoi(temp) + r_sum(str, size - 1);
	}
	return r_sum(str, size - 1);
}

//QUESTION 2
//Print the array
void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Swap 2 elements
void swap(int &x, int &y) {
	int temp = y;
	y = x;
	x = temp;
}

//Create a copy array
void copy(int arr1[], int arr2[]) {
	for (int i = 0; i < SIZE; i++)
		arr2[i] = arr1[i];
}


//Return the pivot position
int partition(int arr[], int low, int high, int &exchanges, int &compares) {
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		compares++;
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
			exchanges++;
		}
	}
	exchanges++;
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

//Quick Sort
void quickSort(int arr[], int low, int high, int &exchanges, int &compares) {
	if (low < high) {
		int pi = partition(arr, low, high, exchanges, compares);
		quickSort(arr, low, pi - 1, exchanges, compares);
		quickSort(arr, pi + 1, high, exchanges, compares);
	}
}

//Merge and sort 2 sub-arrays
void merge(int arr[], int l, int m, int r, int &exchanges, int &compares) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector<int> L(n1), R(n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		compares++;
		if (L[i] <= R[j])
		{
			exchanges++;
			arr[k] = L[i];
			i++;
		}
		else
		{
			exchanges++;
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

//Merge Sort
void mergeSort(int arr[], int l, int r, int &exchanges, int &compares) {
	compares++;
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m, exchanges, compares);
		mergeSort(arr, m + 1, r, exchanges, compares);

		merge(arr, l, m, r, exchanges, compares);
	}
}

//Perform quick sort and output the number of exchanges and comparisons
void callQuickSort(int arr[], int low, int high, int exchanges, int compares) {
	int a_copy[SIZE];
	copy(arr, a_copy);

	//cout << "Before: " << endl;
	//print(a_copy, SIZE);
	quickSort(a_copy, 0, SIZE - 1, exchanges, compares);
	//cout << "After: " << endl;
	//print(a_copy, SIZE);

	cout << "Quick Sort:" << endl;
	cout << "\tExchanges: " << exchanges << endl;
	cout << "\tComparisons: " << compares << endl;
}

//Perform merge sort and output the number of exchanges and comparisons
void callMergeSort(int arr[], int low, int high, int exchanges, int compares) {
	int a_copy[SIZE];
	copy(arr, a_copy);

	//cout << "Before: " << endl;
	//print(a_copy, SIZE);
	mergeSort(a_copy, 0, SIZE - 1, exchanges, compares);
	//cout << "After: " << endl;
	//print(a_copy, SIZE);

	cout << "Merge Sort:" << endl;
	cout << "\tExchanges: " << exchanges << endl;
	cout << "\tComparisons: " << compares << endl;
}

int main() {

	string str;

	//QUESTION 1
	//Get string input
	cout << "Enter a string: ";
	getline(cin, str);
	cout << "Sum of all digit in the string: " << r_sum(str, str.length()) << endl;
	
	//QUESTION 2
	int a1[SIZE];
	int a2[SIZE];
	int a3[SIZE];
	int exchanges = 0;
	int compares = 0;
	//Push 1000 random numbers into each arrays
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		a1[i] = rand();
		a2[i] = rand();
		a3[i] = rand();
	}
	//Calculate number of comparisions and exchanges for each sorting algorithm
	cout << endl << "Array 1:" << endl;
	callQuickSort(a1, 0, SIZE, exchanges, compares);
	callMergeSort(a1, 0, SIZE, exchanges, compares);

	cout << endl << "Array 2:" << endl;
	callQuickSort(a1, 0, SIZE, exchanges, compares);
	callMergeSort(a1, 0, SIZE, exchanges, compares);

	cout << endl << "Array 3:" << endl;
	callQuickSort(a1, 0, SIZE, exchanges, compares);
	callMergeSort(a1, 0, SIZE, exchanges, compares);

	system("pause");
	return 0;
}