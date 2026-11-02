#include <map>
#include <iostream>
#include <algorithm>
int main()
{
#include <map>

    std::map<std::string, int> scores;
    scores["alice"] = 95; // 插入/更新
    scores["bob"] = 88;
    scores["mj"] = 67;
    scores["miejianguo"] = 55;

    std::cout << scores["alice"]; // 读取：95
    auto it = scores.find("bob"); // 查找
    if (it != scores.end())
    { /* 找到了 */
        for (const auto &[name, score] : scores)
        {
            std::cout << name << ": " << score << "\n";
        }
    }
}