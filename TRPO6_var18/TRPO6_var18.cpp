﻿//Вариант 18 (10 баллов) Разработайте следующие иерархии классов : «Обувь»(«Кроссовки»,
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
#include <vector>
using namespace std;

class ClothingItems {
public:
    ClothingItems() {}
    virtual ~ClothingItems() {}
    virtual void print() = 0;
};

class Shoes : public ClothingItems {
public:
    ~Shoes() {}
    virtual void putOn() = 0;
};

class Sneakers : public Shoes {
    std::string brand;

public:
    Sneakers(std::string brand_) : brand(brand_) {}
    ~Sneakers() {}

    void putOn() {
        std::cout << "Обуть кроссовки " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Кроссовки " << this->brand << std::endl;
    }
};

class Slippers : public Shoes {
    std::string brand;

public:
    Slippers(std::string brand_) : brand(brand_) {}
    ~Slippers() {}

    void putOn() {
        std::cout << "Обуть туфли " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Туфли " << this->brand << std::endl;
    }
};

class Clothes : public ClothingItems {
public:
    ~Clothes() {}
    virtual void getDressed() = 0;
};

class Tracksuit : public Clothes {
    std::string brand;
public:
    Tracksuit(std::string brand_) : brand(brand_) {}
    ~Tracksuit() {}

    void getDressed() {
        std::cout << "Надеть спортивный костюм от " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Спортивный костюм " << this->brand << std::endl;
    }
};

class Tuxedo : public Clothes {
    std::string brand;
public:
    Tuxedo(std::string brand_) : brand(brand_) {}
    ~Tuxedo() {}

    void getDressed() {
        std::cout << "Надеть смокинг от " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Смокинг " << this->brand << std::endl;
    }
};

//Создадим абстрактную фабрику по созданию элементов одежды
class AbstractFactory {
public:
    virtual Shoes* createShoes(std::string br) = 0;
    virtual Clothes* createClothes(std::string br) = 0;
};

//Создадим конкретные фабрики для спортивной и вечерней одежды
class SportswearFactory : public AbstractFactory {
public:
    virtual Shoes* createShoes(std::string br) {
        return new Sneakers(br);
    }
    virtual Clothes* createClothes(std::string br) {
        return new Tracksuit(br);
    }
};

class EveningWearFactory : public AbstractFactory {
public:
    virtual Shoes* createShoes(std::string br) {
        return new Slippers(br);
    }
    virtual Clothes* createClothes(std::string br) {
        return new Tuxedo(br);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<ClothingItems*> clothingItems;

    AbstractFactory* factory = new SportswearFactory();//фабрика для спортивных вещей
    clothingItems.push_back(factory->createShoes("Adidas"));
    clothingItems.push_back(factory->createClothes("Calvin Klein"));

    factory = new EveningWearFactory();//фабрика для вечерних вещей
    clothingItems.push_back(factory->createShoes("Ecco"));
    clothingItems.push_back(factory->createClothes("N°21"));

    for (ClothingItems* cloth : clothingItems) {
        cloth->print();
    }

    return 0;
}