#include <string>
#include <iostream>
#include <tuple>

class Person
{
public:
    Person(std::string a_name, double m, size_t a_age);

// private:

    std::string m_name;
    double m_mass;
    size_t m_age;
};

Person::Person(std::string a_name, double m, size_t a_age)
: m_name(a_name)
, m_mass(m)
, m_age(a_age)
{
}

bool operator==(Person const& lhs, Person const& rhs) noexcept
{
    return std::make_tuple(lhs.m_name, lhs.m_mass, lhs.m_age) == std::make_tuple(rhs.m_name, rhs.m_mass, rhs.m_age);
}

bool operator!=(Person const& lhs, Person const& rhs) noexcept
{
    return !(lhs == rhs);
}

bool operator<(Person const& lhs, Person const& rhs) noexcept
{
    return std::make_tuple(lhs.m_name, lhs.m_mass, lhs.m_age) < std::make_tuple(rhs.m_name, rhs.m_mass, rhs.m_age);
    // if( lhs.m_name < rhs.m_name ){
    //     return true;
    // }

    // if( lhs.m_name > rhs.m_name ){
    //     return false;
    // }

    // return lhs.m_age < rhs.m_age;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "{ " << p.m_name << ", " << p.m_mass << ", " << p.m_age << "}\n";
    return os;
}

struct PersonHasher
{
    size_t operator()(Person const& p) const
    {
        // std::string s1;
        // std::string s2{};
        // std::string s3();
        // std::string s4("alex");
        // std::string s5{"alex"};


        std::hash<std::string>  shs;
        auto h1 = shs(p.m_name);
        auto h2 = std::hash<std::size_t>{}(p.m_age);

        // char c[8];
        // memcpy(c, &p.m_mass);

        // std::hash<std::double> hd{};
        // auto h3 = hd(p.m_mass);

        return h1 ^ (h2 << 13);
    }
};


namespace std {

template<>
class hash<Person>
{
public:
    size_t operator()(const Person& key) const
    {
        return hash<std::string>()(key.m_name);
    }
};

}
