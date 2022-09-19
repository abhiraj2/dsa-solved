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
	    lol p1,p2, q1,q2;
	    cin >> p1 >> p2 >> q1 >> q2;
	    lol t1 = max(p1,p2);
	    lol t2 = max(q1, q2);
	    if(t1>t2) cout << "Q\n";
	    else if(t1<t2) cout << "P\n";
	    else cout << "TIE\n";
	}
}