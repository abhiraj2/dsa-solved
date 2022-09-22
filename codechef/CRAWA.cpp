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
	    lol x,y;
	    cin >> x >> y;
	    if(x==0 && y==0) {cout << "YES" << endl; continue;}
	    if(x%2 && x > 0 && y>=-(x-1) && y <= x+1){
	        cout << "YES" << endl; continue;
	    }
	    if(x%2==0 && x < 0 && y>=x && y <= -x){
	        cout << "YES" << endl; continue;
	    }
	    if(y%2==0 && y > 0 && x>=-y && x < y){
	        cout << "YES" << endl; continue;
	    }
	    if(y%2==0 && y < 0 && x>=y && x <= -(y-1)){
	        cout << "YES" << endl; continue;
	    }
	    else cout << "NO" << endl;
	}
}