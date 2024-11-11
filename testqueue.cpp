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
    cout << "binary naive: " << endl;
    // An example of measuring the time it takes for an algorithm to execute
    auto start = high_resolution_clock::now(); // time before cout
    printBinaryNaive(20);
    auto stop = high_resolution_clock::now(); // time after cout

    auto diff = duration_cast<nanoseconds>(stop-start); // get difference
    cout << diff.count() << endl;

    cout << endl;
    
    cout << "binary queue: " << endl;
    auto start2 = high_resolution_clock::now(); // time before cout
    printBinaryQueue(20);
    auto stop2 = high_resolution_clock::now(); // time after cout

    auto diff2 = duration_cast<nanoseconds>(stop2-start2); // get difference
    cout << diff2.count() << endl;
}