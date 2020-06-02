
// Time Complexcity : O(n)

// Algorithm:
//1. Chech if difference between target and element in array can be found:
    //1.1 if not insert the element in map for further check
    //1.2 if yes then pair found pass the index of difference and index of current element


#include<bits/stdc++.h>
using namespace std;

vector<int> twosumindex(int a[ ], int n ,int target)
{

    map<int, int> st; // ordered map
    int i;
    vector<int> found; // result vector which will be returned
    for (i = 0; i < n; i++)
    {
        
        map<int, int>::iterator it;
        it = st.find(target - a[i]); // finding if difference between the target value and current element in array is available 
        if (it != st.end()) // If value found then the pair in found 
        {
    
            found.push_back(it->second); // pushing the index where difference is found
    
            found.push_back(i); // pusing the index of current element of array
            break;
        }
        else // If no value found 
        {
    
            st.insert({a[i], i}); // insert current element of array in ordered map
           
        }
    }
    return found;
}

int main()
{
    int n,t;
    cin>>n; // Number of elements in array
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i]; // Input the value in array
    cin>>t; // Target value
    vector <int> r; // Creating result vector
    r = twosumindex(a,n,t); // passing array , number of elements and target value
    for(int i =0 ;i<2;i++)  // Only two numbers present 
    {
        if(i == 0)
            cout<<"[ "<<r[i]<<" , "; // Printing index of value which will form target value
        else 
            cout<<r[i]<<" ] ";
    }
    
    return 0;        
}
