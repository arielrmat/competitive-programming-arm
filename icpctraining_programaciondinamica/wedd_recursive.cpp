#include <bits/stdc++.h>
using namespace std;

int m, c, precio[21][21];

int solve(int item, int dinero){
	//ya no hay dinero
	if(dinero < 0)
		return INT_MIN; //algo al comparar garantice que este item no se compre
	//solo hay un item
	if(item == c)
		return m - dinero;
	//de todos los items, escoger aquel item optimo
	int item_optimo = INT_MIN;
	for (int i = 1; i <= precio[item][0]; i++){
		item_optimo = max(item_optimo, solve(item+1, dinero-precio[item][i]));
	}
	return item_optimo;
}

int main(){
	int casos, sol;
	cin >> casos;
	while(casos--){
		cin >> m >> c;
		for (int i = 0; i < c; i++){
			cin >> precio[i][0]; //cantidad de modelos
			for (int j = 1; j <= precio[i][0]; j++){
				cin >> precio[i][j];
			}
		}
		//resolver
		sol = solve(0,m);
		if(sol < 0)
			cout << "no solution\n";
		else
			cout << sol << '\n';
	}
	return 0;
}
