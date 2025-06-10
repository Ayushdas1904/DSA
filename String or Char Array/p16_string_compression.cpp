/********printing a vector {'a','a','a','b','b','b','b','c'} as {'a','3','b','4','c'}*****************/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s2;
        int count = 1;

        for (int i = 0; i < chars.size(); ++i) {
            if (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                count++;
            } else {
                s2.push_back(chars[i]);
                if (count > 1) {
                    if (count <= 9) {
                        s2.push_back(char('0' + count)); // '0' is added to make the integer to char
                    } else {
                        string cnt = to_string(count); // COndition when 
                        for(int k=0; cnt[k]!='\0'; k++)
                        s2.push_back(cnt[k]);
                    }
                }
                count = 1;
            }
        }

        chars = s2;
        return chars.size();
        
    }
};