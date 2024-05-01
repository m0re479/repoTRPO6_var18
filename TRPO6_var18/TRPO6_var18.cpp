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

//Для демонстрации работы программы добавим ещё один вариант одежды - летний костюм
class SummerSuit : public Clothes {
    std::string brand;
public:
    SummerSuit(std::string brand_) : brand(brand_) {}
    ~SummerSuit() {}
    
    void getDressed() {
        std::cout << "Надеть летний костюм от " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Летний костюм " << this->brand << std::endl;
    }
};


//Для добавления нового продукта "Сумки" необхлдимо создать соответствующую иерархию классов,
//а также добавить в абстрактную фабрику AbstractFactory новый виртуальный метод по созданию 
//сумок и реализовать его во всех конкретных фабриках

class Bag { //Сумка
public:
    ~Bag() {}
    virtual void toClose() = 0;
    virtual void print() = 0;
};

class Clutch : public Bag { //Клатч
    std::string brand;

public:
    Clutch(std::string brand_) : brand(brand_) {}
    ~Clutch() {}

    void toClose() {
        std::cout << "Закрыть клатч " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Клатч " << this->brand << std::endl;
    }
};

class Backpack : public Bag { //Рюкзак
    std::string brand;

public:
    Backpack(std::string brand_) : brand(brand_) {}
    ~Backpack() {}

    void toClose() {
        std::cout << "Закрыть рюкзак " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Рюкзак " << this->brand << std::endl;
    }
};

class Briefcase : public Bag { //Дипломат
    std::string brand;

public:
    Briefcase(std::string brand_) : brand(brand_) {}
    ~Briefcase() {}

    void toClose() {
        std::cout << "Закрыть дипломат " << this->brand << std::endl;
    }

    void print() {
        std::cout << "Дипломат " << this->brand << std::endl;
    }
};

//Создадим абстрактную фабрику по созданию элементов одежды
class AbstractFactory {
public:
    virtual Shoes* createShoes(std::string br) = 0;
    virtual Clothes* createClothes(std::string br) = 0;

    virtual Bag* createBag(std::string br) = 0;
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

    virtual Bag* createBag(std::string br) {
        return new Backpack(br);
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

    virtual Bag* createBag(std::string br) {
        return new Briefcase(br);
    }
};

//Новая фабрика для категории "Ежедневная одежда"
class DailyClothesFactory : public AbstractFactory {
    virtual Shoes* createShoes(std::string br) {
        return new Sneakers(br);
    }
    virtual Clothes* createClothes(std::string br) {
        return new SummerSuit(br);
    }

    virtual Bag* createBag(std::string br) {
        return new Clutch(br);
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

    /*for (ClothingItems* cloth : clothingItems) {
        cloth->print();
    }
    std::cout << std::endl;*/

    //Для добавления одной новой категории вещей достаточно добавить одну конкретную фабрику
    //Пример использования:
    factory = new DailyClothesFactory();//фабрика для ежедневных вещей
    clothingItems.push_back(factory->createShoes("Ecco"));
    clothingItems.push_back(factory->createClothes("Calvin Klein"));
    /*for (ClothingItems* cloth : clothingItems) {
        cloth->print();
    }*/

    //Пример работы программы с новым продуктом "Сумки"
    std::vector<Bag*> bagItems;
    factory = new SportswearFactory();//фабрика для спортивных вещей
    bagItems.push_back(factory->createBag("Hugo"));
    factory = new EveningWearFactory();//фабрика для вечерних вещей
    bagItems.push_back(factory->createBag("Lauren Ralph Lauren")); 
    factory = new DailyClothesFactory();//фабрика для ежедневных вещей
    bagItems.push_back(factory->createBag("Coccinelle"));
    for (Bag* bag : bagItems) {
        bag->print();
    }

    return 0;
}