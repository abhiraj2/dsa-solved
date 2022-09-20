#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
#define itr(i,a,b) for (int i=a; i<=b; i++)

#define BIGN 1000000007



lol count_o(lol n){
    lol c = 0;
    while(n>0){
        if(n%2) c++;
        n = n/2;
    }
    return c;
}

int main(){
    lol fib[1000001]; 
    fib[0] = 1; fib[1] = 1;
    for(int i=2; i<1000001; i++){
        fib[i] = (fib[i-1]%BIGN + fib[i-2]%BIGN)%BIGN;
    }
	lol t;
	cin >> t;
	while(t--){
	    lol n, g;
	    cin >> n >> g;
	    lol s = (fib[n])%BIGN;
	    lol cor = count_o(s);
	    //cout << fib[n] << endl;
	    cor==g?cout<<"CORRECT\n":cout<<"INCORRECT\n";
	    
	}
}