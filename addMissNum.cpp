#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    
    for (int i : numbers){
        auto it = find(v.begin(), v.end(), i);
        if (it != v.end()) v.erase(it);
    }
    
    for (int a : v) answer+=a;
    return answer;
}

// 핵심 : 전체합 45에서 있는 숫자들 빼기
// for (int n : numbers) sum -= n;