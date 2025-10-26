class Bank {
public:
    vector<long long> bankBalance;
    Bank(vector<long long>& balance) {
        bankBalance=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if((account1-1>=0 && account1-1<bankBalance.size()) && (account2-1>=0 && account2-1<bankBalance.size())){
            if(bankBalance[account1-1]>=money){
                bankBalance[account1-1]-=money;
                bankBalance[account2-1]+=money;
                return true;
            }
            else{
                return false;   
            }
        }
        
        else{
            return false;   
        }
    }
    
    bool deposit(int account, long long money) {
        if(account-1>=0 && account-1<bankBalance.size()){
           
                
                bankBalance[account-1]+=money;
            
            return true;
        }
        
        else{
            return false;   
        }
    }
    
    bool withdraw(int account, long long money) {
        if(account-1>=0 && account-1<bankBalance.size()){
            if(bankBalance[account-1]>=money){
                
                bankBalance[account-1]-=money;
                return true;
            }
            else{
                return false;   
            }
        }
        
        else{
            return false;   
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */