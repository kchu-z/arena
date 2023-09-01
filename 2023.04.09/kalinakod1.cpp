#include<bits/stdc++.h>
using namespace std;
int prio(char c){
    if(c=='*' || c=='/')return 2;
    return 1;
}
int calc(int a,int b,char c){
    if(c=='*')return a*b;
    if(c=='/')return a/b;
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    exit(1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    stack<int> numSt;
    stack<char> opSt;
    s.push_back('+');
    for(char c:s){
        if(isdigit(c)){
            numSt.push(c-'0');
        }else{
            while(opSt.size() && prio(opSt.top())>=prio(c)){
                int second=numSt.top();
                numSt.pop();
                int first=numSt.top();
                numSt.pop();
                int ans=calc(first,second,opSt.top());
                numSt.push(ans);
            }
            opSt.push(c);
        }
    }
    cout<<numSt.top();
    return 0;
}
