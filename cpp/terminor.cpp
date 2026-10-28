#include<iostream>
#include<string>
#include<string_view>
#include <vector>
#include <optional>
#include <cstdlib>

struct Options{
    bool verbose = false;
    int count=1;
    std::vector<std::string> files;
};

// 解析-xxx和-x
bool is_option(std::string_view s){
    return s.size()>=2 && s[0] == '-';
}

Options parse_args(int argc,char* argv[]){
    Options opts;
    std::vector<std::string_view> args(argv+1,argc+argv);

    for(std::size_t i=0;i<args.size();++i){
        std::string_view a = args[i];
        if (a == "--help" || a == "-h") {
            std::cout << "用法: tool [选项] <文件...>\n"
                      << "  -v, --verbose   输出详细信息\n"
                      << "  -c, --count N   处理次数（默认 1）\n"
                      << "  -h, --help      显示帮助\n";
            std::exit(0);
        }
        else if (a == "--verbose" || a == "-v") {
            opts.verbose = true;
        }
        else if (a == "--count" || a == "-c") {
            if (i + 1 >= args.size()) {
                std::cerr << "错误: " << a << " 需要一个值\n";
                std::exit(1);
            }
            opts.count = std::stoi(std::string(args[++i]));  // 值就是下一个参数
        }
        else if (is_option(a)) {
            std::cerr << "错误: 未知选项 " << a << "\n";
            std::exit(1);
        }
        else {
            opts.files.emplace_back(a);   // 位置参数：文件
        }
    }
    return opts;
}

int main(int argc, char* argv[]) {
    Options opts = parse_args(argc, argv);

    if (opts.verbose) std::cout << "[verbose] 解析完成\n";
    if (opts.files.empty()) {
        std::cout << "没有指定文件。用 --help 查看用法。\n";
        return 1;
    }

    for (const auto& f : opts.files) {
        std::cout << "处理 " << f << " x" << opts.count << "\n";
    }
    return 0;
}