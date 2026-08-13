// You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

// The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

// Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.

class Solution {
public:
    struct node{
        int len;
        int maxlen;
        int prefcnt, sufcnt;
        char pref, suf;
    };

    void create(vector<node> &seg, string &s, int i, int j, int idx = 0){
        if (i == j){
            seg[idx].len = 1;
            seg[idx].maxlen = 1;
            seg[idx].prefcnt = seg[idx].sufcnt = 1;
            seg[idx].pref = seg[idx].suf = s[i];
            return;
        }
        int mid = i + (j-i)/2;

        create(seg, s, i, mid, 2*idx + 1);
        create(seg, s, mid+1, j, 2*idx + 2);

        int l = 2*idx + 1, r = 2*idx + 2;

        seg[idx].len = seg[l].len + seg[r].len;
        seg[idx].maxlen = max(seg[l].maxlen, seg[r].maxlen);

        if (seg[l].suf == seg[r].pref)
            seg[idx].maxlen = max(seg[idx].maxlen, seg[l].sufcnt + seg[r].prefcnt);

        seg[idx].pref = seg[l].pref;
        seg[idx].suf = seg[r].suf;

        seg[idx].prefcnt = seg[l].prefcnt;
        
        if (seg[l].prefcnt == seg[l].len && seg[r].pref == seg[l].pref)
            seg[idx].prefcnt += seg[r].prefcnt;

        seg[idx].sufcnt = seg[r].sufcnt;
        
        if (seg[r].sufcnt == seg[r].len && seg[r].suf == seg[l].suf)
            seg[idx].sufcnt += seg[l].sufcnt;
    }
    
    void update(vector<node> &seg, int i, int j, int target, char c, int idx = 0){

        if (i == j && i == target){
            seg[idx].pref = seg[idx].suf = c;
            return;
        }

        int mid = i + (j-i)/2;

        if (target <= mid) update(seg, i, mid, target, c, 2*idx + 1);

        else update(seg, mid+1, j, target, c,  2*idx + 2);

        int l = 2*idx + 1, r = 2*idx + 2;

        seg[idx].len = seg[l].len + seg[r].len;
        seg[idx].maxlen = max(seg[l].maxlen, seg[r].maxlen);

        if (seg[l].suf == seg[r].pref)
            seg[idx].maxlen = max(seg[idx].maxlen, seg[l].sufcnt + seg[r].prefcnt);

        seg[idx].pref = seg[l].pref;
        seg[idx].suf = seg[r].suf;

        seg[idx].prefcnt = seg[l].prefcnt;
        
        if (seg[l].prefcnt == seg[l].len && seg[r].pref == seg[l].pref)
            seg[idx].prefcnt += seg[r].prefcnt;

        seg[idx].sufcnt = seg[r].sufcnt;
        
        if (seg[r].sufcnt == seg[r].len && seg[r].suf == seg[l].suf)
            seg[idx].sufcnt += seg[l].sufcnt;
        
        return;
    }
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        
        int n = s.size();

        int k = qc.size();

        vector<int> ans(k);

        vector<node> seg(4*n);
        
        create(seg, s, 0, n-1);


        for (int i = 0; i < k; i++){
            update(seg, 0, n-1, qi[i], qc[i]);
            ans[i] = seg[0].maxlen; 
        }
        return ans;
    }
};
