#include <iostream>
using namespace std;


void af(int& g)
{
    g++;
    cout<<g;
}

int main()
{
    int g = 123;
    cout << g;
    af(g);
    cout << g;
    return 0;
}
