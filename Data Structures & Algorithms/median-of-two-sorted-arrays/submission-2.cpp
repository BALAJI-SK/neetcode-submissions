class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        int totn = n+m;
        if(n==0 || m==0){
            if(n==0)return m%2?nums2[m/2]:(nums2[m/2-1]+nums2[m/2])/2.0;
            if(m==0)return n%2?nums1[n/2]:(nums1[n/2-1]+nums1[n/2])/2.0;
        }
        int mid1=nums1[0],mid2=nums1[0];
        int i=0,j=0,k=0;
        while(i<n && j<m && k<(totn/2 +1)){
            if(nums1[i]<=nums2[j]){
                mid2=mid1;
                mid1=nums1[i];
                    i++;
            }else{
               mid2=mid1;
                mid1=nums2[j];  
                j++;
            }
        k++;}
        while(k!=(totn/2+1) && i<n){
             mid2=mid1;
                mid1=nums1[i];
                    i++;
                    k++;
        }
         while(k!=(totn/2+1) && j<m){
             mid2=mid1;
                mid1=nums2[j];
                    j++;
                    k++;
        }
        if(totn%2){
            return mid1;
        }else{
            return (mid1+mid2)/2.0;
        }
    }
};
