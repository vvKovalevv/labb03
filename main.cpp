#include <iostream>

#include <vector>
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

void
find_minmax( const vector<double>& numbers, double& min, double& max)
{
    min = numbers[0];
    for (double number : numbers)
    {

        if (number < min)
        {

            min = number;

        }

        if (number > max)
        {

            max = number;

        }

    }
}
vector<size_t>
make_histogram(const vector <double> &numbers,double &max, double &min, size_t &bin_count)
{

    vector<size_t>bins(bin_count,0); /* ������ �� �������� ������ */
    for(double x : numbers) /* �� ������� x ����������� ��������������� ������ ������� ������� "numbers" */


    {
        size_t bin_index=(size_t)((x-min)*bin_count/(max-min));
        if (bin_index==bin_count) /* ������ ������� "bin_index"*/
        {
            bin_index=bin_index-1; /* ��������� ���� � 0*/
        }
        bins[bin_index]++;

    }
    return bins;
}

 void show_histogram_text( const vector <size_t> &bins)
{
    size_t max_bin = bins[0];

    for (size_t bin:bins)
    {
        if (bin > max_bin)
        {

            max_bin=bin;
        }
    }

    if (max_bin > MAX_ASTERISK)
    {
        double factor = MAX_ASTERISK/static_cast<double>(max_bin);

        for (size_t bin:bins)
        {
            if (bin <100)
            {
                cout <<" ";
                if (bin < 10)
                {
                    cout <<" ";
                }
            }

            cout <<bin <<"|";

            size_t height = bin*factor;
            for(int i=0; i<height; i++)
            {
                cout<< "";
            }
            cout<<endl;
        }
    }
    else
    {
        for (size_t bin:bins)
        {
            if (bin <100)
            {
                cout <<" ";
                if (bin < 10)
                {
                    cout <<" ";
                }
            }

            cout <<bin <<"|";

            for (int i = 0; i < bin; i++)
            {
                cout << "*";
            }

            cout<<endl;
        }
    }

}

int main()
{

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
     show_histogram_text(bins);
    return 0;
}
