#include <bits/stdc++.h>
using namespace std;

int buscarpos(int p, int posiciones[]){
  for (int i = 0; i < 8; i++) {
    if(posiciones[i] == p)
      return i;
  }
  return -1;
}

int main() {
  int n, m, a[20], b[20], c[20];
  while(cin >> n >> m && (n || m)) {
    for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }
    int posiciones[8] = {0,1,2,3,4,5,6,7};
    int total=0;
    do{
      bool pos_ok = true;
      for (int i = 0; i < m; i++) {
	int posa = buscarpos(a[i], posiciones);
	int posb = buscarpos(b[i], posiciones);
	if(c[i]>0){
	  if(abs(posa-posb) > c[i]){
	    pos_ok = false;
	    break;
	  }
	}else if(c[i]<0){
	  if(abs(posa-posb) < -c[i]){
	    pos_ok = false;
	    break;
	  }
	}
      }
      if(pos_ok)
	total++;
    }while(next_permutation(posiciones,posiciones+n));
    cout << total << endl;    
  }

  
  return 0;
}
