class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string smallest = s;
        unordered_set<string>vis;
        queue<string>q;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            if(curr < smallest) smallest = curr;

            // Add Operation:
            string temp = curr;
            for(int i=1; i<temp.size(); i+=2){
                temp[i] = ((temp[i]-'0'+a)%10)+'0';  // char to int then again char
            }
            if(!vis.count(temp)){  // if current not present in vis then it will add to vis & queue
                vis.insert(temp);
                q.push(temp);
            }

            // Rotate Operation:
            reverse(curr.begin(), curr.end());
            reverse(curr.begin(), curr.begin()+b);
            reverse(curr.begin()+b, curr.end());

            if(!vis.count(curr)){  // if current not present in vis then it will add to vis & queue
                vis.insert(curr);
                q.push(curr);
            }
        }
        return smallest;
    }
};


/* Three times of those following reverse gives rotate the string 's' to the right by any int 'b' position:
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+b);
    reverse(s.begin()+b, s.end());
*/