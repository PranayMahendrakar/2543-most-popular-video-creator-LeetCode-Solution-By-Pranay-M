class Solution {
    public:
        vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
                unordered_map<string, long long> popularity;
                        unordered_map<string, pair<int, string>> bestVideo;
                                int n = creators.size();
                                        long long maxPop = 0;
                                                for (int i = 0; i < n; i++) {
                                                            popularity[creators[i]] += views[i];
                                                                        maxPop = max(maxPop, popularity[creators[i]]);
                                                                                    if (bestVideo.find(creators[i]) == bestVideo.end() || 
                                                                                                    views[i] > bestVideo[creators[i]].first ||
                                                                                                                    (views[i] == bestVideo[creators[i]].first && ids[i] < bestVideo[creators[i]].second)) {
                                                                                                                                    bestVideo[creators[i]] = {views[i], ids[i]};
                                                                                                                                                }
                                                                                                                                                        }
                                                                                                                                                                vector<vector<string>> result;
                                                                                                                                                                        for (auto& p : popularity) {
                                                                                                                                                                                    if (p.second == maxPop) {
                                                                                                                                                                                                    result.push_back({p.first, bestVideo[p.first].second});
                                                                                                                                                                                                                }
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                return result;
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                    };