/*For a given N, find the number of ways to choose an integer x from the range [0,2N−1] such that x⊕(x+1)=(x+2)⊕(x+3), where ⊕
 *denotes the bitwise XOR operator.
 *Since the number of valid x can be large, output it modulo 109+7.
*/

/*SOLUTION*/
#include <iostream>

using namespace std;

#define m 1000000007;

int main() {
	// your code goes here
	int t, n;
	long long int res,base;
	cin>>t;
	for(int i=0;i<t;i++){
	    cin>>n;
	    n=n-1;
	    res=1;
	    base=2;
	    while(n>0){
	       if(n%2==1){
	            res=(res*base)%m;
	        }
	        n=n>>1;
	        base=(base*base)%m;
        }
	    cout<<res<<endl;
	}
	return 0;
}

//Refer__- https://www.geeksforgeeks.org/modulo-power-for-large-numbers-represented-as-strings/
//	https://en.wikipedia.org/wiki/Modular_exponentiation