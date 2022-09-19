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
	    lol n, k;
	    cin >> n >> k;
	    if(k==1) n%2?cout << "ODD\n":cout<<"EVEN\n";
	    else if(k==2) cout << "ODD\n";
	    else cout << "EVEN\n";
	}
}