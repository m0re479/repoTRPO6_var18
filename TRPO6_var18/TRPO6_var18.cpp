//Вариант 18 (10 баллов) Разработайте следующие иерархии классов : «Обувь»(«Кроссовки»,
//    «Туфли»), «Одежда»(«Спортивный костюм», «Смокинг»).Кроссовки и спортивный костюм,
//    очевидно, относятся к категории спортивной одежды, а смокинг и туфли — к категории
//    вечерних нарядов.При помощи паттерна Abstract Factory реализуйте указанную ситуацию.
//    
// Доп.задания :
//(5 баллов) Что нужно видоизменить в программе, чтобы добавить туда категорию
//    ежедневной одежды ? Внесите изменения в код, продемонстрируйте применение паттерна.
// 
//(5 баллов) Что нужно видоизменить в программе, если надо добавить новый продукт,
//    например, сумки ? Внесите изменения в код, продемонстрируйте применение паттерна.


#include <iostream>
using namespace std;

class ClothingItems {

};

class Shoes : public ClothingItems {
public:
    virtual void putOn() = 0;
};

class Sneakers : public Shoes {
    std::string brand;
    int size;
public:
    void putOn() {
        std::cout << "Обуть кроссовки " << this->brand << std::endl;
    }
};

class Slippers : Shoes {
    std::string brand;
    int size;
public:
    void putOn() {
        std::cout << "Обуть туфли " << this->brand << std::endl;
    }
};

class Clothes : public ClothingItems {
public:
    virtual void getDressed() = 0;
};

class Tracksuit : Clothes {
    std::string brand;
public:
    void getDressed() {
        std::cout << "Надеть спортивный костюм от " << this->brand << std::endl;
    }
};

class Tuxedo : Clothes {
    std::string brand;
public:
    void getDressed() {
        std::cout << "Надеть смокинг от " << this->brand << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");


    return 0;
}