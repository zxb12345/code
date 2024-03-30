#include <iostream>
#include <string>

class Base
{
public:
    Base(const std::string &n = "")
    : name{n}
    {
    }

    Base(const Base &lhs)
    : name{lhs.name}
    {
        std::cout << "base copy configurator: " << name << std::endl;
    }

    Base(Base &&rhs) noexcept
    : name{std::move(rhs.name)}
    {

    }

    Base& operator=(const Base &lhs)
    {
        name = lhs.name;
        return *this;
    }

    Base& operator=(Base &&rhs) noexcept
    {
        name = std::move(rhs.name);
        return *this;
    }

    virtual ~Base() {};

private:
    std::string name;
};

class Derive : public Base
{
public:
    Derive(const std::string &n)
    : Base(n)
    {

    }

    Derive(const Derive &lhs)
    : Base(lhs)
    {

    }

    Derive(Derive &&rhs) noexcept
    : Base(rhs)
    {

    }

    Derive& operator=(const Derive &lhs)
    {
        this->Base::operator=(lhs);
        return *this;
    }

    Derive& operator=(Derive &&rhs)
    {
        Base::operator=(rhs);
        return *this;
    }

    virtual ~Derive()
    {

    }

};

int main()
{
    Derive temp("test_code");
    // Derive temp_copy(std::move(temp));

    Derive temp_copy_2{Derive("test_code_2")};
    std::cout << "test end." << std::endl;
    return 0;
}