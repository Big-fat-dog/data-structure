class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        for(long long i=1;i<x;i++){
        if(i*i<=x&&(i+1)*(i+1)>x) return i;
        }
        return 0;
    }
};