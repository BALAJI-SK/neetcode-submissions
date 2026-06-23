class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height .size();
        int maximum = 0 ;
        int j = n-1 ;
        int i = 0;
      
        
            while(j>i){
                int c = min(height[i],height[j])*(j-i);
                maximum = max(maximum,c );
                if(height[i]<height[j]) {
                    i++;
                }
                else j--;
            }
        
        return maximum ;

        
    }
};
