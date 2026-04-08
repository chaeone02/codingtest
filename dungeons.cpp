#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 모든순열 기반 brute force로 풀음
int solution(int k, vector<vector<int>> dungeons) {
    // vector<int> answer; -> 불필요
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());
    do{
        int count = 0;
        int k_copy = k;
        for (int i = 0; i < dungeons.size(); i++) {
            if (dungeons[i][0] <= k_copy) {
                count++;
                k_copy -= dungeons[i][1];}
        }
        answer = max(answer, count);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}


// DFS로 푸는 법
int answer = 0;
void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count) {
    answer = max(answer, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;

            dfs(k - dungeons[i][1], dungeons, visited, count + 1);

            visited[i] = false; // 백트래킹
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);

    dfs(k, dungeons, visited, 0);

    return answer;
}