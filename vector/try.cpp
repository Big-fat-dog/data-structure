#include<iostream>
#include<vector>
using namespace std;
int main(){
    //创建一个int类型的动态数组
    vector<int> myv;
    myv.push_back(1);
    myv.push_back(2);
    myv.push_back(3);
    myv.push_back(4);
    myv.push_back(5);
    myv.push_back(6);
    cout<<"element are: ";
    for(int i=0;i<myv.size()-1;i++){
        cout<<myv[i];
    }
    cout<<"\n";
    //删除第三个元素
    myv.erase(myv.begin()+2);
    //访问第二个元素
    cout<<myv.at(1)<<endl;
    // 输出删除元素后的向量
    std::cout << "Elements in the vector after erasing: ";
    for (int element : myv) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 清空向量并输出
    myv.clear();
    std::cout << "Size of the vector after clearing: " << myv.size() << std::endl;
}