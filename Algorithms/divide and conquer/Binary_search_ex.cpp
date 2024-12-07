#include <iostream>
#include<vector>
using namespace std;
/*
Exercise 3
Given an array A of integers with A1 < A2 < A3 < . . . < AN, write an algorithm to
determine if there is in the array an integer i such that Ai = i. What is the
running time of your algorithm?
*/

bool binarysearch(vector<int> a){
    int low=0;
    int high = a.size()-1;
    while (low<=high)
    {
        /* code */
        int mid= (low+high)/2;
        if(a[mid]==mid)return true;
        else if (a[mid]<mid)low=mid+1;
        else high=mid-1;
        
    }
    return false;

}
int main(){
    vector<int> a ={0,2,3,4,5,6,7,8,8};
    cout << binarysearch(a);
}

//[0,1,3,7,75,54,54]