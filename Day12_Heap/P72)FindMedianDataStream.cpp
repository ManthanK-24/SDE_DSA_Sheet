class MedianFinder {
public:
    // M1: Use vector and sort on each add
    // M2: Using Heap
    priority_queue<int> left, right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        right.push(-left.top());
        left.pop();
        if(right.size()>left.size())
        {
            left.push(-right.top());
            right.pop();
        }
    }
    
    double findMedian() 
    {
       if(left.size()>right.size())return left.top();
       
        return (left.top()-right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
