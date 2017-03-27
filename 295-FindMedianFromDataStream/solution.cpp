class MedianFinder {
    priority_queue<int> l;                              // max heap
    priority_queue<int, vector<int>, greater<int>> r;   // min heap
public:
    MedianFinder() {

    }
    void addNum(int num) {
        l.push(num);
        r.push(l.top());
        l.pop();
        if(l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }
    }
    double findMedian() {
        return l.size() > r.size()? l.top(): ((long long)l.top()+r.top())*0.5;
    }
};
