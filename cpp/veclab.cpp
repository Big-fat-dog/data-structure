#include<iostream>
#include<vector>

void veclab(std::vector<int>& v){
    int m = v.size();
    int n = v.capacity();
    int a = v[0];
    int b = v[2];
    a=b;
    v.push_back(22);
    v.push_back(33);
    v.push_back(67);
}

int main(){
    std::vector<int> v;
    v.reserve(5);
    for(int i=0;i<5;i++){
        v.push_back(i);
    }
    std::cout<<v.size();
    std::cout<<v.capacity();

    veclab(v);

    for(auto& x:v){
        x*=2;
    }
}