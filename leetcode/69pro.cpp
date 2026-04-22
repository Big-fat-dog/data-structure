class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x;
        long long  middle;
        if(x==0||x==1) return x;
        while(left<=right){
            middle=left+(right-left)/2;
            if(middle*middle<x&&(middle+1)*(middle+1)>x||middle*middle==x) return middle;
            else if(middle*middle<x){
                left=middle+1;
            }
            else if(middle*middle>x){
                right=middle-1;
            }
        }
        return 0;
    }
};