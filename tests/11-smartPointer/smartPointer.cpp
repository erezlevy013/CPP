#include <iostream>
#include <memory>
#include <vector>
#include <string>


std::string longestString(std::vector<std::unique_ptr<std::string>> const& a_vec)
 {
    std::string longStr;
    for(auto& elm : a_vec){
        if(elm->length() > longStr.length()){
            longStr = *elm;
        }
    }
    return longStr;
 }


int main()
{
    std::vector<std::unique_ptr<std::string>> vec;
    vec.push_back(std::make_unique<std::string>("Erez"));
    vec.push_back(std::make_unique<std::string>("Levy"));
    vec.push_back(std::make_unique<std::string>("Talia Emma Roza Perez"));
    std::cout<<longestString(vec)<<std::endl;

    return 0;
}
