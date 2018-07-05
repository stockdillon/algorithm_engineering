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
	
	std::vector<int> vect;
	
	int n;
	cout << "enter an input size: " << endl;
	cin >> n;
	
	std::multiset<int> mset;
	
	int arr[n];	
	
	double mset_start_time;
	double vect_start_time;
	double mset_total;
	double vect_total;
	
	for(int i=0; i<n; i++){
		int new_int = rand() % 1000000;
		mset_start_time = std::clock();
		mset.insert(new_int);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		
		vect_start_time = std::clock();
		insert_sorted(vect, new_int);
		vect_total += (std::clock() - vect_start_time) / CLOCKS_PER_SEC;
		
		arr[i] = new_int;
	}
	
	
	////////////////////////////////////////////////////////////////
	/*
	cout << "displaying vector after inserts..." << endl;
	for(int i : vect){
		cout << i << " ";
	}
	cout << endl;
	*/
	////////////////////////////////////////////////////////////////
	
	
	
	for(int i=0; i<n; i++){
		mset_start_time = std::clock();
		mset.erase(arr[i]);
		mset_total += (std::clock() - mset_start_time) / CLOCKS_PER_SEC;
		
		vect_start_time = std::clock();
		vect.erase(binary_find(vect.begin(), vect.end(), arr[i]));
		vect_total += (std::clock() - vect_start_time) / CLOCKS_PER_SEC;
	}
	
	
	cout << "multiset time: " << mset_total << endl;
	cout << "vect time: " << vect_total << endl;
	
}

