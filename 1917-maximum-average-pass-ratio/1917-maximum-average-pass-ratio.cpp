class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>>pq;    // max heap -> {maxDiff, idx}

        //At first, taking all classes currPR and newPR with updated 1 student
        for(int i=0; i<n; i++){
            double currPR = (double) classes[i][0] / classes[i][1];
            double newPR = (double) (classes[i][0]+1) / (classes[i][1]+1);
            double diff = newPR - currPR;
            pq.push({diff, i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();
            double diff = curr.first;
            int idx = curr.second;
            classes[idx][0]++;      // increment passing students in the class
            classes[idx][1]++;     //  increment total students in the class

            // after updated the pass and total students find their curr & new PR & idx remain same
            double currPR = (double) classes[idx][0] / classes[idx][1];
            double newPR = (double) (classes[idx][0]+1) / (classes[idx][1]+1);
            diff = newPR - currPR;
            pq.push({diff, idx});
        }

        double res = 0.0;
        for(int i=0; i<n; i++){
            res += (double) classes[i][0] / classes[i][1];
        }
        return res/n;
    }
};