class Spreadsheet {
public:
    unordered_map<string, int> sheet;   // cell -> val

    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        for(int i=0; i<formula.size(); i++){
            if(formula[i]=='+'){
                string s1 = formula.substr(0, i), s2 = formula.substr(i+1);
                int left = 0, right = 0;
                if(s1[0]>='A' and s1[0]<='Z') left = sheet[s1];  // if the input is given by X+Y (cell)
                else left = stoi(s1);  // if the input is given by any int value as string
                if(s2[0]>='A' and s2[0]<='Z') right = sheet[s2];
                else right = stoi(s2);
                return left+right;
            }
        }
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */