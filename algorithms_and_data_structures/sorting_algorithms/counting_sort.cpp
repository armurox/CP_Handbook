// Program that demonstrates an O(n) sorting algorithm, given that the maximum element is known.
// Tradeoff is a large amount of space complexity
#include <iostream>
#include <vector>

int find_max(std::vector<int> v);
std::vector<int> construct_vector(int size);
std::vector<int> construct_bookkeeping_vector(std::vector<int> v);
std::vector<int> construct_sorted_vector(std::vector<int> bookkeep);
void print_vector(std::vector<int> v1);

int main(void)
{
    int t{};
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n{};
        std::cin >> n;

        std::vector<int> v = construct_vector(n);

        std::vector<int> bookkeep = construct_bookkeeping_vector(v);

        std::vector<int> v1 = construct_sorted_vector(bookkeep);

        print_vector(v1);
    }
}



int find_max(std::vector<int> v)
{
    int max{(v.size() == 0) ? 0 : v[0]};
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        max = (*it > max) ? *it : max;
    return max;
}

std::vector<int> construct_vector(int size)
{
    int temp{};
    std::vector<int> v{};
    for (int j = 0; j < size; j++)
    {
        std::cin >> temp;
        v.push_back(temp);
    }
    return v;
}

std::vector<int> construct_bookkeeping_vector(std::vector<int> v)
{
    std::vector<int> bookkeep(find_max(v), 0);
    for (size_t j = 0; j < v.size(); j++)
    {
        bookkeep[v[j] - 1] += 1;
    }

    return bookkeep;
}

std::vector<int> construct_sorted_vector(std::vector<int> bookkeep)
{
    std::vector<int> v1;
    for (size_t j = 0; j < bookkeep.size(); j++)
    {
        while (bookkeep[j] > 0)
        {
            v1.push_back(j + 1);
            bookkeep[j]--;
        }
    }

    return v1;
}

void print_vector(std::vector<int> v1)
{

    for (size_t j = 0; j < v1.size(); j++)
    {
        std::cout << v1[j] << ' ';
    }

    std::cout << '\n';
}
