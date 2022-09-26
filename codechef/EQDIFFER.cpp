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
	    lol n;
	    cin >> n;
	    //cout << n << " ";
	    vl a(n);
	    for(int i=0; i<n;i++) cin >>a[i];
	    //set<lol> s(a.begin(), a.end());
	    lol max = 0;
	    if(n<=2){
	        cout << 0 << endl;
	        continue;
	    }
	    sort(a.begin(), a.end());
	    lol ma =0;
	    lol cn =1;
	    for(int i=1; i<n; i++){
	        if(a[i] == a[i-1]) cn ++;
	        else cn =1;
	        
	        if(cn > ma) ma = cn;
	    }
	    
	    cout << min(n - ma, n-2) << endl;
	}
}