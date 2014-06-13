#include <iostream>
#include "rdstring.h"
using namespace std;

int main()
{
    rdstring romain("ccou"), nom(" dauby");
    rdstring dd(romain);
    romain = "romain";
    romain.erase(5, 1);
    cout << romain <<endl;
    return 0;
}
