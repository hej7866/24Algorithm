#pragma once
#include <vector>

using namespace std;

void MergeSort(int list[], int left, int right);
void Merge(int list[], int left, int mid, int right);

int QuickSelect(vector<int>& nums, int k);
void QuickSort(vector<int>& nums, int begin, int end);