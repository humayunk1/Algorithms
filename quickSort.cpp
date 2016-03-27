/* This file contains a quickSort function and a selection function quickSelect
 * Code by: Humayun Kabir, humayun.k1@gmail.com */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//This exchanges the values at i and j-th position
void exchange(int* & inArr, int i, int j) {
	int temp = inArr[i];
	inArr[i] = inArr[j];
	inArr[j] = temp;
}


//This partitions the array inArr around the element inArr[hi]
//puts inArr[hi] in its proper place in sorted array inArr and returns 
//it's index in the sorted array
int partition(int* & inArr, int lo, int hi)
{
	int x = inArr[hi];
	int i = lo -1;

	for(int j = lo; j < hi; j++) {
		if( inArr[j] <= x ) {
			i++;
			exchange(inArr, i, j);
		} 
	}
	exchange(inArr, i+1, hi);

	return i +1;
}


//sort the array between indices lo and hi
void quickSort(int * & inArr, int lo, int hi) {
	if( hi <= lo ) 
		return;

	int j = partition(inArr, lo, hi);
	quickSort(inArr, lo, j-1);
	quickSort(inArr, j+1, hi);
}


//Sort an input array
void sort(int* & inArr, int length) {
	quickSort(inArr, 0, length -1);
}

//Selects the k-th smallest element from inArr
int quickSelect(int* &inArr, int length, int k) {
	int lo = 0, hi = length - 1;

	while(hi > lo) {
		int j = partition(inArr, lo, hi);

		if( j < k ) lo = j + 1;
		else if( j > k ) hi = j - 1;
		else return inArr[k];
	}
	return inArr[k];
}

//Test the quickSort function
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

        cout<<"3rd element is: \n";
        cout<< quickSelect(arr, length, 3) << endl;                

	sort(arr, length);

	cout<<"Sorted array: \n";
	for(int i = 0; i < length; i++)
		cout<<arr[i]<<" ";
	cout<<"\n"; 

	return 0;
}


