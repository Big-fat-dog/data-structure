#include<memory>
#include<iostream>
int main(){
    auto s1 = std::make_shared<int>(67);
    std::cout << "after make_shared: " << s1.use_count() << "\n"; // 1

    auto s2 = s1;
    std::cout << "after copy s2:     " << s1.use_count() << "\n"; // 2


    std::weak_ptr<int> w = s1;   // weak 不增加强引用计数
    std::cout << "after weak w:      " << s1.use_count() << "\n"; // 仍是 2

    s1.reset();
    std::cout << "after s1.reset:    " << s2.use_count() << "\n"; // 1
    std::cout << "weak lock alive?   " << (w.lock() ? "yes" : "no") << "\n"; // yes

    s2.reset();   // 计数归 0，对象被 delete，weak 此后 lock() 返回 null
    std::cout << "after s2.reset:    " << (w.lock() ? "yes" : "no") << "\n"; // no
}