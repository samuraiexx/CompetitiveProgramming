#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* A, int B, int C) {
  ListNode *b = NULL, *c = A;
  ListNode *prev = NULL;
  for(int i = 1; A != NULL; i++){
    if(i == B - 1){
      b = A;
      c = A->next;
    } else if(i > B) {
      auto it = A->next;
      A->next = prev;
      prev = A;

      if(i == C){
        if(b != NULL) b->next = A;
        c->next = it;
        break;
      }

      A = it;
      continue;
    }
    prev = A;
    A = A->next;
  }
}

int main(){
}
