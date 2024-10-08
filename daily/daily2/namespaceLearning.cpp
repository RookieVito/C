#include <iostream>

//显示的声明需要的命名空间中的函数
using std::cin;
using std::cout;
int main(){
    int i;
    cin >> i;
    cout << "The entered number is: " << i << std::endl;
    return 0;
}