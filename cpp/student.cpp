#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>

class Student
{
private:
    std::string name_;
    int chinese_, math_, english_;

public:
    Student(std::string &name, int chinese, int math, int english) : name_(name), chinese_(chinese), math_(math), english_(english) {}

    const std::string &name() const { return name_; }
    int chinese() const { return chinese_; }
    int math() const { return math_; }
    int english() const { return english_; }

    const int total() const
    {
        return chinese_ + math_ + english_;
    }

    const double average() const { return total() / 3.0; }
};

std::ostream &operator<<(std::ostream &os, const Student &s)
{
    return os << std::setw(12) << std::left << s.name()
              << std::right
              << " 语文:" << s.chinese()
              << " 数学:" << s.math()
              << " 英语:" << s.english()
              << " 总分:" << s.total();
}

class GradeBook
{
private:
    std::vector<const Student &> students_;

public:
    void add(const Student &s)
    {
        students_.push_back(s);
    }

    void rank_by_total()
    {
        std::sort(students_.begin(), students_.end(), [](const Student &a, const Student &b)
                  { return a.total() < b.total(); });
    }

    void sort_by_subject(int (Student::*getter)() const)
    { // 参数是成员指针
        std::sort(students_.begin(), students_.end(), [getter](const Student &a, const Student &b)
                  { return (a.*getter)() > (b.*getter)(); });
    }

    std::map<std::string, int> segment_stats() const
    {
        std::map<std::string, int> stats{
            {"优秀(>=270)", 0}, {"及格(>=180)", 0}, {"不及格(<180)", 0}};
        for (auto &s : students_)
        {
            int t = s.total();
            if (t >= 270)
                stats["优秀(>=270)"]++;
            else if (t >= 180)
                stats["及格(>=180)"]++;
            else
                stats["不及格(<180)"]++;
        }
        return stats;
    }

    const Student* find(const std::string& name) const {
        auto it = std::find_if(students_.begin(), students_.end(),
            [&](const Student& s) { return s.name() == name; });
        return it == students_.end() ? nullptr : &(*it);
    }

    void list() const {
        for (const auto& s : students_) std::cout << s << "\n";
    }



};