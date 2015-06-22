/*
* # 204
* Count Primes
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // array index from 0 to n-1, represent number 0 to n-1 is sum number or not
        // please ignore 0 and 1
        bool *arr = new bool[n];
        // calculate all sum numbers
        for (int i = 2; i*i < n; i++) {
            if (!arr[i]) {
                for (int j = i; i*j < n ;j++) {
                    arr[i*j] = true;
                }
            }
        }
        int count = 0;
        // take values from 2 to n-1, check whether it is prime(false value)
        for (int i = 2; i < n; i++) {
            if (!arr[i]) count++;
        }
        delete[] arr;
        return count;
    }
};

int main(int args, char* argv[]) {
    Solution *s = new Solution();
    int n = (args > 1) ? atoi(argv[1]) : 3;
    cout << n << ": " << s->countPrimes(n) << endl;
    delete s;
    return 0;
}
