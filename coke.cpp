#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, share = 0, remainder = 0;

    while (n >= a) {
        int new_coke = (n / a) * b;
        answer += new_coke;
        n = n % a + new_coke;
    }
    return answer;
}