# Understanding-ADTs
This project was done so I could better understand abstract data types.

An array called "ArrayBag" is to be modified with a new public method called "flatten." 

This method handles all contents of the bag have a count/value of one. It returns true if any contents were changed and false otherwise.

A second public method is added called "reduce" to find content in the bag with the lowest frequency and delete those instances.

The third method "replace," removes instances of entries(anEntry) with user-inputted entries(newEntry). Returns false if anEntry isn't present. Returns false if there are no changes to the bag.

A constructor is added to create a bag from an array of user-inputted data.

A final public method is added called "bagUnion" uses the union operation. It creates a new bag from a new bag, and an old bag, and returns true.
