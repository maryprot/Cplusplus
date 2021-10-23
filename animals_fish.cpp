#include <iostream>

class Animal {
public:
        int legs_num;
        void make_a_sound();
};

void Animal::make_a_sound() {
       std::cout << "some abstract sound" << std::endl;
}


class Fish : public Animal {
public:
    
    Fish(int n) {
        legs_num = n;
    }
    
    std::string colour;
    void make_a_sound();
};

void Fish::make_a_sound() {
    std::cout << "буль-буль" << std::endl;
}

class Dog : public Animal {
public:
        unsigned int width;
        unsigned int height;
        void make_a_sound();
};

void Dog::make_a_sound() {
        std::cout << "woof-woof!" << std::endl;
}

int main()
{
        Animal anima;
        Dog rex;
        Fish Gera(0);
        Gera.make_a_sound();

        Animal *pRex = &rex;
        Animal& rRex = rex;
        std::cout << Gera.legs_num << std::endl;
        anima.make_a_sound();
        rex.make_a_sound();
        pRex->make_a_sound();
        rRex.make_a_sound();
        return 0;
}
