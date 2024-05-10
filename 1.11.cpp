#include <iostream> 
#include <string>
using namespace std;

class nodefile
{
public:
    nodefile* next;
    string data;

    nodefile()
    {
        next = NULL;
    }
};

class nodecommit
{
public:
    nodecommit* next;
    string message;
    int number;

    nodecommit()
    {
        next = NULL;
    }
};