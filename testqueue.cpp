#include <chrono>
#include "binary.h"
using namespace std;
using namespace std::chrono;

/* 
    Test your code here - measure the difference in time to show that
    the queue implementation is faster!
*/
int main()
{
    // An example of measuring the time it takes for an algorithm to execute
    auto start = high_resolution_clock::now(); // time before cout
    cout << "hello!" << endl;
    auto stop = high_resolution_clock::now(); // time after cout

    auto diff = duration_cast<nanoseconds>(stop-start); // get difference
    cout << diff.count();
}