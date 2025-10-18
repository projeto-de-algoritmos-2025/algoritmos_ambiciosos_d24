// Questão: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

// Implementacao utilizando Interval Partitioning
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        // ordenacao do vetor de intervalos pelo left
        sort(intervals.begin(), intervals.end());

        // inicializacao da heap
        priority_queue<int,vector<int>,greater<int>> pq;

        int start;
        int end;

        // percorre o vetor e vai atualizando a heap
        for(auto& i:intervals) {
            start = i[0];
            end = i[1];

            int earlier;
            if(!pq.empty()) {
                earlier = pq.top();
                if(earlier < start) {
                    pq.pop();
                }
            }

            pq.push(end);
        }

        // retorna a quantidade de elementos da heap
        return pq.size();
    }
};