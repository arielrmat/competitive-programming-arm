#include <bits/stdc++.h>
using namespace std;

const int IMIN = INT_MIN;
int fila, columna;
int arr[11][11];

int solve(int fi, int co){
	if(fi == fila-1 && co == columna-1)
		return arr[fi][co];
	else if(fi == fila+1 || co == columna+1)
		return IMIN;
	int der = solve(fi, co + 1);
	int abajo = solve(fi+1, co);
	return arr[fi][co] + max(der, abajo);	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> fila >> columna;
	for (int i = 0; i < fila; i++){
		for (int j = 0; j < columna; j++){
			cin >> arr[i][j];
		}
	}	
	cout << solve(0, 0);
	return 0;
}
