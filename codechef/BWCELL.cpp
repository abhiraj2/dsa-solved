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
	t++;
	while(t--){
	    string s;
	    lol k = 0;
	    getline(cin, s);
	    if(s=="") continue;
	    for(auto x:s){
	        k++;
	        if(x=='W') break;
	        
	    }
	    if((s.size()%2 && k == (s.size()+1)/2)){
	        cout << "Chef" << endl;
	    }
	    else cout << "Aleksa" << endl;
	}
}