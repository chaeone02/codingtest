#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int maxNum = nums.size()/2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return min((int)nums.size(), maxNum);
}

// 정렬 및 unique 불필요, set 사용
// int solution(vector<int> nums)
// {
//     unordered_set<int> s(nums.begin(), nums.end());
//     return min((int)s.size(), nums.size() / 2);
// }