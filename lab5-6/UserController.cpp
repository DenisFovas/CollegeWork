//
// Created by denis on 21.04.2017.
//

#include "UserController.h"

UserController::UserController(Repository<Dog> &repository) : repository { repository } {

}

//UserController::UserController(Repository<Dog> repository) : repository { repository } {
//    for (int i = 0; i < repository.getSize(); ++i) {
//        this->repository.add(repository.getElement(i));
//    }
//}


Repository<Dog> UserController::getAdoptionList(){
    return adoptionList;
}

UserController::~UserController() {

}

Repository<Dog> &UserController::getByBreedAnAge(std::string breed, int age) {
    Repository<Dog> repo;
    for (int i = 0; i < this->repository.getSize(); ++i) {
        if (this->repository.getElement(i).getBreed() == breed or breed == "-")
            if (this->repository.getElement(i).getAge()  < age)
                repo.add(this->repository.getElement(i));
    }
    return  repo;
}


void UserController::addToAdoption(Dog dog) {
	for (int i = 0; i < this->adoptionList.getSize(); i++) {
        Dog dogInRepository;
        dogInRepository = this->getAdoptionList().getElement(i);
		if (dog == dogInRepository)
				return;
	}
    this->adoptionList.add(dog);
}
