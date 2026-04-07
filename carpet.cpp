#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow; // == w*h

    // 세로 후보: 1 ~ total 제곱근 까지
    for (int height = 1; height <= sqrt(total); height++) {
        if (total % height != 0) continue;  // 가로 세로 후보가 나누어 떨어져야 함!!
        int width = total / height;

        // 노란색 영역 = (width-2) * (height-2)
        if ((width - 2) * (height - 2) == yellow) {
            return { max(width, height), min(width, height) };
        }
    }
    return {};
}




// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
    
//     int N; int M;
//     int sum = (brown + 4) / 2; -> 이렇게 풀어서 쓸 필요 없음
//     int times = (yellow + brown);
//     for (int i = 2; i < (sum - 1); i++){
//         N = i; M = sum - i;
//         if ((N * M) == times) break;
//     }
//     answer.push_back(max(M,N));
//     answer.push_back(min(M,N));
    
    
//     return answer;
// }