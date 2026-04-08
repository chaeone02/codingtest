#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // pair 활용하여 좌표값을 지정
    vector<pair<int,int>> pos(12);
    pos[1] = {0,0}; pos[2] = {0,1}; pos[3] = {0,2};
    pos[4] = {1,0}; pos[5] = {1,1}; pos[6] = {1,2};
    pos[7] = {2,0}; pos[8] = {2,1}; pos[9] = {2,2};
    pos[0] = {3,1}; pos[10] = {3,0}; pos[11] = {3,2}; // *->10, #->11
    
    int left = 10;
    int right = 11;
    
    for(int num : numbers){
        if(num == 1 || num == 4 || num == 7){
            answer += 'L';
            left = num;}
        else if (num == 3 || num == 6 || num == 9){
            answer += 'R';
            right = num;}
        else {
            // pair 구조 활용한 거리계산
            int left_dist = abs(pos[left].first - pos[num].first) + abs(pos[left].second - pos[num].second);
            int right_dist = abs(pos[right].first - pos[num].first) + abs(pos[right].second - pos[num].second);
            
            if (left_dist < right_dist) {
                answer += 'L';
                left = num;}
            else if (left_dist > right_dist) {
                answer += 'R';
                right = num;}
            else {
                if (hand == "left") {answer += 'L'; left = num;}
                else {answer += 'R'; right = num;}
            }
        }
    }

    return answer;
}