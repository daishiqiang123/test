#include <vector>
#include <iostream>

class MyClass {
public:
    int a;
    double b;

    // 构造函数
    MyClass(int a, double b) : a(a), b(b) {
        std::cout << "Constructed MyClass(" << a << ", " << b << ")\n";
    }

    // 拷贝构造函数
    MyClass(const MyClass& other) : a(other.a), b(other.b) {
        std::cout << "Copy constructed MyClass(" << other.a << ", " << other.b << ")\n";
    }

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : a(other.a), b(other.b) {
        std::cout << "Move constructed MyClass(" << other.a << ", " << other.b << ")\n";
    }

    // 析构函数
    ~MyClass() {
        std::cout << "Destructed MyClass(" << a << ", " << b << ")\n";
    }
};

int main() {
    std::vector<MyClass> vec;

    std::vector<MyClass> vec1;
    std::cout << "Using push_back:\n";
    MyClass obj1(1, 2.0);
    vec.push_back(obj1);  // 使用 push_back 添加对象
    vec.push_back(MyClass(1, 1)); 
    // vec.push_back(1, 4);
    std::cout << "\nUsing emplace_back:\n";
    vec1.emplace_back(obj1);
    vec1.emplace_back(3, 4.0);  // 使用 emplace_back 直接构造对象
    vec1.emplace_back(MyClass(1, 3)); 
    
    return 0;
}
