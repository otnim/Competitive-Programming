#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>


int main(){
    /// 34  4  3  30
      deque<int> dq;
      dq.push_front(4);
      dq.push_back(3);
      dq.push_back(30);
      dq.push_front(34);

      cout<<dq.front()<<'\n';
      cout<<dq.back()<<'\n';
      dq.pop_front();
      dq.pop_back();


      cout<<dq.front()<<'\n';
      cout<<dq.back()<<'\n';




}


