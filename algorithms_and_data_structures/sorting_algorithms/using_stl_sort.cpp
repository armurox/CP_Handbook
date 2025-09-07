#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

void print_vector(std::vector<int> v);

// User defined struct for sorting by first the x coordinate, and then the y
struct P
{
    int x, y;
    bool operator< (const P &p) const
    {
        return ((x != p.x) ? x < p.x : y < p.y);
    }
};

// Comparison function which compairs strings by size, then alphabet
bool comp(std::string s1, std::string s2)
{
    return (s1.size() != s2.size()) ? s1.size() < s2.size() : s1 < s2;
}

int main(void)
{
    // Lets start with basic sort of a vector
    std::vector<int> v = {4, 2, 8, 3, 6, 3, 1, 2, 5};
    std::sort(v.begin(), v.end());
    print_vector(v);
    // // Reverse sort
    std::sort(v.rbegin(), v.rend());
    print_vector(v);

    // Lets sort pairs now, they sort by first element, then second
    std::vector<std::pair<int, int>> v1;
    v1.push_back({1,5});
    v1.push_back({2,3});
    v1.push_back({1,2});
    std::sort(v1.begin(), v1.end());
    for (std::vector<std::pair<int, int>>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << '(' << it -> first << ' ' <<  it -> second << ") ";
    std::cout << '\n';

    // Reverse sort
    std::sort(v1.rbegin(), v1.rend());
    for (std::vector<std::pair<int, int>>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << '(' << it -> first << ' ' <<  it -> second << ") ";
    std::cout << '\n';

    std::vector<struct P> v2;
    struct P p1 = {1, 2};
    struct P p2 = {1, 4};
    struct P p3 = {4, 5};
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    // Lets sort our defined struct P now
    std::sort(v2.begin(), v2.end());
    for (std::vector<struct P>::iterator it = v2.begin(); it != v2.end(); ++it)
        std::cout << "P (" << it -> x << ' ' <<  it -> y << ") ";
    std::cout << '\n';

    // Lets apply our string sort to a set of functions now
    std::vector<std::string> v3 = {"hello", "zob", "bobby", "123"};
    std::sort(v3.begin(), v3.end(), comp);
    for (std::vector<std::string>::iterator it = v3.begin(); it != v3.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';


}


void print_vector(std::vector<int> v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}