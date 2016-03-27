/* This file contains a merge sort function 
 * Code by: Humayun Kabir, humayun.k1@gmail.com */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//merge function -- merges two sorted arrays
void merge(int* & inArr, int lo, int mid, int hi, int* tempArr) {

	int i = lo, j = mid + 1;

	for(int k = lo; k <= hi; k++) {

		if( i > mid ) {
			tempArr[k] = inArr[j];
			j++; 
		}
		else if( j > hi ) {
			tempArr[k] = inArr[i];
			i++; 
		}
		else if( inArr[i] <= inArr[j] ) {
			tempArr[k] = inArr[i];
			i++; 
		}
		else {
			tempArr[k] = inArr[j];
			j++; 
		}
	}	

	for(int k = lo; k <= hi; k++) { 
		inArr[k] = tempArr[k];
	}

}

//mergeSort function
void mergeSort(int* & inArray, int lo, int hi, int* tempArr) {

	if(hi == lo)
		return;

	int mid = (lo + hi)/2;
	mergeSort(inArray, lo, mid, tempArr);
	mergeSort(inArray, mid + 1, hi, tempArr);

	//Merge the sorted arrays
	merge(inArray, lo, mid, hi, tempArr);	
}

//This function sorts the input array inArr
void sort(int* & inArr, int length) {

	int *tempArr = new int[length]; 
	mergeSort(inArr, 0, length - 1, tempArr);

}


//Test the mergeSort function
int main() {

	int length = 10;
        int *arr = new int[length];

	srand( time(NULL) );

        cout<<"Input array: \n";
        for(int i = 0; i < length; i++) {
		//Generate a random number between 1 and 1000
                arr[i] = rand() % 1000 + 1;
                cout<<arr[i]<<" ";
	}
                
        cout<<"\n";

	sort(arr, length);

        cout<<"Sorted array: \n";
        for(int i = 0; i < length; i++)
                cout<<arr[i]<<" ";
        cout<<"\n";	

	return 0;
}
