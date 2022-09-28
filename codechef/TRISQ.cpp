#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	lol t;
	cin >> t;
	while(t--){
	    lol b;
		cin >> b;
		lol n = (lol)(b/2);
		cout << n*(n-1)/2 << endl;
	}
}