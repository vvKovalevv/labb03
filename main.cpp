#include <iostream>
#include "histogram.h"
#include <vector>
#include "svg.h"
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double> input_numbers(istream& in, size_t count)
{
    vector <double> result(count);
    for (int i=0; i<count; i++)
    {
        in>>result[i];
    }
    return result;

}

vector<size_t>
make_histogram(const vector <double> &numbers,double &max, double &min, size_t &bin_count)
{

    vector<size_t>bins(bin_count,0); /* массив из индексов корзин */
    for(double x : numbers) /* мы каждому x присваиваем последовательно каждый элемент массива "numbers" */


    {
        size_t bin_index=(size_t)((x-min)*bin_count/(max-min));
        if (bin_index==bin_count) /* индекс корзины "bin_index"*/
        {
            bin_index=bin_index-1; /* нумирация идет с 0*/
        }
        bins[bin_index]++;

    }
    return bins;
}


int main()
{

    size_t number_count;

    cerr << "Enter number count: ";

    vector<double> input_numbers(istream& in, size_t count);



    const auto numbers=input_numbers(cin,number_count);
    size_t bin_count;

    cerr << "Enter column count: ";

    cin >> bin_count;

    double min, max;
    find_minmax(numbers, min, max);


     const auto bins=make_histogram(numbers, max, min, bin_count);
     show_histogram_svg(bins,number_count);
    return 0;
}
