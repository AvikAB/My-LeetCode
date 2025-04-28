class Solution {
public:
    int perform(int x, int y, char op){
        if(op=='+') return x+y;
        if(op=='-') return x-y;
        if(op=='*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int>res;
        bool isNum = true;
        for(int i=0; i<expression.size(); i++){
            if(!isdigit(expression[i])){
                isNum = false;
                vector<int>left = diffWaysToCompute(expression.substr(0, i));
                vector<int>right = diffWaysToCompute(expression.substr(i+1));

                for(int x:left){
                    for(int y:right){
                        int val = perform(x, y, expression[i]);
                        res.push_back(val);
                    }
                }
            }
        }
        if(isNum == true) res.push_back(stoi(expression));
        return res;
    }
};