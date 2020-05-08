#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <iostream>
#include<vector>
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
void find_minmax (const vector<double>& numbers, double& min, double& max);

#endif // HISTOGRAM_H_INCLUDED
