#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        workers.reserve(n);
        for (int i = 0; i < n; ++i)
            workers.emplace_back((double)wage[i] / quality[i], quality[i]);

        sort(workers.begin(), workers.end());

        priority_queue<int> topQ;   // guarda as maiores qualidades
        long long sumQ = 0;
        double ans = numeric_limits<double>::infinity();

        for (auto& [ratio, q] : workers) {
            topQ.push(q);
            sumQ += q;

            if ((int)topQ.size() > k) {
                sumQ -= topQ.top();
                topQ.pop();
            }

            if ((int)topQ.size() == k) {
                ans = min(ans, ratio * (double)sumQ);
            }
        }
        return ans;
    }
};