#include<iostream>

unsigned long long sumsquared(int);

int main(){
    std::cout<<sumsquared(19);
    return 0;
}

unsigned long long sumsquared(int n){
    return n == 1 ? 1 : (n*n) + sumsquared(n-1);
}