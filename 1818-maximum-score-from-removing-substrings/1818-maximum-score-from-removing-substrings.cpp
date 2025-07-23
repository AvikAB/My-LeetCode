class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a = 0, b = 0, l = min(x,y), res = 0;
        for(char c:s){
            if(c>'b'){     // if the char is not 'a' or 'b'
                res += min(a,b)*l;
                a = 0;
                b = 0;
            } else if(c=='a'){
                if(x<y and b>0){  // y is greater and b is available then its 'ba'
                    b--;
                    res += y;
                } else a++;
            } else {
                if(x>y and a>0){   // x is greater and a is available then its 'ab'
                    a--;
                    res += x;
                } else b++;
            }
        }
        res += min(a,b) * l;
        return res;
    }
};