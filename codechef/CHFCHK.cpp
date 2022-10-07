#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	int t; cin >>t;
	while(t--){
	    int n; cin >> n;
	    vi arr(n);
	    itr(i,0,n-1){ cin >> arr[i];}
	    cout << *min_element(arr.begin(), arr.end()) << endl;
	}
}