#include <iostream>
#include <string>
#include <cstdio>
#include <bitset>

//sprawdz czy stringi rowne, sprawdz czy rowne bez rozroznienia mala/wielka litera
void cw1() {
    std::string str = "FujfujBleble";
    std::string str2;
    std::cin >> str2;

    std::cout << str.compare(str2) << std::endl;

    //wielkosc liter bez znaczenia:
    int size = str.length();
    for(int i = 0 ; i < size ; i++)
        str[i] = tolower(str[i]);
    size = str2.length();
    for(int i = 0 ; i < size ; i++)
        str2[i] = tolower(str2[i]);
    std::cout << str.compare(str2) << std::endl;
}

//scnaf z zabezpieczeniem
void cw2(){
    char napis[30];
    if(scanf("%[1-4]s", napis))
        printf("%s", napis);
}

//pobierz linie z zabepieczeniem
void cw3(){
    char napis[30];
    if(fgets(napis, 30, stdin))
        printf("%s", napis);
}

//pobieraj znaki z wejscia do kropki
void cw4(){
    char c;
    do{
        c = getchar();
        std::cout << c;
    }while(c != '.');
}

//liczba zer w bitset
void cw5(){
    std::bitset<8> b("10101110");
    std::cout << b.size() - b.count() << std::endl;
    std::cout << b.flip().count() << std::endl;
}
int main() {

    //cw1();
    //cw2();
    //cw3();
    //cw4();
    //cw5();


    return 0;
}