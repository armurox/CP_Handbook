#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> v = {-1, 2, 4, -3, 5, 2, -5, 2};
    // Compute maximum subarray
    int best = 0;
    size_t size = v.size();
    int curr_sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        curr_sum = std::max(v[i], curr_sum + v[i]);
        best = std::max(curr_sum, best);
    }

    std::cout << best << '\n';
}
