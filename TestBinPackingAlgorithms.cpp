/*
Assignment 5 - Bin Packing Algorithms 
By: Brandon Troche
Professor Stamos
Computer Science 335
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <queue> 

using namespace std;

//Primitive, random items and random start bin.
int NextFitBinPacking(std::vector<double> bin_s, std::vector<double> item){

	std::vector<double> bin = bin_s; //Create a copy of the vector of bins
	

for(int i=0; i<item.size(); i++){

		for( int j = 0; j<bin.size(); j++){
			if(item[i] > bin[j]){		//Check to see if the item size is larger than the current bin capacity
				bin.push_back(item[i]);		//If it is then we add it to a new bin and add that bin to current bins
				j = bin.size();		//Break out of the inner loop
			} else {
				bin[j] -= item[i];	//If it fits in the bin then I subtract its size from the current bin capacity
				j = bin.size(); //Break out of the inner loop
			}

		}


}

	return bin.size();		//Return the number of bins after the loop

}

//Unsorted, sorted bin values and unsorted random items.
int FirstFitBinPacking(std::priority_queue<double> bin_s, std::vector<double> item){

	std::priority_queue<double> bin = bin_s;

	for(int i=0; i<item.size(); i++){		//For all items in the list of items

	if(item[i] > bin.top()){			//If the current item does not fit into the most free bin
		bin.push(item[i]);					//then we push the item into a new bin to the priorirty queue
	} else {					//If the item fits into the most free bin
		double temp = bin.top();
			temp -= item[i];		//then subtract the size of the item from the capacity of the bin
			bin.pop();				//and get rid of the old bin size
			bin.push(temp);			//and replace it with the new bin size to be re-sorted by the priority queue
	}

}

	return bin.size();		//return the number of bins

}

//Sorted bin values and sorted item values. 
int FirstFitBinPackingDecreasing(std::priority_queue<double> bin_s, std::priority_queue<double> item){

	std::priority_queue<double> bin = bin_s;

while(!item.empty()){		//While we still have items to add to bins

	if(item.top() > bin.top()){		//If the largest item does not fit in the most free bin
		bin.push(item.top());		//create a new bin for that item and push it to the queue
		item.pop();					//and delete the item from the queue of items as it is now used
	} else {
		double temp = bin.top();		//Else we subtract the value of the largest item 
			temp -= item.top();			//from the capacity of the most free bin
			bin.pop();					//and replace the old bin capacity
			bin.push(temp);				//with the new bin capacity to be re-sorted by the queue.
			item.pop();					//Then we get rid of the item from the list of items.
	}

}

	return bin.size();		//return the number of bins

}

std::priority_queue<double> GenerateRandomNumbers(int numbers){

	std::priority_queue<double> myBin;

	srand(time(0)); //use current time as seed for random generator 
		for (int i = 0; i < numbers; i++) {
			const double random_variable = (double)rand() / (double)RAND_MAX; // Push it into the vector of random numbers.
			myBin.push(random_variable);
		}

	return myBin;

}

std::vector<double> GenerateRandomNumbersV(int numbers){

	std::vector<double> myBin;

	srand(time(0)); //use current time as seed for random generator 
		for (int i = 0; i < numbers; i++) {
			const double random_variable = (double)rand() / (double)RAND_MAX; // Push it into the vector of random numbers.
			myBin.push_back(random_variable);
		}

	return myBin;

}

int main(int argc, char **argv){

	if (argc != 2) {
   		cout << "Usage: " << argv[0] << " <Number_Of_Items>" << endl;
    	return 0;
 	}

 	

 	const string num_of_items(argv[1]);
 	const int N(stoi(num_of_items));

 	std::priority_queue<double> bin_sizes_sorted = GenerateRandomNumbers(1);
 	std::priority_queue<double> random_numbers_sorted = GenerateRandomNumbers(N);
 	std::vector<double> random_numbers = GenerateRandomNumbersV(N);
  	std::vector<double> bin_sizes = GenerateRandomNumbersV(1);

 	/*cout<<bin_sizes.size()<<endl;

 	while(!bin_sizes.empty()){
 		cout<<bin_sizes.top()<<endl;
 		bin_sizes.pop();
 	}

 	cout<<bin_sizes.size()<<endl;

 	cout<<random_numbers.size()<<endl;

 	while(!random_numbers.empty()){
 		cout<<random_numbers.top()<<endl;
 		random_numbers.pop();
 	}

 	cout<<random_numbers.size()<<endl;*/


 	const int number_of_bins_next_fit = NextFitBinPacking(bin_sizes, random_numbers); 
 	const int number_of_bins_first_fit = FirstFitBinPacking(bin_sizes_sorted, random_numbers);
 	const int number_of_bins_first_fit_decreasing = FirstFitBinPackingDecreasing(bin_sizes_sorted, random_numbers_sorted);

 	cout<<"Next Fit: "<<number_of_bins_next_fit<<endl<<"First Fit: "<<number_of_bins_first_fit<<endl<<"First Fit Dec: "<<number_of_bins_first_fit_decreasing<<endl;

 	

}