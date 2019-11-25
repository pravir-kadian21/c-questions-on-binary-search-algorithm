// FIND UPPER AND LOWER BOUND
// Find position of the last and first occurrence of a given number in a sorted array. If number not exist then print lower and upper bound as -1.

// Input Format:
// An integer n denoting the size of the array followed by n integers denoting array elements Followed by T testcases Each testcase contains integer x (whose positions are to be found)

// Constraints:
// Output Format
// Lower bound position followed by upper bound position separates by space in each line

// Sample Input
// 5
// 1 2 3 3 4
// 3
// 2
// 3
// 10
// Sample Output
// 1 1
// 2 3
// -1 -1
#include<iostream>
using namespace std;

int lowerbound(int *a,int n,int key){
	int sp=0;
	int ep=n-1;
	int ans=-1;
	while(sp<=ep){
		int mid=(sp+ep)/2;
		if(a[mid]==key){
			ans = mid;
			ep=mid-1;
		}
		if(a[mid]>key){
			ep=mid-1;
		}
		if(a[mid]<key){
			sp=mid+1;
		}
	}
	return ans;
}

int upperbound(int *a,int n,int key){
	int sp=0;
	int ep=n-1;
	int ans=-1;
	while(sp<=ep){
		int mid=(sp+ep)/2;
		if(a[mid]==key){
			ans = mid;
			sp=mid+1;
		}
		if(a[mid]>key){
			ep=mid-1;
		}
		if(a[mid]<key){
			sp=mid+1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	int a[100000005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
		int key;
		cin>>key;
		cout << lowerbound(a,n,key) << " ";
		cout << upperbound(a,n,key) << endl;
	}
	return 0;
}