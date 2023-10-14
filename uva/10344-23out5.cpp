#include <bits/stdc++.h>
using namespace std;
vector<int> tup(5,0);
bool encontrado;

bool buscar(int n, int res){
  if(n==5){
    if(res == 23) return true;
    else return false;
  }
  return buscar(n+1, res+tup[n]) || buscar(n+1, res-tup[n]) || buscar(n+1, res*tup[n]);  
}

int main() {
  while(cin>>tup[0]>>tup[1]>>tup[2]>>tup[3]>>tup[4]){
    if(!tup[0] && !tup[1] && !tup[2] && !tup[3] && !tup[4])
      break;
    sort(tup.begin(), tup.end());
    encontrado = false;
    do{
      if(buscar(1, tup[0])) {
	encontrado = true;
	cout << "Possible" << endl;
	break;
      }      
    }while(next_permutation(tup.begin(), tup.end()));
    if(!encontrado)
      cout << "Impossible" << endl;
  }
  
  return 0;
}
