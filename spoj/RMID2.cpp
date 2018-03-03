#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0), ios_base::sync_with_stdio(0); // Para quem usar CIN e COUT, em questoes com tempo
                                            //apertado, precisa escrever esses dois comando no
                                            //inicio e usar '\n' em vez de endl ou usa scanf
                                            //e printf
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int x;
    priority_queue<int> left, right; // ambas tem o maior elemento inserido no top(), mas como
                                     // nós precisamos do menor na direita, basta fazer x = -x
                                     // quando for inserir e remover
    while(cin >> x, x){ // 'igual' a while(n), a ultima condicao separada por vigulas é a verificada
      if(x == -1){ // mostra o maior elemento da esquerda e deleta
        cout << left.top() << '\n';
        left.pop();
      } else {  // Ve se o elemento deve ir para a direita ou para a esquerda
        if(right.size() and x >= -right.top()) right.push(-x);
        else left.push(x);
      }

      if(left.size() < right.size())
        left.push(-right.top()), right.pop();

      else if(left.size() > right.size() + 1)
        right.push(-left.top()), left.pop();
    }
    cout << '\n';
  }
  return 0;
}
