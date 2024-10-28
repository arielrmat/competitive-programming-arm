#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	int f1 = 1;
	int f2 = 1;
	int f = 0;
	if (n == 1)
		return f1;
	if (n == 2)
		return f2;
	for (int i = 3; i <= n; i++){
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	return f;
}

int main(){
	cout << fib(6);

	return 0;
}
