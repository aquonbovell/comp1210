#include<iostream>

unsigned long long int sum(int n);

int main (){
    std::cout<<sum(10065);
    return 0;
}

unsigned long long int sum(int n){
    return n==1 ? n : (n + sum(n-1));
}