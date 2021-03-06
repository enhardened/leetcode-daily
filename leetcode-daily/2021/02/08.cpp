/*
Problem: https://leetcode.com/explore/item/3633
Title: Peeking Iterator
*/
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    bool hasPeeked = false;
    int peekedElement;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {        
        if (!hasPeeked) {
            hasPeeked = true;
            peekedElement = Iterator::next();
        }
        
        return peekedElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peekedElement;
        }
        
        return Iterator::next();
	}
	
	bool hasNext() const {
        return (hasPeeked || Iterator::hasNext());
	}
};
