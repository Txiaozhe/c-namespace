// range_for.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto &i : v)
        i *= i;
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
