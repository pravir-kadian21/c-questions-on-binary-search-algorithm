// PIVOT OF SORTED AND ROTATED ARRAY
// You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element in the array which is greater than its next element and divides the array into two monotonically increasing halves.

// Input Format:
// The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

// Constraints:
// Output Format
// Output the index of the pivot of the array.

// Sample Input
// 5
// 4
// 5
// 1
// 2
// 3
// Sample Output
// 1
#include<iostream>
using namespace std;

int printpivot(int *a,int n){
	int sp=0;
	int ep=n-1;
	while(sp<=ep){
		int mid = (sp+ep)/2;
		if(a[mid]<a[mid-1] && mid>0){
			return mid-1;
		}
		if(a[mid]>a[mid+1] && mid<n-1){
			return mid;
		}
		if(a[sp]>a[mid]){
			ep=mid-1;
		}
		else{
			sp=mid+1;
		}
	}
}
int main() {
	int n;
	cin>>n;
	int a[10000005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout << printpivot(a,n) << endl;
	return 0;
}