#include<iostream>
#include<vector>
#include<string>
using namespace std;
        

int main(){
        string s = "K1:L2";
        string cell1, cell2;
        vector<string> cells;
        
        int a = 0;
        while(true){
            if(s[a] ==':'){
                cell1 = s.substr(0, a);
                cell2 = s.substr(a+1);
                break;
            }
            a++;
        }
        cout << cell1 << endl;
        cout << cell2 << endl;

        for(char i = cell1[0]; i <= cell2[0]; i++){
            for(char j = cell1[1]; j <= cell2[1]; j++){
                cout << to_string(i) + to_string(j) << endl;
          
                cells.push_back(to_string(i + j));
            }
        }

        cout << 'A' + '1';
    
    return 0;
}