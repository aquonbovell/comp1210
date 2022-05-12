#include <iostream>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main() {
	int x, y;
	cout << "Enter a value of x such that it is greater than y: ";
	cin >> x;
	cout << "Enter a value of y such that it is less than that x: ";
	cin >> y;
	//cout << "The greatest commom divisor of "<< x << " and "<< y <<" is: "<<gcd(x, y)<<'\n';
	cout<<"The least common multiple is :" << x << " and "<< y << abs(x*y)/gcd(x,y);
	return 0;
}

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

// greatest common multiple using iteration
// int gcd(int x, int y)
// {
// 	int remainder=0;
    
//     while (y != 0) {
//         remainder = x%y;
// 		x=y;
// 		y=remainder;
//     }
//     return x;
// }

int lcm (int x, int y){
	return abs(x*y)/gcd(x,y);
}