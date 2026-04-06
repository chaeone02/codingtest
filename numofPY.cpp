#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int yCount = 0, pCount = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'y') yCount++;
        if (c == 'p') pCount++;
    }
    return (yCount == pCount);
}

// 깔끔한 풀이 - 변수 하나로 해결
// int count = 0;
// for (char c : s) {
//     c = tolower((c));
//     if (c == 'p') count++;
//     else if (c == 'y') count--;
// }
// return count == 0;