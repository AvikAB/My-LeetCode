class Solution {
public:
    struct Node {
        char lc, rc;
        int llen, rlen, best, len;

        Node() {
            lc = rc = 0;
            llen = rlen = best = len = 0;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.lc = a.lc;
        res.rc = b.rc;

        res.llen = a.llen;
        res.rlen = b.rlen;

        res.best = max(a.best, b.best);

        // Merge the suffix of left with prefix of right
        if (a.rc == b.lc) {
            res.best = max(res.best, a.rlen + b.llen);

            // Entire left segment has same character
            if (a.llen == a.len)
                res.llen = a.len + b.llen;

            // Entire right segment has same character
            if (b.rlen == b.len)
                res.rlen = b.len + a.rlen;
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx].lc = seg[idx].rc = s[l];
            seg[idx].llen = seg[idx].rlen = seg[idx].best = 1;
            seg[idx].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx].lc = seg[idx].rc = c;
            seg[idx].llen = seg[idx].rlen = seg[idx].best = 1;
            return;
        }

        int mid = (l+r)/2;

        if (pos <= mid) update(2*idx, l, mid, pos, c);
        else update(2*idx+1, mid+1, r, pos, c);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        int k = queryCharacters.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};