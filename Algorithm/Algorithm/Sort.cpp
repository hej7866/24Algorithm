#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int list[], int n)
{
	// n번 반복
	for (int i = n - 1; i > 0; i--)
	{
		// j번 비교 반복
		for (int j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}

void bubbleExample()
{
	int list[] = { 7, 3, 5, 9, 6 };
	bubbleSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << list[i] << " ";
	}

	cout << "\n";
}

void bubbleSort2(int list[], int n)
{
	// n번 반복
	for (int i = 0; i < n - 1; i++)
	{
		// j번 비교 반복
		for (int j = 0; j < n - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}

void bubbleExample2()
{
	int list[] = { 7, 3, 5, 9, 6 };
	bubbleSort2(list, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << list[i] << " ";
	}

	cout << "\n";
}

void selectionSort(int list[], int n)
{
	int least;
	for (int i = 0; i < n; i++)
	{
		least = i;
		for (int j = i + 1; j < n; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}

		if (least != i)
		{
			swap(list[i], list[least]);
		}
	}
}

void selectionExample()
{
	int list[] = { 7, 3, 5, 9, 6 };
	bubbleSort(list, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << list[i] << " ";
	}

	cout << "\n";
}

void insertionSort(int list[], int n)
{
	int j;
	for (int i = 0; i < n - 1; i++)
	{
		j = i;
		while (list[j] > list[j + 1] && j >= 0)
		{
			swap(list[j], list[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << list[i] << " ";
	}
}

void insertionExample()
{
	int list[7] = { 1, 10, 5, 9, 7, 6, 4 };

	insertionSort(list, 7);
	cout << "\n";
}


void countSort(vector<int> array, vector<int> count)
{
	for (int i = 0; i < array.size(); i++)
	{
		count[array[i]]++;
	}

	// count의 인덱스 번호가 숫자가되고 값이 크기가 되는것
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
			{
				cout << i << " ";
			}
		}
	}
}

void countExample()
{
	vector<int> array = { 3,0,4,1,0,4 };
	auto max_it = max_element(array.begin(), array.end());
	int max = *max_it;
	vector<int> count(max + 1,0);
	
	countSort(array, count);
	cout << "\n";
}