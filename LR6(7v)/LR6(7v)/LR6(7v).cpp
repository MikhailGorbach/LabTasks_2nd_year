#include <iostream>
using namespace std;

template <class T> void FillArray(T* t, int number);
template <class T> void PrintArray(T* t, int number);
template <class T> T LargestValue(T* t, int number);

int main()
{
	cout << "Write the number of array elements (digits): ";
	int n = 0;
	cin >> n;
	int* a1 = new int[n];

	cout << "Now fill in the array:" << endl;
	FillArray(a1, n);

	cout << "Write the number of array elements (characters): ";
	int m = 0;
	cin >> m;
	char* a2 = new char[m];

	cout << "Now fill in the array:" << endl;
	FillArray(a2, m);

	cout << "Write the number of array elements (digits float): ";
	int k = 0;
	cin >> k;
	float* a3 = new float[k];	
	
	cout << "Now fill in the array:" << endl;
	FillArray(a3, k);

	system("pause");

	cout << "The largest elements of arrays: "
		<< LargestValue(a1, n) << ", "
		<< LargestValue(a2, m) << ", "
		<< LargestValue(a3, k) << endl;
	system("pause");
	return 0;
}
template <class T> void FillArray(T* t, int number)
{
	for (int i = 0; i < number; i++)
	{
		cin >> t[i];
	}
}
template <class T> void PrintArray(T* t, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << t[i] + " ";
	}
}
template <class T> T LargestValue(T* t, int number)
{
	T max = 0;
	for (int i = 0; i < number; i++)
	{
		if (t[i] > max) max = t[i];
	}
	return max;
}