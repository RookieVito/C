#include <iostream>
using namespace std;
/** CPP结构体和类
 * 1. 支持继承和多态
 * 2. 都支持访问控制
 * 3. 都可以包含成员变量和成员函数
 * 
 * 区别：
 * 结构体默认访问权限是public
 * 类默认访问权限是private
 * 
 * 用途习惯：
 * 结构体：通常用于纯数据结构，主要存储数据，成员通常公开
 * 类：通常包含数据和操作数据的函数，支持更加复杂的封装
 */
struct Student{
    int id;
    std::string name;

    // 构造函数
    Student(int studentId, std::string studentName):
        id(studentId), name(studentName){}

    // 保留默认构造函数
    Student(){}
};

void base_struct_using(){
    //创建结构体
    struct Student stu1;

    //使用.进行赋值和访问
    stu1.id = 1001;
    stu1.name = "Tom";

    //两种初始化方法
        //直观初始化
    struct Student stu2 = {1002, "Jerry"};

        //逐个赋值
    struct Student stu3;
    stu3.id = 1003;
    stu3.name = "Lily";

    //自定义的构造函数
    struct Student stu4(1004,"bob");
}

void embed_struct(){
    struct School{
        std::string schoolName;
        int studentCount;
        struct Student stu;
    };
    School school;
    struct Student stu(1001,"bob");
    school.schoolName = "Beijing University";
    school.studentCount = 1000;
    school.stu = stu;
}

void struct_vector(){
    struct Student students[] = {
        {1001, "Student1"},
        {1002, "Student2"},
        {1003, "Student3"}
    };

    for (int i = 0; i < 3; i++){
        std::cout << "student id is " << students[i].id 
                  << "student name is "<< students[i].name 
                  << std::endl;
    }

}

void struct_pointer(){

    // 使用-> 访问结构体中的成员
    struct Student *stu = new Student(1005, "Alice");
    std::cout << "student id is " << stu->id 
              << "student name is "<< stu->name 
              << std::endl;

    delete stu;

    struct Student stu2 = {1006, "Bob"};
    struct Student *stu2_p = &stu2;
    std::cout << "student id is " << stu2_p->id 
              << "student name is "<< stu2_p->name 
              << std::endl;
}

void struct_alias(){
    typedef struct {
        int id;
        struct Student stu;
    }Class;

    // or using need the C++11
    using _class2 = struct 
    {
        int id;
        Student stu;
    };

    //then you can use _class as follows
    struct Student stu(1007, "Eve");
    Class cls1 = {445, stu};
}


struct Point{
    int x;
    int y;
};

void printPoint(Point p){
    std::cout << "Point(" << p.x << "," << p.y << ")" << std::endl;
}


void movePoint(Point &p){
    p.x += 1;
    p.y += 1;
};
void struct_delivery(){
    typedef struct Point Point;
    Point p1 = {1, 2};
    //通过值传递
    printPoint(p1);

    //通过引用传递
    movePoint(p1);
}

struct Area{
    int value;
};

struct Rectangle{
    int width;
    int height;
};

Area calculateArea(Rectangle r){
    Area area;
    area.value = r.width * r.height;
    return area;
}

void calculateArea(){
    Rectangle r = {5, 3};
    Area area = calculateArea(r);
    std::cout << "Area is: " << area.value << std::endl;
}
int main(){
    base_struct_using();
    struct_delivery();
    struct_vector();
    calculateArea();
}