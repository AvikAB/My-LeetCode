class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        for(int i=0; i<caption.size(); i++){
            if(caption[i]==' ') continue;
            if(i>0 and caption[i-1]==' '){
                if(islower(caption[i])) caption[i] = toupper(caption[i]);
            } else {
                if(isupper(caption[i])) caption[i] = tolower(caption[i]); 
            }
            ans += caption[i];
        }
        if(ans.size()>=1) ans[1] = tolower(ans[1]);  // first char always in lowercase
        return ans.substr(0,100);
    }
};