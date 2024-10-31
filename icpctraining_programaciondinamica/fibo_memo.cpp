#include <bits/stdc++.h>
using namespace std;

int valor_n = 6;
vector<int> f(valor_n+1, -1);

int fib(int n){	
	if(f[n] == -1){		
		if(n == 1 || n == 2)
			f[n] = 1;
		else
			f[n] = fib(n-1)+fib(n-2);
	}
	return f[n];
}

int main(){
	cout << fib(valor_n);
	return 0;
}
