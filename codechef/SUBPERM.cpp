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
	    lol n, k;
	    cin >> n >> k;
	    //if(k==1 && n==1){cout << 1 << endl; continue;}
	    if(k>n || (k == 1 && n!=1)){cout << -1 << endl; continue;}
	    
	    for(int i=1; i<k; i++){
	        cout << i << " ";
	    }
	    
	    for(int i=n; i>=k; i--){
	        cout << i << " ";
	    }
	    
	    cout << endl;
	    
	}
}