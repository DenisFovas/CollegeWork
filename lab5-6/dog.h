//
// Created by denis on 03.04.2017.
//

#ifndef LAB5_6_DOG_H
#define LAB5_6_DOG_H

#include <string>

class Dog {
private:
    std::string breed;
    std::string name;
    std::string photo;
    int age;
    // TODO: Add a photograph
public:
    Dog(std::string, std::string, std::string, int);
    Dog();
    ~Dog();
    std::string getBreed() { return breed; };
    std::string getName() { return name; };
    std::string getPhto() { return photo; };
    int getAge() { return age; };
    void setBreed(std::string breed) { this->breed = breed; };
    void setName(std::string name) { this->name = name; };
    void setPhoto(std::string photo) { this->photo = photo; };
    void setAge(int age) { this->age = age; };
    void openPhoto();

};
#endif //LAB5_6_DOG_H
