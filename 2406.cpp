// Questão: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int,vector<int>,greater<int>> pq;

        int start;
        int end;
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

        return pq.size();
    }
};