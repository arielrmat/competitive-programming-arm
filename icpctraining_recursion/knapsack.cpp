#include <bits/stdc++.h>
using namespace std;

int peso[21];
int valor[21];
int n, capac;

int solve(int items, int capDisp){
	if(capDisp == 0 || items == 0)
		return 0;
	if(peso[items] > capDisp)
		return solve(items-1, capDisp);
	else{
		int opcion1 = solve(items-1,capDisp);
		int opcion2 = valor[items] + solve(items-1,capDisp-peso[items]);
		return max(opcion1, opcion2);
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	 cin >> n >> capac;
	 for (int i = 1; i <= n; i++){
		 cin >> peso[i] >> valor[i];
	 }
	cout << solve(n, capac); 
	

	return 0;
}
