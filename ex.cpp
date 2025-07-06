#include<bits/stdc++.h>
using namespace std;

int main(){
    float a=10.234567890;
    float *p = &a;
    float &b= a;
    bool yes= true;
    cout<<a<<endl<<p<<endl<<*p<<endl<<b<<endl;
    cout<<yes<<endl;
    cout<<std::fixed<<std::setprecision(5)<<a<<endl;
    return 0;
}