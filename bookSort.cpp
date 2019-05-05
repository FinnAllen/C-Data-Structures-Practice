// @author Finnian Allen
// 5/4/2019
// ThriftBooks book sorting program
#include <string>
#include <iostream>
using namespace std;

struct book
{
	string name[10]; // stores the book names
	bool containsThe[10]; // used to flag books starting with substring "The "
};

// basic insertion sort algorithm that sorts by book name
// while also keeping track of which title contains "The "
// to prevent mix-up issues
void insertionSort(book& list, int n)
{ 
	for ( int unsorted = 1; unsorted < n; unsorted++)
	{
		// At this point, list[0..unsorted-1] is sorted.
		// Find the right position (loc) in list[0..unsorted]
		// for list[unsorted], which is the first entry in the
		// unsorted region; shift, if necessary, to make room
		string nextItem = list.name[unsorted];
		bool nextItem2 = list.containsThe[unsorted]; // you have to also move this variable too, or the program will confuse which book has "The " in it
		int loc = unsorted;

			while ((loc > 0) && (list.name[loc - 1] > nextItem))
			{
				list.name[loc] = list.name[loc - 1];
				list.containsThe[loc] = list.containsThe[loc - 1];
				loc--;
			}
	// At this point, list[loc] is where nextItem belongs
	list.name[loc] = nextItem;
	list.containsThe[loc] = nextItem2;
	}
} 
  
// checks if the book name array contains "The", and
// then flags it accordingly to remove "the" for
// sorting, and then to be added back after sorting,
// sorts by ASCII values in order to make the array
// lexicographical
void checkArray(book& list, int n) 
{  
    for (int i = 0; i < n; i++)
	{
		if (list.name[i].find("The") == 0) // if the is at the begining
		{
			list.containsThe[i] = true;
			list.name[i].erase(0, 4);
		} else {
			list.containsThe[i] = false;
		}
	}
} 

// prints the list of books in order,
// also determines if the have 
void printList(book list, int n) 
{  
    for (int i = 0; i < n; i++)
	{
		if(list.containsThe[i])
        cout << list.name[i].insert(0, "The ") << endl; // appends the back on the begging of the string
		else
		cout << list.name[i] << endl; // for the books without "The " in the title
	}
} 
 
 
int main() 
{ 
	book list;
	// these are just the example book names provided in the email
	list.name[0] = "Rich Dad, Poor Dad";
	list.name[1] = "To Kill a Mockingbird";
	list.name[2] = "Harry Potter and the Sorcerer's Stone";
	list.name[3] = "The Secret";
	list.name[4] = "The Four Agreements: A Practical Guide to Personal Freedom (A Toltec Wisdom Book)";
	list.name[5] = "The Five Love Languages: How to Express Heartfelt Commitment to Your Mate";
	list.name[6] = "The Great Gatsby";
	list.name[7] = "1984 (Signet Classics)";
	list.name[8] = "The Outsiders";
	list.name[9] = "The Book Thief";
	int n = sizeof(list.name) / sizeof(list.name[0]); // gets the size of the array
	checkArray(list, n);
	insertionSort(list, n);
	printList(list, n);
    return 0; 
}