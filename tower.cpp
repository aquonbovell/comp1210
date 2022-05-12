#include<iostream>

void tower(int,int,int,int);

int main(){
    tower(3,1,2,3);
    return 0;
}
void tower(int n,int ipeg,int tpeg,int fpeg) {
    if(n==1){
        std::cout<<"\t\tMove disc 1 from "<<ipeg<<" to "<<fpeg<<"\n";
        return;
        }
        else{
        tower(n-1,ipeg,fpeg,tpeg);
        std::cout<<"\t\tMove disc "<<n<<" from "<<ipeg<<" to "<<fpeg<<"\n";
        tower(n-1,tpeg,ipeg,fpeg);
        }
}

