#include <iostream>

using namespace std;

struct Process 
{
    struct Process* up;
    struct Process* down;
};