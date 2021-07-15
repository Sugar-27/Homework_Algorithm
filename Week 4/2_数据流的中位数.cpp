#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int> > lo;
    priority_queue<int, vector<int>, greater<int> > hi;
    MedianFinder() {}

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? (double)lo.top()
                                     : (lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */