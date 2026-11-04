#include <unordered_map>
#include <unordered_set>
#include <string>
int main()
{
    std::unordered_map<std::string, int> u;
    u["alice"] = 95;
    u["bob"] = 88;

    auto it = u.find("alice"); // 平均 O(1)
    u.count("alice");          // 0 或 1

    std::unordered_set<int> s = {3, 1, 2};
    s.insert(5);
    s.erase(3);
}