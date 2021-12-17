#include <iostream>

enum class animalType{
    dog,
    cat,
    none
};
class Animal{
protected:
    std::string name;
    animalType type;
public:
    Animal(std::string inName) : name(inName){
        type = animalType::none;
    }
    virtual std::string Voice(Animal *guest){
        return "Animal";
    }
    animalType GetType(){
        return type;
    }
};

class Dog :public Animal{

public:
    Dog(std::string inName) : Animal(inName){
        type = animalType::dog;
    }
    virtual std::string Voice(Animal *guest){
        if(guest->GetType() == this->type){
            return "Woof";
        }
        else return "Bark";
    }
};
class Cat :public Animal{

public:
    Cat(std::string inName) : Animal(inName){
        type = animalType::cat;
    }
    virtual std::string Voice(Animal *guest){
        if(guest->GetType() == this->type){
            return "Purr";
        }
        else return "Meow";
    }
};

void meeting(Animal* a, Animal* b){
    std::cout << a->Voice(b) << ' ' << b->Voice(a) << std::endl;
}
int main() {
    Animal* a = new Cat("Murzic");
    Animal* b = new Dog("Sharic");
    meeting(a, b);
    meeting(b, a);
    meeting(a, a);
    meeting(b, b);
    return 0;
}
