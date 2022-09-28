#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
#define itr(i,a,b) for (int i=a; i<=b; i++)

lol gcd(lol a, lol b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

lol lcm(lol a, lol b){
    return (a*b)/(gcd(a,b));
}

int main(){
	lol t; cin >> t;
	while(t--){
	    lol a, b;
	    cin >> a >> b;
	    cout << gcd(a,b) << " " << lcm(a,b) << endl; 
	}
}