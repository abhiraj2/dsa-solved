#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
typedef vector<lol> vl;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	while(t--){
	    lol n , m;
	    cin >> n >> m;
	    if((min(n,m) ==1 && max(n,m)==2) || (min(n,m)>=2 && (n%2 ==0 ||m%2 ==0))) cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
}