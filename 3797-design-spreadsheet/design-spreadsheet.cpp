class Spreadsheet {
public:
    vector<vector<int>> spreadSheet;
    Spreadsheet(int rows) {
        vector<vector<int>> temp(rows+1,vector<int>(26,0));
        spreadSheet=temp;
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int len=cell.size();
        string rowS=cell.substr(1,len-1);
        int row=stoi(rowS);
        spreadSheet[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col=cell[0]-'A';
        int len=cell.size();
        string rowS=cell.substr(1,len-1);
        int row=stoi(rowS);
        spreadSheet[row][col]=0;
    }
    int giveValue(string cell){
        int col=cell[0]-'A';
        int len=cell.size();
        string rowS=cell.substr(1,len-1);
        int row=stoi(rowS);
        return spreadSheet[row][col];
    }
    int getValue(string temp) {
        int len=temp.size();
        string s=temp.substr(1,len-1);
        string first="";
        int i=0;
        int j=0;
        while(s[j]!='+'){
            first+=s[j];
            j++;
        }
        j++;
        int n=s.size();
        string second="";
        while(j<n){
            second+=s[j];
            j++;
        }
        bool isFirst=false;
        bool isSecond=false;
        for(auto& c:first){
            if(!((c-'0')>=0 && (c-'0')<=9)){
                isFirst=true;
            }
        }
        for(auto& c:second){
            if(!((c-'0')>=0 && (c-'0')<=9)){
                isSecond=true;
            }
        }
        int val1;
        int val2;
        if(!isFirst){
            val1=stoi(first);
        }
        else{
            val1=giveValue(first);
        }
        if(!isSecond){
            val2=stoi(second);
        }
        else{
            val2=giveValue(second);
        }
        return val1+val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */