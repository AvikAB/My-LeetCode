class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i=0, j=0;
        while(i<n or j<m){
            string s1,s2;

            // revision from version1
            while(i<n and version1[i]!='.'){
                s1 += version1[i];
                i++;
            }

            // revision from version2
            while(j<m and version2[j]!='.'){
                s2 += version2[j];
                j++;
            }
            
            int v1 = s1.empty() ? 0 : stoi(s1);
            int v2 = s2.empty() ? 0 : stoi(s2);
            
            if(v1 < v2) return -1;
            else if(v1 > v2) return 1;
            i++, j++;   // skip '.' and check after '.' & again go to the main while loop
        }
        return 0;
    }
};