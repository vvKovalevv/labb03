#include <iostream>
#include <vector>
#include <conio.h>
#include<curl/curl.h>
#include "histogram.h"
#include "svg.h"
#include<sstream>

using namespace std;

vector<double> input_numbers(istream& in, size_t count)
{
    vector <double> result(count);
    for (int i=0; i<count; i++)
    {
        in>>result[i];

#include <string>
#include "histogram.h"
#include "svg.h"
#include <cstdio>
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


Input
read_input(istream& in, bool prompt )
{
    Input Input;
    size_t number_count;

    if (prompt)
    {
        cerr << "Enter number count: ";
        in >> number_count;

        cerr << "Enter numbers: ";
        Input.numbers = input_numbers(in, number_count);

        cerr << "Enter bin count: ";
        in >> Input.bin_count;
    }
    else
    {
        in >> number_count;
        Input.numbers = input_numbers(in, number_count);
        in >> Input.bin_count;
    }
    return Input;
}
size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx)
 {
    const size_t data_size = item_size * item_count;
    const char* new_items = reinterpret_cast<const char*>(items);
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(new_items, data_size);
    return data_size;
}


vector<size_t>
make_histogram( struct Input Input)
{
vector<size_t> bins(Input.bin_count, 0);

double min;
double max;
find_minmax(Input.numbers, min, max);
for(double x: Input.numbers)
{
size_t bin_index=(x-min)/(max-min)*Input.bin_count;
if (bin_index==Input.bin_count)
{
bin_index--;
}
bins[bin_index]++;
}
return bins;
}

Input
download(const string& address)
{
    stringstream buffer;
curl_global_init(CURL_GLOBAL_ALL);
 CURL *curl = curl_easy_init();
 if(curl)
{
CURLcode res;
curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
 res = curl_easy_perform(curl);
  if (res != CURLE_OK)
  {
     cout << curl_easy_strerror(res) << endl;
     exit(1);
  }
  curl_easy_cleanup(curl);
}
 return read_input(buffer, false);
}

 int main(int argc, char* argv[])
{
    Input input;

    if (argc > 1)
    {
                input = download(argv[1]);
}
        else {
         input = read_input(cin, true);
        }


    const auto bins = make_histogram (input);
    show_histogram_svg(bins,input.bin_count);
    return 0;

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
   /* printf("WinVersion  %x\n", GetVersion());
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
    printf("build is %u.\n", platform);
if ((info & 0x40000000) == 0)
{
  DWORD build = platform;
  printf("Windows build is %u.\n", build);
}
*/
/*char system[MAX_COMPUTERNAME_LENGTH + 1];

    DWORD Size = sizeof(system);
    GetComputerNameA(system, &Size);
    printf("System: %s", system);*/

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
