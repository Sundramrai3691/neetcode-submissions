class Solution {
public:
    void patterns(int idx,set<vector<string>> &curr, vector<string> pat,vector<string> &history){
        int sz = history.size();

        if(pat.size() == 3){
            curr.insert(pat);
            return;
        }

        if(idx == sz){
            return;
        }
        
        pat.push_back(history[idx]);
        patterns(idx + 1,curr,pat,history);
        pat.pop_back();

        patterns(idx+1,curr,pat,history);
    }

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();

        map<int,vector<int>> tmap;

        for(int i = 0;i<n;i++){
            tmap[timestamp[i]].push_back(i);
        }

        unordered_map<string,vector<string>> webs;

        int m = tmap.size();

        for(auto m : tmap){
            int t = m.first;
            auto v = m.second;
            
            for(auto j : v)
            webs[username[j]].push_back(website[j]);
        }

        map<vector<string>,int> freq;

        for(auto m : webs){
            auto vec = m.second;

            set<vector<string>> curr;
            vector<string> pat;

            patterns(0,curr,pat,vec);

            for(auto v : curr)
            freq[v]++;
        }

        int maxi = 0;

        vector<string> res;

        for(auto f : freq){
            int fq = f.second;
            auto vec = f.first;

            if(fq > maxi){
                maxi = fq;
                res = vec;
            }
        }
        return res;
    }
};