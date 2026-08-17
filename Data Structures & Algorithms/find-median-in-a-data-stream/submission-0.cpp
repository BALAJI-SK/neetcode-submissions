class MedianFinder {
    private:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    int size_max,size_min;
public:
    MedianFinder() {
        size_max=0;
        size_min=0;
    }
    
    void addNum(int num) {
        if( !minh.empty() && minh.top()<=num){
        minh.push(num);
            size_min++;
            if(abs(size_max-size_min)>=2){
            maxh.push(minh.top());
            minh.pop();
            size_min--;
            size_max++;
        }
        }else{
          maxh.push(num);
        size_max++;
        if(abs(size_max-size_min)>=2){
            minh.push(maxh.top());
            maxh.pop();
            size_max--;
            size_min++;
        }
        }
    }
    
    double findMedian() {
        //cout << size_max << " "<< size_min<<endl;
        if(size_max+size_min==0)return 0;
        if((size_max+size_min)%2){
            return size_max>size_min? maxh.top():minh.top();
        }
            return (maxh.top()+minh.top())/2.0;
        
    }
};
