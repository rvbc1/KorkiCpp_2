#include "object.h"
#include <fstream>

int Object::all_of_objects = 0;


//ZRZUT PAMIECI DO PLIKU
void Object::save(){
    std::string path = "object";
    path.append(std::to_string(id));
    path.append(".txt");

    std::ofstream fileOut(path);

    // Wykorzystanie this, czyli wskaznik na samego siebie
    fileOut.write((char *) this, sizeof(*this));
}

Object::Object(){
    id = all_of_objects;
    all_of_objects++;
}

Object::Object(int init_value){
    varible = init_value;

    id = all_of_objects;
    all_of_objects++;
}

Object::~Object(){
    save();
}

int Object::getVarible(){
    return varible;
}
