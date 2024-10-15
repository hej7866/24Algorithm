#include "Sort.h"
#include <algorithm>
#include <iostream>

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
