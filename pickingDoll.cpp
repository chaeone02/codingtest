#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    
    // 열 기준으로 스택 만들기
    vector<vector<int>> cols(n);
    
    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >= 0; i--) {
            if (board[i][j] != 0) {
                cols[j].push_back(board[i][j]);
            }
        }
    }
    
    vector<int> basket;
    int answer = 0;
    
    // 인형 뽑기 시행
    for (int k : moves) {
        if (cols[k-1].empty()) continue;
        
        int doll = cols[k-1].back();
        cols[k-1].pop_back();
        
        // 터지는 경우 -> 바스켓에 넣지 말고 바로 제거
        if (!basket.empty() && basket.back() == doll) {
            basket.pop_back();
            answer += 2;
        } else {
            basket.push_back(doll);
        }
    }
    
    return answer;
}


// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// int solution(vector<vector<int>> board, vector<int> moves) {
    
//     int n = board.size();
//     vector<vector<int>> board2(n);
//     vector<int> answers;
    
//     // 벡터 행렬 변환
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++) {
//             if (board[i][j] != 0) board2[j].push_back(board[i][j]);
//         }
//     }
    
//     // 크레인 작동
//     for (int k : moves){
//         if (!(board2[k-1].empty())){
//             answers.push_back(board2[k-1][0]);
//             board2[k-1].erase(board2[k-1].begin()); 
//         }   
//     }
        
 
//     int answerCount = 0;

// for (int l = 1; l < answers.size(); ) {
//     if (answers[l] == answers[l-1]) {
//         answerCount += 2;
//         answers.erase(answers.begin() + l);     // 뒤 먼저 삭제
//         answers.erase(answers.begin() + (l-1)); // 앞 삭제
//         l--; // 다시 체크
//     } else {
//         l++;
//     }
// }
    

//     return answerCount;
// }