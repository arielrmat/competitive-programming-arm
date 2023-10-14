#include <bits/stdc++.h>
using namespace std;

char digitos[10]={'0','1','2','3','4','5','6','7','8','9'};

bool verificar(int a, int b){
  char digitosusados[11];
  int total;
  sprintf(digitosusados,"%05d%05d",a,b);
  for (int i=0; i < 10; i++) {
    total = 0;
    for (int j = 0; j < 10; j++) {
      if(digitos[i] == digitosusados[j])
	total++;
    }
    if(total > 1)
      return false;
  }
  return true;
}


int main() {
  int n, nume, deno;
  bool primercaso = true, haysolucion;
  while(cin >> n && n){
    if(!primercaso)
      cout << endl;
    haysolucion = false;
    deno = 1234;
    for (deno = 1234; deno <= 98765; deno++) {
      nume = n*deno;
      if(nume > 98765) break;
      
      if(verificar(nume, deno)){
	haysolucion = true;
	cout << setfill('0') << setw(5) << nume;
	cout << " / ";
	cout << setfill('0') << setw(5) << deno;
	cout << " = " << n <<endl;	
      }
      
    }
    if(!haysolucion)
      cout << "There are no solutions for " << n <<"."<< endl;
      primercaso = false;
      
  }
  return 0;
}
