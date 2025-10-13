#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; ++i)
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap; // guarda as maiores qualidades
        long long sumQ = 0;
        double minCost = numeric_limits<double>::infinity();

        for (auto& [ratio, q] : workers) {
            maxHeap.push(q);
            sumQ += q;
            if ((int)maxHeap.size() > k) {
                sumQ -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == k) {
                minCost = min(minCost, ratio * sumQ);
            }
        }
        return minCost;
    }
};