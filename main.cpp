#include <iostream>
#include "histogram.h"
#include <vector>
#include "svg.h"
#include <windows.h>
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
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
    printf("WinVersion  %x\n", GetVersion());
    printf("WinVersion  %u\n", GetVersion());

    DWORD mask = 0x0000ffff;
    DWORD mask_major = 0b00000000'00000000'00000000'11111111;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    printf("Windows decimal-version is %u.\n", version);
    printf("Windows 16x version is %x.\n", version);
    printf("Windows major version is %u.\n", version_major);
    printf("Windows minor version is %u.\n", version_minor);
    printf("build %u.\n", platform);

    size_t number_count;

    cerr << "Enter number count: ";

    cin >> number_count;

    const auto numbers=input_numbers(number_count);
    size_t bin_count;

    cerr << "Enter column count: ";

    cin >> bin_count;

    double min, max;
    find_minmax(numbers, min, max);


    const auto bins=make_histogram(numbers, max, min, bin_count);
    show_histogram_svg(bins,number_count);
    return 0;
}
