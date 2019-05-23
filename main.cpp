#include <iostream>
#include <vector>
#include "object.h"
#include <fstream>


#define AMOUNT_OF_OBJECTS 10

int main(){
    std::vector<Object *> objects_vector;


    //WCZYTYWANIE PAMIECI TYLKO JEZELI PLIKI ISTANIJA [NAJPIERW URUCHOMIC, PLIKI POWINNY SIE ZAPISAC]

    /*
    for(int i = 0; i < AMOUNT_OF_OBJECTS; i++){
        Object *read_object = new Object();

        std::string path = "object";
        path.append(std::to_string(i));
        path.append(".txt");

        std::ifstream fileIn(path, std::ios::in);
        fileIn.read((char *) read_object, sizeof(*read_object));
        objects_vector.push_back(read_object);
        fileIn.close();
    }
    */

    //GENEROWANIE LOSOWYCH OBIEKTOW
    for(int i = 0; i < AMOUNT_OF_OBJECTS; i++){
        objects_vector.push_back(new Object(rand() % 3));
    }


    //WYSWIETLENIE CALEGO KONTENERA objects_vector
    for(int i = 0; i < objects_vector.size(); i++){
        std::cout << "Object " << i << " - " << objects_vector[i]->getVarible() << std::endl;
    }


    //USUWANIE

    //niestety nalezy wywolac *.begin() + i lub *.end() - i aby vector wiedzial gdzie w pamieci usuwac dane
    //    objects_vector.erase(objects_vector.end() - 3); //USUWANIE 3 ELEMENTU OD KONCA

    //    objects_vector.erase(objects_vector.begin() + 2); //USUWANIE 2 ELEMENTU

    //    objects_vector.erase(objects_vector.begin() + 2, objects_vector.begin() + 5); //USUWANIE OD 2 DO 5 ELEMENTU

    //    objects_vector.erase(objects_vector.begin() + 2, objects_vector.end()); //USUWANIE OD 2 ELEMENTU DO KONCA


    //WAZNE NALEZY PAMIEC ZE objects_vector.erase USUWA TYLKO ELEMENTY ZAWARTE W KONTENERZE - CZYLI W TYM PRZYPADKU WSKAZNIKI NA OBIEKTY
    //OZNACZA TO ZE USUNIEMY SAM ADRES A NIE OBIEKT POD NIM, WIEC NAJPIERW NALEZY WYYWALAC delete objects_vector[0] a potem objects_vector.erase(objects.begin())
    //ABY USUNAC PIERWSZY ELEMENT ITP



    //ZRZUT PAMIECI DO PLIKU // ZAIPLEMENTOWANE W OBJECT.CPP ABY W DESTRUKTORZE ZAPISYWAL OBIEKT CALY ALE NIE WYKORZYSTANE PRZEZE MNIE

    for(int i = 0; i < objects_vector.size(); i++){
        std::string path = "object";
        path.append(std::to_string(i));
        path.append(".txt");

        std::ofstream fileOut(path);
        /////******************************************///////////
        // objects_vector[i] - adres poczatkowy pamieci zgrywanej - wskaznik na obiekt
        // (char *) - rzutowanie wskaznika na wskaźnik liczby 8 bitowa (najmniejsza komóra pamieci w komputerze jest 8 bitowa)
        // sizeof(*objects_vector[i]) - ilosc pamieci do zgrania - rozmiar obiektu [poprzez funkcje sizeof]
        // *objects_vector[i] z * bo intersuje nas rozmiar wyłuskanego obiektu a nie rozmiar wskaźnika;
        fileOut.write((char *) objects_vector[i], sizeof(*objects_vector[i]));
    }

    return 0;
}

