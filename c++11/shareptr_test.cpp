/*
* Created by smtech on 15-10-23.
* shareptr test for c++11
*/


#include <iostream>
#include <memory>

class People {
private:
    int age;
public:
    People(int age):
            age(age)
    {
        std::cout<<"On construct People "<<age<<std::endl;
    }
    ~People(){
        std::cout<<"On People destroy. Age is "<<this->age<<std::endl;
    }
};

int main() {
    std::shared_ptr<People> ppl(new People(23));
    std::cout<<"Now reset ppl, point to People(24)"<<std::endl;
    ppl.reset(new People(24));
}
