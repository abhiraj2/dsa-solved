#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef __int128_t lollol;
typedef vector<int> vi;
#define itr(i,a,b) for (int i=a; i<=b; i++)


int main(){
	int t; cin >>t;
	while(t--){
	    lol N; cin >> N;
	    vector<lol> arr(N);
	    for(int i=0; i < N; i++) cin >> arr[i];
	    sort(arr.begin(), arr.end());
	    float m1 = (float)accumulate(arr.begin(), arr.end()-1, 0)/ (float)(N-1);
	    float m2 = (float)accumulate(arr.end()-1, arr.end(), 0);
	    cout << fixed << setprecision(6) << m1+m2 << endl;
	    
	}
}