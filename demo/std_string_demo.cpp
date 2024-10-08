#include <string.h>
#include <iostream>
#include <sstream> //字符串流
#include <map>
#include <algorithm>

/**
 * @Vito
 * 要求：创建一个程序，接受用户输入的一段文本，提供以下的功能
 * 1. 统计单词数量
 * 2. 统计每个词出现的次数
 * 3. 查找指定单词出现的次数
 * 4. 输出最长的单词
 */

int main(int argc, char* argv[]){
    std::string text;
    std::cout << "Enter a text (结束请输入Ctrl+D/Ctrl+z):\n";

    //读取整段文本
    std::ostringstream oss;
    std::string line;
    while(std::getline(std::cin, line)){
        if(line.empty()){
            break;
        }
        oss << line << " ";
    }

    text = oss.str();

    //使用字符串流分割单词
    std::stringstream ss(text);
    std::string word;
    std::map<std::string,int> wordCount;
    size_t totalWords = 0;
    std::string longestWord;

    while(ss >> word){
        //去除标点符号
        word.erase(std::remove_if(word.begin(), word.end(),
        [](char c){ return ispunct(c);}), word.end());

        //转为小写
        std::transform(word.begin(), word.end(),word.begin(), ::tolower);

        if(!word.empty()){
            wordCount[word]++;
            totalWords++;
            if (word.length() > longestWord.length())
            {
                longestWord = word;
            }
        }
    }

    std::cout <<"\n统计结果:\n";
    std::cout <<"总单词数： "<< totalWords << std::endl;
    std::cout <<"每个单词出现的次数：\n";
    for(const auto& p : wordCount){
        std::cout << p.first << ": " << p.second << std::endl;
    }

    std::cout << "\n最长单词: " << longestWord << std::endl;


    //查找指定单词出现的次数
    std::string searchWord;
    std::cout << "\n请输入要查找的单词:";
    std::cin >> searchWord;

    //转为小写
    std::transform(searchWord.begin(),searchWord.end(),searchWord.begin(),::tolower);
    auto it = wordCount.find(searchWord);
    if(it != wordCount.end()){
        std::cout << "'" << searchWord << "' 出现了 " << it->second << " 次数\n" << std::endl;
    }else{
        std::cout << "'" << searchWord << "' 未在文本中找到\n" << std::endl;
    }

}
