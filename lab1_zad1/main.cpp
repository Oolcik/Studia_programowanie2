//Aleksandra Wnuk - programowanie 2 - labolatorium 1 - zadanie 1
//Proszę napisać program, który będzie pobierał od użytkownika n nazwisk i umieszczał je w tablicy o rozmiarze n,
//gdzie n to ustalona stała. Nazwiska mają być różnej długości, a po zakończeniu wypełniania tablicy nie mogą
//zajmować więcej miejsca niż liczba znaków w nich + 1.
//W jednym rozwiązaniu proszę skorzystać z klasy string, a w drugim z napisów w stylu języka C

#include <iostream>
#include <string>
#include <cstring>

//funkcja do wczytwywania tablicy Cstringów, zkaladam ze nazwisko nie ma wiecej niż 19 znaków
void readCString(char** database, int size){
    char surname[20];
    for(int i = 0 ; i < size ; i++){
        std::cin >> surname;
        database[i] = new char[strlen(surname) + 1];
        strcpy(database[i], surname);
    }
}

//funkcja do wczytywania do tablicy stringów
void readString( std::string* database, int size){
    for(int i = 0 ; i  < size ; i++){
        std::cin >> database[i];
    }
}

void strVer(){
    std::cout << "enter the number of surnames" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "enter surnames" << std::endl;
    std::string database[n];
    readString(database, n);
    std::cout << "your database:" << std::endl;
    for(int i = 0 ; i  < n ; i++){
        std::cout << database[i] << std::endl;
    }
}

void CStrVer(){
    std::cout << "enter the number of surnames" << std::endl;
    int n;
    std::cin >> n;
    std::cout << "enter surnames" << std::endl;
    char** database = new char* [n];
    readCString(database, n);
    std::cout << "your database:" << std::endl;
    for(int i = 0 ; i  < n ; i++){
        std::cout << database[i] << std::endl;
    }
    for(int i = 0 ; i < n ; i++)
            delete[] database[i];
    delete[] database;
}

int main() {
    std::cout << "-- surname database --" <<std::endl;
    std::cout << "enter '1' for string ver or '2' for Cstring ver, '0' to close" <<std::endl;
    int ver;
    while(true) {
        std::cin >> ver;
        if (ver == 1) {
            std::cout << "-- string version --" << std::endl;
            strVer();
            std::cout << "enter '0' to close" <<std::endl;
        } else if (ver == 2) {
            std::cout << "-- Cstring version --" << std::endl;
            CStrVer();
            std::cout << "enter '0' to close" <<std::endl;
        } else if (ver == 0){
            std::cout << "bye!" << std::endl;
            break;
        } else {
            std::cout << "wrong number, choose between 0, 1 and 2" << std::endl;
        }
    }
    return 0;
}