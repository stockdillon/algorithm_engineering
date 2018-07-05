/*
Dillon Stock stockdil@basset
2017-02-17
HW3_problem1.cpp

Your Comments


#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using std::cout; using std::endl;

using namespace std;


////////////////////////////////////////////////////////////////////////////////////
// http://codereview.stackexchange.com/questions/77782/quick-sort-implementation 
void print(int *a, int n)
{
    int i=0;
    while(i<n){
        cout<<a[i]<<",";
        i++;
    }
}

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
	
	double start_time;
	double total_time;
	
	int n = 8;
	
	
	// quicksort
    for(int i=0; i<10000; i++){
		//int arr[n] = {110, 5, 10,3 ,22, 100, 1, 23};
		
		
		
		for(int index = 0; index < n; index++){
			int new_int = rand() % 10000;
			arr[index] = new_int;
			arr2[index] = new_int;
		}
		
		
		
		
		start_time = std::clock();
		quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
		total_time += (std::clock() - start_time) / CLOCKS_PER_SEC;
	}
    std::cout << "QuickSort Time = " << total_time << " seconds." << std::endl;
    //print(arr, (sizeof(arr)/sizeof(arr[0])));
    cout << endl;
    
    
    
    // insertion sort
    
    
    for(int i=0; i<10000; i++){
    int arr2[n] = {110, 5, 10,3 ,22, 100, 1, 23};
		start_time = std::clock();
		insertion_sort(arr2, 8);
		total_time += (std::clock() - start_time) / CLOCKS_PER_SEC;
	}
    std::cout << "Insertion Sort Time = " << total_time << " seconds." << std::endl;
    //print(arr2, (sizeof(arr)/sizeof(arr[0])));
    cout << endl;
    
    
    return 0;
}







int main(){
	//int input_sizes[12] = {5,10,15,20,30,40,50,100,500,1000, 5000, 10000};
	
	vector<int> insert_arr;
	vector<int> 
	
	for(int i=0; i<12; i++){
		
		for(int j=0; j<
		
	}
}



*/






















