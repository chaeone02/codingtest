#include <string>
#include <set>
using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int solution(string numbers) {
    set<int> primes;              // 중복 제거용
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();

    // 부분 문자열을 만들어 np1 ~ npn-1을 커버하고
    do {
        for (int len = 1; len <= n; len++) {
            string sub = numbers.substr(0, len);
            int num = stoi(sub);
            if (isPrime(num)) {
                primes.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end())); // npn 돌리기

    return primes.size();
}