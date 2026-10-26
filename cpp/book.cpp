#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>
class Book {
private:
    std::string title_;
    std::string  author_;
    double price_;
    int stock_;
public:
    Book(std::string title,std::string author,double price,int stock): title_(std::move(title)),author_(std::move(author)),
    //这里初始化两个字符串用了移动语义，减少了拷贝的开销
    price_(price),stock_(stock){}

    const std::string& title()const{return title_;}
    const std::string& author()const{return author_;}
    double price()const {return price_;}
    int stock()const {return stock_;}
    void set_stock(int x){stock_=x;}
};
//重载输出运算符
std::ostream& operator<<(std::ostream& os,const Book& b){
    return os<<b.title()<<" | "<<b.author()<<" | "<<b.price()<<"元 | 库存："<<b.stock();
}

class Bookstore{
private:
    std::vector<Book> books_;
public:
    void add(const Book& b){
        books_.push_back(b);
    }
    const Book* find(const std::string& title)const{
        auto it = std::find_if(books_.begin(),books_.end(),
            [&](const Book& b){return b.title()==title;}
        );
        return it==books_.end() ? nullptr: &(*it);
    }
    bool remove(const std::string& title){
        auto it = std::find_if(books_.begin(),books_.end(),
            [&](const Book& b){return b.title()==title;}
        );
        if(it!=books_.end()){
            books_.erase(it);
            return true;
        }
        return false;
    }

    void sort_by_price(){
        std::sort(books_.begin(),books_.end(),[](const Book&a,const Book&b){return a.price()<b.price();});
    }

    void list(){
        if (books_.empty()) std::cout << "（书库为空）\n";
        for(const auto&  b:books_){
            std::cout<<b<<"\n";
        }
    }
    std::size_t size() const { return books_.size(); }
};
int main(){
    Bookstore store;
    std::cout<<"=========图书管理系统=========";
    std::cout<<"(1)添加书籍"<<"\n"<<"(2)删除图书"<<"\n"<<"(3)查找图书"<<"\n"<<"(4)按照价格排序"<<"\n"<<"(5)列出全部"<<"\n"<<"(0)退出";
    while(true){
        std::cout<<"请输入：";
        int x;
        std::cin>>x;
        if(x==0)break;
        switch(x){
            case 1:{
                std::string title;
                std::string author;
                double price;
                int stock;
                std::cout<<"书名：";
                std::cin>>title;
                std::cout<<"作者：";
                std::cin>>author;
                std::cout<<"价格：";
                std::cin>>price;
                std::cout<<"库存：";
                std::cin>>stock;
                Book b(title,author,price,stock);
                store.add(b);
                std::cout<<"已经添加了："<<title;
                break;
            }
            case 2:{
                std::string title;
                std::cout<<"书名：";
                std::cin>>title;
                store.remove(title);
                break;
            }
            case 3:{
                std::string title;
                std::cout<<"书名：";
                std::cin>>title;
                const Book *book = store.find(title);
                std::cout<<book->author()<<" "<<book->price();
                break;
            }
            case 4:{
                store.sort_by_price();
                std::cout<<"排序完成";
                break;
            }
            case 5:{
                store.list();
                break;
            }
        }
    }
    return 0;
}