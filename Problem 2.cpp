// Time Complexcity : O(length of number)
// Algorithm: Using recursion so a stack will be formed:
//1. Check number if negative convert to positive
//2. Create a pointer to point to copy of the number
//3. Compare the first and last element:
    //3.1 If same then pallindrome
    //3.2 else not a pallindrome

#include<bits/stdc++.h>
using namespace std;

int comp(int num) 
{
	return (num >= 0 && num < 10); 
} 
bool ispalcheck(int num, int* dupNum) 
{  
	if (comp(num)) 
		return (num == (*dupNum) % 10); // num in moving from left to right dupNum right to left till same return true

	if (!ispalcheck(num/10, dupNum)) // if false some value didn't match
		return false; 
		
	*dupNum /= 10; // removing the rightmost int 
	
	return (num % 10 == (*dupNum) % 10); // first and last element in int here
} 
int ispal(int num) 
{ 

	if (num < 0)  // if input is - make it + 
	    num = -num; 
	int *dupNum = new int(num); // *dupNum = num 

	return ispalcheck(num, dupNum); 
}
int main() 
{ 
	int n;
	cin>>n; // input 
	ispal(n)? cout<<"true":cout<<"false"; 
	return 0; 
} 
