#include <bits/stdc++.h>
using namespace std;

int valor_n = 6;
vector<int> f(valor_n+1, -1);

int fib(int n){	
	if(n == 1 || n == 2)
		return 1;
	return fib(n-1)+fib(n-2);
}

int main(){
	cout << fib(valor_n);
	return 0;
}
