#include<bits/stdc++.h>
using namespace std;

// works on unimodal function ie with only one peak or low
// paraboidal fucntions 

double f(double x){
    return (x*x + 4*x + 15);
}

// used to find min and max
double TernarySearch(double l,double r,double epsln = 1e-7){
    while(r - l > epsln){
        double x1 = l + (r - l)/3.0;
        double x2 = r - (r - l)/3.0;

        if(f(x1) < f(x2)){
            l = x1;
        }else{
            r = x2;
        }
    }
    return (l + r)/2.0;
}

int main(){
    double l = 0.0, r = 4.0;
    double Mx_x = TernarySearch(l,r);
    cout<<"Max Value is at x = "<<Mx_x<<endl;
    cout<<"Max Value is = "<<f(Mx_x)<<endl;  
}

// Sampel Problem : https://codeforces.com/contest/1999/problem/G2