#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
typedef map<lol, lol> ml;
typedef unordered_map<lol, lol> uml;
#define MOD 1000000007
#define itr(i,a,b) for (int i=a; i<=b; i++)

int main(){
    int change = 0;
    char output[MOD];
    char c;
    int i=0;
    while((c=getchar()) != EOF){
        //cout << (int)c<< endl; 
        if(c == 34){
            if(change){
                output[i++] = '\'';
                output[i++] = '\''; 
                change = 0;
            }
            else{
                output[i++] = '`';
                output[i++] = '`'; 
                change =1;
            }
        }
        else output[i++] = c;
    }
    output[i] = '\0';
    cout << output;
}