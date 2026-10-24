class Solution {
public:
    int toDays(string date){
        int month = stoi(date.substr(0,2));  //MM:DD
        int day = stoi(date.substr(3, 2));
        int tot = day;
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=0; i<month-1; i++){
            tot += days[i];
        }
        return tot;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);
        if(start>end) return 0;
        
        return toDays(end) - toDays(start)+1;
    }
};