#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>


using namespace std;

array<int,5> list1 = {1,2,3,4,5};
array<int,8> list2 = {2,1,2,3,2,4,2,5};
array<int,10> list3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count1 = 0, count2 = 0, count3 = 0;
    // 하나로 관리, vector<int> count(3);
    
    for (int i = 0; i < answers.size(); i++){
        if (list1[i % list1.size()] == answers[i]) count1++;
        if (list2[i % list2.size()] == answers[i]) count2++;
        if (list3[i % list3.size()] == answers[i]) count3++;
        // count[0]++ 이런식으로 증가
    }
    int maxScore = max({count1, count2, count3});
    // 대신 *max_element(count.begin((), count.end());
    
    if (maxScore == count1) answer.push_back(1);
    if (maxScore == count2) answer.push_back(2);
    if (maxScore == count3) answer.push_back(3);
    // 대신 
    // for (int i = 0; i < 3; i++){
    //    if(maxScore==count[i]) answer.push_back(i+1); }
    
    return answer;
}