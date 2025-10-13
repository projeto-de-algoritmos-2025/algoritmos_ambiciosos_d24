class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers; // (ratio, quality)
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        // TODO: ordenar por ratio e montar lógica de seleção
        return 0.0;
    }
};