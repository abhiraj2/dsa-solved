#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
typedef pair<lol, lol> pl;
#define MOD 1000000007
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	while(t--){
	    lol x,y;
	    cin >> x >> y;
	    //cout << x << " " << y << endl;
	    //cout << (y%2^x%2)<< endl;
	    if(y==x) cout << 0 << endl;
	    else if(y>x) cout << y-x << endl;
	    else{
	        if((y%2)^(x%2)==0) cout << (x-y)/2 <<endl;
	        else cout << 1 + (x-y+1)/2 << endl;
	    }
	}
}