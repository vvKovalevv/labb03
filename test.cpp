#include "histogram.h"

#include <cassert>
#include "histogram.h"
#include "block_width.h"
#include <cassert>

void
test_1homework_3()
{
    double BLOCK_WIDTH=2;
    int flag=1;
    block_width(BLOCK_WIDTH, flag);
    assert(flag == 1);
}
void
test_2homework_30()
{
    double BLOCK_WIDTH=40;
    int flag=1;
    block_width(BLOCK_WIDTH, flag);
    assert(flag == 1);
}

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void
test_negative()
{
  double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void
test_same()
{
  double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_one()
{
  double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_nul()
{
    double min = 0;
    double max = 0;
    find_minmax({}, max, min);
    assert(min == 0);
    assert(max == 0);
}

int
main()
{
    test_1homework_3();
    test_2homework_30();
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_nul();
}


