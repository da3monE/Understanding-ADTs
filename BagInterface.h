//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
/** Listing 1-1.
    @file BagInterface.h */
#ifndef BAG_INTERFACE_
#define BAG_INTERFACE_

#include <vector>

template<class ItemType>
class BagInterface
{
public:
   /** Gets the current number of entries in this bag.
    @return  The integer number of entries currently in the bag. */
   virtual int getCurrentSize() const = 0;
   
   /** Sees whether this bag is empty.
    @return  True if the bag is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to this bag.
    @post  If successful, newEntry is stored in the bag and
       the count of items in the bag has increased by 1.
    @param newEntry  The object to be added as a new entry.
    @return  True if addition was successful, or false if not. */
   virtual bool add(const ItemType& newEntry) = 0;
   
   /** Removes one occurrence of a given entry from this bag,
       if possible.
    @post  If successful, anEntry has been removed from the bag
       and the count of items in the bag has decreased by 1.
    @param anEntry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool remove(const ItemType& anEntry) = 0;
   
   /** Removes all entries from this bag.
    @post  Bag contains no items, and the count of items is 0. */
   virtual void clear() = 0;
   
   /** Counts the number of times a given entry appears in this bag.
    @param anEntry  The entry to be counted.
    @return  The number of times anEntry appears in the bag. */
   virtual int getFrequencyOf(const ItemType& anEntry) const = 0;
   
   /** Tests whether this bag contains a given entry.
    @param anEntry  The entry to locate.
    @return  True if bag contains anEntry, or false otherwise. */
   virtual bool contains(const ItemType& anEntry) const = 0;
  
   /** Empties and then fills a given vector with all entries that
       are in this bag.
    @return  A vector containing all the entries in the bag. */
   virtual std::vector<ItemType> toVector() const = 0;
   
   /** Destroys this bag and frees its assigned memory. (See C++ Interlude 2.) */
   virtual ~BagInterface() { }

   /** Modify this bag so that all items in the bag
   have a “frequency” (count) value of 1.
   @return True if the bag was changed; otherwise return false. */
   virtual bool flatten() = 0;

   /** Finds the item in this bag with the smallest “frequency”,
   and removes all occurrences of that item.
   In case of a tie for smallest frequency, select any one of
   those items and remove all occurrences of that item.
   @return True if at least one item was removed;
   otherwise return false. */
   virtual bool reduce() = 0;

   /** Replaces all occurrences of anEntry in this bag with the
   user-provided newEntry. If anEntry is not present, makes
   no changes to the bag and returns false.
   @param anEntry The entry to be replaced, if already present
   in the bag.
   @param newEntry A new value that will replace all
   occurrences of anEntry in the bag.
   @return True if at least one occurrence was replaced;
   otherwise return false. */
   virtual bool replace(const ItemType& anEntry,
	   const ItemType& newEntry) = 0;

}; // end BagInterface
#endif