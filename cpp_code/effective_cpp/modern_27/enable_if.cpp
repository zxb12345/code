#include <string>
#include <iostream>

class Person
{
public:
    template<typename T, typename = typename std::enable_if<condition>::type>
    explicit Persion(T&& n);

private:
    std::string name;
}

int main()
{
    return 0;
}