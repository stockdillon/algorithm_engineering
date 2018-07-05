/*
Dillon Stock stockdil@basset
2017-02-19
BST_vs_HashTable.cpp

Your Comments
*/

#include <iostream>
#include <set>
#include <unordered_set>
#include <ctime>
#include <vector>
using std::cout; using std::endl; using std::cin;



int binary_search(int num_to_delete, int begin, int end, std::vector<int> vec){
	int i = (end - begin)/2;
	cout << "i: " << i << endl; //remove
	if( vec[i] > num_to_delete){
		return binary_search( num_to_delete, begin, begin + i, vec);
	}
	
	if(vec[i] < num_to_delete){
		return binary_search(num_to_delete, begin , end, vec);
	}
	
	if(vec[i] == num_to_delete){
		cout << "found item at index : " << i << endl;
		return i;
	}
	
	return -1;
}




void vector_delete(std::vector<int> &vec, int index){
	return;
}


int main(){
	
	
	/////////////////////////////////////////////////
	std::vector<int> vect = {0,1,2,3,4,5,6,7,8};
	binary_search(1, 0, vect.size() - 1, vect);
	/////////////////////////////////////////////////
	
	
	int n;
	cout << "enter an input size: " << endl;
	cin >> n;
	
	std::multiset<int> mset;
	std::unordered_multiset<int> htable;
	
	int arr[n];
	//int count = 0;
	
	
	
	double mset_start_time;
	double htable_start_time;
	double mset_total;
	double htable_total;
	
	for(int i=0; i<n; i++){
		int new_int = rand() % 1000000;
		mset_start_time = std::clock();
		mset.insert(new_int);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		htable_start_time = std::clock();
		htable.insert(new_int);
		htable_total += (std::clock() - htable_start_time) / CLOCKS_PER_SEC;
		arr[i] = new_int;
		
	}
	
	for(int i=0; i<n; i++){
		mset_start_time = std::clock();
		mset.erase(arr[i]);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		
		htable_start_time = std::clock();
		htable.erase(arr[i]);
		htable_total += (std::clock() - htable_start_time) / CLOCKS_PER_SEC;
	}
	
	
	cout << "multiset time: " << mset_total << endl;
	cout << "hash table time: " << htable_total << endl;
	
	
	//cout << (std::clock() - start_time) / CLOCKS_PER_SEC << endl;
	
}

