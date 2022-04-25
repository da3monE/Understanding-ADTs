//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Header file for an array-based implementation of the ADT bag. Listing 3-1.
 @file ArrayBag.h */

#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
   static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
   ItemType items[DEFAULT_CAPACITY];      // Array of bag items 
   int itemCount;                         // Current count of bag items 
   int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();// first constructor
	ArrayBag(const ItemType arr[], int size);// second constructor
	int getCurrentSize() const;// returns current size of array
	bool isEmpty() const;// returns true/false whether or not the bag is full or not
	bool add(const ItemType& newEntry);// adds item to bag
	bool remove(const ItemType& anEntry); // removes item to bag
	void clear(); // clears bag
	bool contains(const ItemType& anEntry) const; //returns true/false if bag contains an entry
	int getFrequencyOf(const ItemType& anEntry) const;// returns frequency of item in bag
    std::vector<ItemType> toVector() const;// returns a vector that has all elements in bag
	bool flatten();// returns true/false if the bag was changed
	bool reduce();//  returns true/false if an item/s with frequency of 1 has been removed
	bool replace(const ItemType& anEntry,// returns true/false depending if instances of item has been replaced
		const ItemType& newEntry);

	/** Creates a new bag and returns it. The new bag is the union
	of the current bag and the parameter bag2.
	The current bag is not modified, and bag2 is not modified.
	@param bag2 A bag providing input for the union operation.
	@return A bag that results from the union operation. */
	ArrayBag<ItemType> bagUnion(const ArrayBag<ItemType>& bag2) const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
