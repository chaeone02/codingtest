#include <string>
#include <vector>
using namespace std;

int answer = 0;

// 인덱스 증가하며, 인덱스 값을 더하거나 빼가며 누적합
// 순서를 바꿔가며 탐색하는게 X -> visited X
void dfs(vector<int>& numbers, int target, int index, int sum) {
    if (index == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, index + 1, sum + numbers[index]);
    dfs(numbers, target, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
