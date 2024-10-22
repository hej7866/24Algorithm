#pragma once

#include <iostream>
#include <chrono>

using namespace std;

template<typename Func, typename... Args>
double measureExecutionTime(Func func, Args&... args)
{
	auto start = chrono::high_resolution_clock::now();
	func(forward<Args>(args)...);
	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	return duration.count() / 1000.0; 
}

