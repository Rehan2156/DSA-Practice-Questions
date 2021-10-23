#include<bits/stdc++.h>

using namespace std;
int main(){
    int a=79;
    int b=8372;
    int c=b;
    int count=0;
    int remainder=0, reverse=0;
    while(c!=0){
        c=c/10;
        count++;
    }
    c=pow(10,count);
    a=a*c+b;
    cout<<a<<endl;
    while(a!=0){
        remainder= a%10;
        reverse= reverse*10 +remainder;
        a/=10;
    }
    cout<<reverse;



}