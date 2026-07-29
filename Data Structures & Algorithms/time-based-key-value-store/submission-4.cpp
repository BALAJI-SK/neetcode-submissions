class TimeMap {
    private:
    unordered_map<string, vector<pair<int,string>>>umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp,value});
       
    }
 
    string get(string key, int timestamp) {
        if (umap.find(key) == umap.end()) {
        return "";
    }
        auto & arr = umap[key];

        int l = 0,h=arr.size()-1,ans=-1;
        while(l<=h){
            // cout << l << " "<< h << " "<< ans <<endl;
            int mid = (h+l)/2;
            if(arr[mid].first==timestamp)return arr[mid].second;
            if(arr[mid].first<timestamp){
                l=mid+1;
                ans=mid;
                
            }else{
                h=mid-1;
            }
          // cout << l << " "<< h << " "<< ans <<endl;
        }
        return ans ==-1 || ans==arr.size() ?"": arr[ans].second;
       
    }
};
