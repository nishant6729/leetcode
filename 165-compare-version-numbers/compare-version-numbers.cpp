class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=1;
        vector<int> v1;
        vector<int> v2;
        while(i<version1.size()){
            while(j<version1.size() && version1[j]!='.'){
                j++;
            }
            string temp=version1.substr(i,j-i);
            int number=stoi(temp);
            v1.push_back(number);
            i=j+1;
            j=i+1;
        }
        i=0;
        j=1;
        
        while(i<version2.size()){
            while(j<version2.size() && version2[j]!='.'){
                j++;
            }
            string temp=version2.substr(i,j-i);
            v2.push_back(stoi(temp));
            i=j+1;
            j=i+1;
        }
        cout<<v1.size()<<" ";
        cout<<v2.size()<<" ";
        if(v1.size()!=v2.size()){
            if(v1.size()>v2.size()){
                int extra=v1.size()-v2.size();
                for(int i=0;i<extra;i++){
                    v2.push_back(0);
                }
            }
            else{
                int extra=v2.size()-v1.size();
                for(int i=0;i<extra;i++){
                    v1.push_back(0);
                }
            }
        }
        int ans=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                ans=1;
                break;
            }
            else if(v1[i]<v2[i]){
                ans=-1;
                break;
            }
        }
        return ans;

    }
};