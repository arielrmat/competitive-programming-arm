#include <bits/stdc++.h>
using namespace std;

int m, c, precio[21][21];
int mem[21][201];

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		cin >> m >> c;
		for (int i = 0; i < c; i++){
			cin >> precio[i][0]; //cantidad de modelos
			for (int j = 1; j <= precio[i][0]; j++){
				cin >> precio[i][j];
			}
		}
		//inicializar mem (-1 -> representa a un valor no calculado)
		memset(mem, -1, sizeof(mem));		
		//resolver, ahora partimos de lo mas basico (caso inicial)
		for (int i = 1; i <= precio[0][0]; i++){
			if(m-precio[0][i] >= 0)
				mem[0][m-precio[0][i]] = 1;
		}
		int dinero = 0;
		//recorrer cada item
		for (int i = 1; i < c; i++){
			//buscamos cuanto de dinero nos queda de la anterior 'compra'
			//busco los 1's marcados en la tabla mem
			for(dinero = 0; dinero < m; dinero++){
				//si esta marcado (si es igual a 1)
				if(mem[i-1][dinero]==1){
					for (int j = 1; j <= precio[i][0]; j++){
						if(dinero-precio[i][j] >= 0)
							mem[i][dinero-precio[i][j]] = 1;
					}
				}
			}
		}
		for(dinero = 0; dinero<=m; dinero++){
			if(mem[c-1][dinero]==1)
				break;
		}
		if(dinero == m+1)
			cout << "no solution\n";
		else
			cout << (m-dinero) << '\n';		
	}
	return 0;
}
