// HELP RAHUL TO SEARCH
// Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

// Input Format:
// The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

// Constraints:
// Output Format
// Output the index of number in the array to be searched. Output -1 if the number is not found.

// Sample Input
// 5
// 4
// 5
// 1
// 2
// 3
// 2
// Sample Output
// 3
#include<iostream>
using namespace std;

int searchrotatedarray(int *a,int sp,int ep,int key){
    if(sp>ep){
        return -1;
    }
    int mid = (sp+ep)/2;

    if(a[mid]==key){
        return mid;
    }
    if(a[mid]>=a[sp]){
        if(a[mid]>=key && key>=a[sp]){
            return searchrotatedarray(a,sp,mid-1,key);
        }
        else{
            return searchrotatedarray(a,mid+1,ep,key);
        }
    }
    else{
        if(a[mid]<=key && key<=a[ep]){
            return searchrotatedarray(a,mid+1,ep,key);
        }
        else{
            return searchrotatedarray(a,sp,mid-1,key);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int a[1000000005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout << searchrotatedarray(a,0,n-1,key) << endl;
	return 0;
}