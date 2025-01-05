#include<sstream>
#include<iostream>
// Examples
void test(){
    std::stringstream iss("1 2 3"); // iss << "1 2 3";
    int a, b, c;
    iss >> a >> b >> c; // 1 2 3
    std::cout << a << ' ' << b << ' ' << c << std::endl;
    
    std::stringstream oss;
    oss << "Hello " << "World\n";
    std::string res = oss.str(); // getline(oss, res);
    std::cout << res << std::endl; // Hello World
}