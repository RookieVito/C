#include <iostream>
#include <string.h>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <regex>


void string_class(){
    //C语言风格的字符串和C++字符串
    char vars[] = "abcdefgh";
    std::string str = "abcdefgh";
}

void string_init_methods(){
    std::string str0;                   // str0是一个空串
    std::string str1 = "hello";         //使用字符串字面值初始化
    std::string str2("world");          //使用字符串字面值初始化
    std::string str3 = "hello";

    std::string str4(str1);             //拷贝初始化，str4是str1的副本
    std::string str5(str3, 1, 3);       //使用str3的子串初始化，str5是"ell"

    std::string str6(5, 'x');           //使用指定字符和指定数量拷贝初始化“xxxxx”
}

void IPO_string(){
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;//读取直到第一个空白字符
    std::cout << "You entered: " << input << std::endl;

    /**
     * 读取包含空格的整行字符串
     */
    std::cout << "Enter a string: ";
    std::string input2;
    std::getline(std::cin, input2);
    std::cout << "You entered: " << input2 << std::endl;
}
//拼接字符串，比较字符串字典大小，查找与替换，子字符串与切片
void test1(){
    std::string str1 = "Hello";
    std::string str2 = "Hello ";
    std::string str3 = "World";
    size_t pos = str1.find("llo");
    std::cout << "the pos of the string \"llo\" is: " << pos << std::endl;

    str1.replace(pos, 3, "lle");
    std::cout << "After replace, str1 is: " << str1 << std::endl;
    
    std::cout << "the substring from the string str2 is (1,3): " << str2.substr(1, 3) << std::endl;
    std::cout << "the substring from the string str2 is (3,:): " << str2.substr(3) << std::endl;
    std::cout << "拼接字符串：" << str2 + str3 <<std::endl;
}

void string_arguments(){
    std::string str="can you give me a fine description?";
    std::cout << "the length of the string is: " << str.length() << std::endl;
    str += "yes, I can";
    std::cout << "the maximum length of the string witch don't need extra space is:"<< str.capacity() << std::endl;
    std::cout << "the length of added string is:" << str.length() << std::endl;
     
    //maybe is useless, but it presents the maximum number of characters the string can hold.
    std::cout << "the max_size of the string is:" <<str.max_size() << std::endl;
}

void string_operators(){
    std::string str;
    str = "Hello";
    
    /**
     * std::toupper and std::tolower can be used to convert a character to uppercase or lowercase.
     * combined with std::transform finish the stuff.
     */

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    std::cout << str << std::endl;

    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    std::cout << str << std::endl;

    //clearing the string 
    str.clear();

    if(str.empty()){
        std::cout << "The string is empty." << std::endl;
        str = "Hello world!";
    }
    //
    str.erase(0,5);
    std::cout << "After erase, the string is: " << str << std::endl;

    //insert a character at the beginning
    str.insert(0, "World ");
    std::cout << "After insert, the string is: " << str << std::endl;
}

//advanced using the string
void advanced_string(){
    //1. stringstream  std::stringsteam <sstream>
    // using stringstream for reading and writing to/from strings in memory ,similar to the file stream
    std::stringstream ss;
    ss << "Value: " << 42 << ", "<< 3.14;
    std::string result = ss.str();
    std::cout << "The result of the stringstream is: " << result << std::endl;

    //2. Type conversion of string to other types
    // to string
    int num = 100;
    double pi = 3.14159;
    std::cout << "The integer to string conversion is: " << std::to_string(num) << std::endl;
    std::cout << "The double to string conversion is: " << std::to_string(pi) << std::endl;

    // from string to other types
    std::string str = "123";
    int num1;
    std::stringstream ss1(str);
    ss1 >> num1;
    std::cout << "The string to integer conversion is: " << num1 << std::endl;

    // using std::stoi and std::stod to convert the type
    int num3 = std::stoi(str);
    //double pi = std::stod("3.14159");
    std::cout << "num:"<< num3 << std::endl;
}

void regexLearning(){
    //#include <regex>
    std::string text = "The quick brown for jumps over the lazy dog.";
    std::regex pattern(R"(\b\w{5}\b)"); //匹配所有5个字母的单词

    std::sregex_iterator it(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    std::cout<< "5个字母的单词有:"<<std::endl;
    while(it != end){
        std::cout <<(*it).str() << std::endl;
        ++it;
    }
}
void char_v_to_string(){
    // convert C string to C++ string 
    // only using CString init the C++ string for conversion
    const char* cstr = "Hello, C-strings!";
    std::string str(cstr);
    std::cout << str << std::endl;
}

//using str.c_str() to convert C++ string to C string 
void string_to_char_v(){
    std::string str = "Hello, std::strings!";
    const char* cstr = str.c_str();
    std::cout << cstr << std::endl;
}
int main(int argc, char *argv[]) {
    // IPO_string();
    // test1();
    string_arguments();
    string_operators();

    //TODO: understand how to use the lamba expression and do some exercise for std::transform
    std::string str = "Hello";
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){return std::toupper(c);});
    return 0;
}