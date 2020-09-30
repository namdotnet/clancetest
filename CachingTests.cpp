#include <iostream>
#include <time.h>

#define ROWS 10000
#define COLS 10000

int m[ROWS][COLS];

void calculate_sum(long long& sum, int order)
{
    sum = 0;
    if (order == 0) {
        for (unsigned r = 0; r < ROWS; ++r) {
            for (unsigned c = 0; c < COLS; ++c) {
                sum += m[r][c];
            }
        }
    }
    else {
        for (unsigned c = 0; c < COLS; ++c) {
            for (unsigned r = 0; r < ROWS; ++r) {
                sum += m[r][c];
            }
        }
    }
}

int main()
{
    long long sum;
    std::cout << "Summing by rows... ";

    clock_t start = clock();
    calculate_sum(sum, 0); // rows major
    clock_t delta_by_rows = clock() - start;
    std::cout << delta_by_rows << " ticks" << "\n";

    std::cout << "Summing by columns... ";

    start = clock();
    calculate_sum(sum, 1); // columns major
    clock_t delta_by_columns = clock() - start;
    std::cout << delta_by_columns << " ticks" << "\n";

}

