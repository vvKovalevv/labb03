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


    void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {

    cout << "</svg>\n";
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


void svg_text(double left, double baseline, string text)
{
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}

void svg_rect(double x, double y, double width, double height,string stroke, string fill)
{
    cout<< "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<< "' fill='"<<fill<<"'/>";
}

void show_histogram_svg(const vector<size_t>& bins, size_t& number_count)
{
    const size_t MAX_ASTERISK=30;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto WIDTH_TO_PROCENT = 370;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    unsigned max_count=0;
    for (size_t b : bins) /* мы присваиваем значение количества элементов */
    {
        if(max_count<b)
            max_count=b;
    }
    for (size_t bin : bins)
    {
        size_t height=30;
        if(max_count>MAX_ASTERISK) /* Если количество будет больше 35, то уменьшаем масштаб*/
            height=MAX_ASTERISK*((static_cast<double>(bin))/max_count); /* это для того,чтобы было дробное число , получаем, используя "static_cast<double>"*/
        else
        {
            height=bin;
        }
        height = BLOCK_WIDTH * height;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, height, BIN_HEIGHT, "black", "yellow");
        top += BIN_HEIGHT;
    }
    svg_end();
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
     show_histogram_svg(bins,number_count);
    return 0;
}
