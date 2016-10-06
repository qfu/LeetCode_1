/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    vector<int> flat;
    vector<int>::iterator it;
    void flatten(vector<NestedInteger> &nestedList){
        for(int i =0; i < nestedList.size(); ++i){
            if(nestedList[i].isInteger()){
                cout << nestedList[i].getInteger();
                flat.push_back(nestedList[i].getInteger());
            }
            else
                flatten(nestedList[i].getList());
        }
    }
    

public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        // need to flatten it and sort it
        flatten(nestedList);
        it = flat.begin();
    }

    int next() {
        return *(it++);
    }

    bool hasNext() {
    	//check has to stay at begin position
        if (it != flat.end())
            return true;
        else return false;
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */