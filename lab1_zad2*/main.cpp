//Aleksandra Wnuk - labolatorium 1 - zadanie 2
//Proszę zaimplementować dwie dowolne struktury (analogicznie do przykładu z zajęć). Następnie użyć wskaźnika
//w jednej jako pole umożliwiające odwołanie się do obiektów drugiej. Dalej stworzyć klasyczny wskaźnik do obiektu
//drugiej klasy i podpiąć go do obiektów pierwszej.
//*Proszę spróbować skorzystać ze sprytnych wskaźników zastępujących klasyczne wskaźniki.

//wersja ze sprytnymi wskaźniakami

#include <iostream>
#include <string>
#include <memory>

struct Order{
    std::string tea = "black";
    std::string sweetener = "no";
    std::string addMilk = "no";
    float price = 9.99;
};

struct TeahouseCustomer{
    std::string name = "Ola";
    bool discount = false;
    std::shared_ptr<Order> order;
};

void show(TeahouseCustomer* customer){
    std::cout << "--------- ORDER ---------" << std::endl;
    std::cout << "> customer name: .. " << customer->name << std::endl;
    std::cout << "> discount: ....... " << customer->discount << std::endl;
    std::cout << "> tea: ............ " << customer->order->tea << std::endl;
    std::cout << "> sweetener: ...... " << customer->order->sweetener << std::endl;
    std::cout << "> milk: ........... " << customer->order->addMilk  <<  std::endl;
    std::cout << "> price: .......... " << customer->order->price << std::endl;
    std::cout << std::endl;
}

int main() {

    std::shared_ptr<Order> blackWithMilk(new Order);
    blackWithMilk->addMilk = "yes";
    blackWithMilk->price += 1.99;

    std::shared_ptr<Order> white(new Order);
    white->tea = "white";
    white->price = 13.99;

    std::shared_ptr<Order> greenWithHoney(new Order);
    greenWithHoney->tea = "green";
    greenWithHoney->sweetener = "honey";
    greenWithHoney->price += 3.98;

    TeahouseCustomer * customer1 = new TeahouseCustomer;
    customer1->discount = true;
    customer1->order = white;

    TeahouseCustomer * customer2 = new TeahouseCustomer;
    customer2->name = "Ala";
    customer2->order = blackWithMilk;

    TeahouseCustomer * customer3 = new TeahouseCustomer;
    customer3->name = "Ela";
    customer3->discount = true;
    customer3->order = white;

    TeahouseCustomer * customer4 = new TeahouseCustomer;
    customer4->name = "Ula";
    customer4->order = greenWithHoney;

    TeahouseCustomer * customer5 = new TeahouseCustomer;
    customer5->name = "Iza";
    customer5->discount = true;
    customer5->order = greenWithHoney;

    TeahouseCustomer * customer6 = new TeahouseCustomer;
    customer6->name = "Ida";
    customer6->order = white;

    TeahouseCustomer * customer7 = new TeahouseCustomer;
    customer7->name = "Iga";
    customer7->discount = true;
    customer7->order = greenWithHoney;

    show(customer1);
    show(customer2);
    show(customer3);
    show(customer4);
    show(customer5);
    show(customer6);
    show(customer7);

    delete customer7;
    delete customer6;
    delete customer5;
    delete customer4;
    delete customer3;
    delete customer2;
    delete customer1;

    return 0;
}

