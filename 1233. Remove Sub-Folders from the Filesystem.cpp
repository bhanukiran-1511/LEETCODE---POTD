class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        if (folder.empty()) return ans;  // Handle empty input
        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            string prev = ans.back();
            prev += '/';
            // Only add if current folder is not a sub-folder of prev
            if (folder[i].find(prev) != 0) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
