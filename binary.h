#include "queue.h"
#include <string>
#include <cmath>

/*
    Given a number N, write a function that generates 
    and prints all binary numbers with decimal values 
    from 1 to N. This implementation should NOT use
    queues and run in O(N*log(N)) time.
*/
void printBinaryNaive(int n)
{
    int i = 1;
    while (i <= n){
        cout << i << ": ";
        int binary = 1;
        int num = 1;
        int counter = 0;
        int placeholder = i;
        while (binary * 2 <= placeholder){
            binary *= 2;
            counter += 1;
            num *= 10;
        }
        counter--;
        placeholder -= binary;
        for (int j = counter; j >= 0; j--){
            binary = pow(2, j);
            if (binary <= placeholder){
                num += pow(10, j);
                placeholder -= binary;
            } else if (placeholder == 1){
                num += 1;
                placeholder -= 1;
            }
        }
        cout << num << endl;
        i++;
    }
}

/*
    Given a number N, write a function that generates 
    and prints all binary numbers with decimal values 
    from 1 to N. This implementation should make use of
    queues such that it runs in O(N) time. 
*/
void printBinaryQueue(int n)
{
    Queue<int> q;
    q.Enqueue(1);
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        int a = q.Dequeue();
        cout << a;
        a *= 10;
        q.Enqueue(a);
        q.Enqueue(a + 1);
        
        cout << endl;
    }
}