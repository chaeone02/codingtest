#include <string>

using namespace std;

string solution(string phone_number) {
    int n = phone_number.size();
    return string(n-4,'*') + phone_number.substr(n-4);
}
// string solution(string phone_number) {
//     string answer = "";
//     for (int i = 0; i < phone_number.size(); i++){
//         if (i >= (phone_number.size()-4)) 
//             answer += phone_number[i];
//         else answer+='*';
//     }
//     return answer;
// }