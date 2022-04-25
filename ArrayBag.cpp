#include "ArrayBag.h"
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(const ItemType arr[], int size) 
{
	itemCount = size;
	maxItems = DEFAULT_CAPACITY;
	for (int i = 0; i < size; i++)
	{
		items[i] = arr[i];
	}
} // end new constructor


template<class ItemType>
inline ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType>& bag2) const
{
	return ArrayBag<ItemType>();
} // end bag union


template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0; //returns true or false
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
   bool hasRoomToAdd = (itemCount < maxItems);
   if (hasRoomToAdd)
   {
       items[itemCount] = newEntry;
       itemCount++;
   } // end if

   return hasRoomToAdd;
}  // end add

/*
// STUB
 template<class ItemType>
 bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
 {
    return false; // STUB
 }  // end remove
*/   
 
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

/*
 // STUB
 template<class ItemType>
 void ArrayBag<ItemType>::clear()
 {
    // STUB
 }  // end clear
*/

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector


template<class ItemType>
bool ArrayBag<ItemType>::flatten()
{
	bool flatCheck = false;
	int size = getCurrentSize();
	for (int i = 0; i < size; i++)
	{
		if (getFrequencyOf(items[i]) > 1)
		{
			remove(items[i]);
			flatCheck = true;
		}// end if
	}
	return flatCheck;
}// end flatten

template<class ItemType>
bool ArrayBag<ItemType>::reduce()
{
	if (isEmpty() == false)
	{
		int freq = getFrequencyOf(items[0]);
		for (int i = 0; i < getCurrentSize(); i++)
		{
			if (getFrequencyOf(items[i]) < freq)
				freq = getFrequencyOf(items[i]); //end if
		}
		int size = getCurrentSize();
		for (int i = 0; i < size; i++)
		{
			if (getFrequencyOf(items[i]) == freq)
			{
				remove(items[i]);
				freq--;
			}// end if
		}
		return true;
	}
	else
		return false;
}// end reduce

template<class ItemType>
bool ArrayBag<ItemType>::replace(const ItemType & anEntry, const ItemType & newEntry)
{
	for (int i = 0; i < getCurrentSize(); i++)
	{
		if (items[i] == anEntry)
		{
			items[i] = newEntry;
		}// end if
	}
	return true;
} // end replace


// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf
