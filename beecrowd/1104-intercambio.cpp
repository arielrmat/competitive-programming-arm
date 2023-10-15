#include <bits/stdc++.h>

using namespace std;

set<int> alicia;
set<int> betty;
set<int> intercambio;

int main() {
  int a, b, temp;
  while(cin>>a>>b && (a||b)){
    alicia.clear();
    betty.clear();
    intercambio.clear();
    for (int i = 0; i < a; i++) {
      cin >> temp;
      alicia.insert(temp);
    }
    for (int i = 0; i < b; i++) {
      cin >> temp;
      betty.insert(temp);
    }
    if(alicia.size() < betty.size()){
      //A-B: alicia-betty
      //                          A              -              B             =   intercambio
      set_difference(alicia.begin(), alicia.end(), betty.begin(), betty.end(), inserter(intercambio, intercambio.begin()));
    }else{
      //B-A: betty-alicia
      set_difference(betty.begin(), betty.end(), alicia.begin(), alicia.end(), inserter(intercambio, intercambio.begin()));
    }
    cout << intercambio.size() << endl;    
  }
  
  return 0;
}
