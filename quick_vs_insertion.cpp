/*
Dillon Stock stockdil@basset
2017-02-17
HW3_problem1.cpp

Your Comments
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using std::cout; using std::endl;

using namespace std;


////////////////////////////////////////////////////////////////////////////////////
// http://codereview.stackexchange.com/questions/77782/quick-sort-implementation 
void swap(int i,int j, int *a){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void quicksort(int *arr, int left, int right){
    int min = (left+right)/2;
    //cout<<"QS:"<<left<<","<<right<<"\n";

    int i = left;
    int j = right;
    int pivot = arr[min];

    while(left<j || i<right)
    {
        while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<=j){
            swap(i,j,arr);
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(arr, left, j);
            if(i<right)
                quicksort(arr,i,right);
            return;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////
// http://cforbeginners.com/insertionsort.html
void insertion_sort (int arr[], int length){
	 	int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
			  }
		}
}
///////////////////////////////////////////////////////////////////////////////////










int main() {
	
	double quick_start_time;
	double quick_total_time;
	
	double insertion_start_time;
	double insertion_total_time;
	
	
	int n;
	cout << "number of inputs? " << endl;
	cin >> n;
	//int n = 50;
	int arr[n];
	int arr2[n];
	
	
	// quicksort
    for(int i=0; i<10000; i++){
		
		
		// build two identical arrays from random number generator
		for(int index = 0; index < n; index++){
			int new_int = rand() % 10000;
			arr[index] = new_int;
			arr2[index] = new_int;
		}
		
		quick_start_time = std::clock();
		quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
		quick_total_time += (std::clock() - quick_start_time) / CLOCKS_PER_SEC;
		
		insertion_start_time = std::clock();
		insertion_sort(arr2, n);
		insertion_total_time += (std::clock() - insertion_start_time) / CLOCKS_PER_SEC;
	}
	
	
	
    std::cout << "QuickSort Time = " << quick_total_time << " seconds." << std::endl;
    cout << endl;

    std::cout << "Insertion Sort Time = " << insertion_total_time << " seconds." << std::endl;
    cout << endl;
    
    
    return 0;
}





/*

int main(){
	//int input_sizes[12] = {5,10,15,20,30,40,50,100,500,1000, 5000, 10000};
	
	vector<int> insert_arr;
	vector<int> 
	
	for(int i=0; i<12; i++){
		
		for(int j=0; j<
		
	}
}
*/

























