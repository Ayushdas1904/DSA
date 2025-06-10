/**********NO. OF PRIME NUMBER WITHOUR EXCEDDING TIME LIMIT*********/
/*************SEIVES OF ERATOSTHENES************/

#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n){
    int cnt = 0;
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2*i; j < n; j+=i)
            {
                prime[j] = 0;
            }
            
        }
        
    }
    return cnt;
    
}

int main(){
    
    return 0;
}