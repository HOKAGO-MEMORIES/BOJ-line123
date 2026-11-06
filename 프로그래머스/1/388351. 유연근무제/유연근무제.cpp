#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int len = schedules.size();
    for (int i = 0; i < len; i++) {
        bool flag = true;
        int day = startday;
        
        int start = schedules[i];
        int s_hour = start / 100;
        int s_min = start % 100;
                
        int e_hour = s_hour;
        int e_min = s_min + 10;
        if (e_min >= 60) {
            e_min %= 60;
            e_hour++;
        }
        
        for (int j = 0; j < 7; j++) {
            if (day > 7) day = 1;
            if (day >= 1 && day <= 5) {
                int cur_hour = timelogs[i][j] / 100;
                int cur_min = timelogs[i][j] % 100;
                if ((cur_hour == e_hour && cur_min > e_min) ||
                   cur_hour > e_hour) {
                    flag = false;
                    break;
                }
            }
            day++;
        }
        
        if (flag) answer++;
    }
    
    return answer;
}