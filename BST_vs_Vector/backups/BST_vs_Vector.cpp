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
#include <algorithm>
using std::cout; using std::endl; using std::cin;



int binary_search_delete(int num_to_delete, int begin, int end, std::vector<int> vec){
	unsigned i = (end - begin)/2;
	cout << "i: " << i << endl; //remove
	
	if(i ==0 && vec[i] != num_to_delete) return -1;
	if(i ==vec.size() - 1 && vec[i] != num_to_delete) return -1;

	
	if( vec[i] > num_to_delete){
		return binary_search_delete( num_to_delete, begin, begin + i - 1, vec);
	}
	
	if(vec[i] < num_to_delete){
		return binary_search_delete(num_to_delete, begin + i + 1 , end, vec);
	}
	
	if(vec[i] == num_to_delete){
		cout << "found item at index : " << i << endl;
		return i;
	}
	
	return -1;
}




int binary_search_insert(int num_to_insert, int begin, int end, std::vector<int> vec){
	unsigned i = (end - begin)/2;
	
	cout << "finding insert index. " << endl; //remove
	cout << "i: " << i << endl; //remove
	cout << "num to insert: " << num_to_insert << endl; //remove
	
	if(vec.size() == 0) cout << "ERROR" << endl;
	cout << "no error." << endl;
	
	if(i ==0 && vec[i] != num_to_insert) return -1;
	if(i ==vec.size() - 1 && vec[i] != num_to_insert) return -1;
	
	if( vec[i] >= num_to_insert){
		if(vec[i-1] < num_to_insert) return i;
		return binary_search_insert( num_to_insert, begin, begin + i, vec);
	}
	
	if(vec[i] <= num_to_insert){
		if(vec[i+1] > num_to_insert) return i+1;
		return binary_search_insert(num_to_insert, begin + i, end, vec);
	}
	
	/*
	if(vec[i] == num_to_insert){
		cout << "found item at index : " << i << endl;
		return i;
	}
	*/
	
	return -1;
}



// http://stackoverflow.com/questions/15843525/how-do-you-insert-the-value-in-a-sorted-vector
template< typename T >
typename std::vector<T>::iterator 
   insert_sorted( std::vector<T> & vec, T const& item )
{
    return vec.insert
        ( 
            std::upper_bound( vec.begin(), vec.end(), item ),
            item 
        );
}




// http://stackoverflow.com/questions/446296/where-can-i-get-a-useful-c-binary-search-algorithm
template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}






int main(){
	
	
	/////////////////////////////////////////////////
	/*
	std::vector<int> vect = {0,1,2,3,4,5,6,7,8};
	binary_search_delete(1, 0, vect.size() - 1, vect);
	vect.erase(vect.begin() + binary_search_delete(1, 0, vect.size() - 1, vect));
	for(int i : vect){
		cout << i << " ";
	}
	cout << endl;
	*/
	/////////////////////////////////////////////////
	
	
	std::vector<int> vect;
	
	int n;
	cout << "enter an input size: " << endl;
	cin >> n;
	
	std::multiset<int> mset;
	//std::unordered_multiset<int> htable;
	
	int arr[n];
	//int count = 0;
	
	
	
	double mset_start_time;
	double vect_start_time;
	double mset_total;
	double vect_total;
	
	for(int i=0; i<n; i++){
		int new_int = rand() % 1000000;
		mset_start_time = std::clock();
		mset.insert(new_int);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		///////////////////////////////////
		vect_start_time = std::clock();
		/*
		if(vect.size() == 0) vect.push_back(new_int);
		else if(new_int >= vect[vect.size() - 1]) vect.push_back(new_int);
		else if(new_int <= vect[0]) vect.insert(vect.begin(), new_int);
		else {vect.insert(vect.begin() + binary_search_insert(new_int, 1, vect.size() -2, vect), new_int);}
		*/
		insert_sorted(vect, new_int);
		vect_total += (std::clock() - vect_start_time) / CLOCKS_PER_SEC;
		////////////////////////////////////////
		arr[i] = new_int;
	}
	
	
	////////////////////////////////////////////////////////////////
	cout << "displaying vector after inserts..." << endl;
	for(int i : vect){
		cout << i << " ";
	}
	cout << endl;
	////////////////////////////////////////////////////////////////
	
	
	
	for(int i=0; i<n; i++){
		mset_start_time = std::clock();
		mset.erase(arr[i]);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		
		/////////////////////////////////
		vect_start_time = std::clock();
		vect.erase(binary_find(vect.begin(), vect.end(), arr[i]));
		//vect.erase(vect.begin() + binary_search_delete(arr[i], 0, vect.size()-1, vect));
		vect_total += (std::clock() - vect_start_time) / CLOCKS_PER_SEC;
		/////////////////////////////////
	}
	
	
	cout << "multiset time: " << mset_total << endl;
	cout << "vect time: " << vect_total << endl;
	
	/////////////////////////////////////////////
	/*
	vect.insert(vect.begin() + 5 , 99);
	
	cout << "displaying vector..." << endl;
	for(int i : vect){
		cout << i << " ";
		cout << "?" << " ";
	}
	cout << endl;
	*/
	/////////////////////////////////////////
	
	
	//cout << (std::clock() - start_time) / CLOCKS_PER_SEC << endl;
	
}

