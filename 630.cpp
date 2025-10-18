// Questão: https://leetcode.com/problems/course-schedule-iii/?envType=problem-list-v2&envId=greedy


// Implementacao com adaptacao do Scheduling to Minimize Lateness
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        // ordenacao do vetor de cursos pelo deadline
        std::sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int day = 0;
        int qnt = 0;
        priority_queue<int> pq;
        int top;

        // passa por cada curso e adiciona a duracao na variavel dia. Se ultrapassar do tempo, retira o curso com maior duracao
        for(auto& i:courses) {
            day += i[0];
            pq.push(i[0]);
            if(day > i[1]) {
                top = pq.top();
                pq.pop();
                day -= top;
            }
        }

        return pq.size();
    }
};