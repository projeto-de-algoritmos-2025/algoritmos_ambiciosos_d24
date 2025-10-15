// Questão: https://leetcode.com/problems/course-schedule-iii/?envType=problem-list-v2&envId=greedy

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end());

        std::sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int day = 0;
        int qnt = 0;
        for(auto& i:courses) {
            day += i[0];
            if(day <= i[1]) {
                qnt++;
            } else {
                break;
            }
        }

        return qnt;
    }
};