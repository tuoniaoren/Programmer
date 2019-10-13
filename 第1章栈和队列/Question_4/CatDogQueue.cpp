//
// Created by qhp on 2019/10/12.
//
#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>  //标准异常库
using namespace std;

class Pet{
public:
    Pet(string type){
        this->type = type;
    }
    Pet(){}
    string getPetType(){
        return this->type;
    }
private:
    string type;
};

class Dog: public Pet{
public:
    Dog(): Pet("dog"){}
};

class Cat: public Pet{
public:
    Cat(): Pet("cat"){}
};

class PetEnterQueue{
public:
    PetEnterQueue(const Pet& pet, long count){
        this->pet = pet;
        this->count = count;
    }
    Pet getPet(){
        return this->pet;
    }
    long getCount(){
        return this->count;
    }
    string getEnterPetType(){
        return this->pet.getPetType();
    }
private:
    Pet pet;
    long count;
};

class DogCatQueue{
public:
    DogCatQueue(){
        this->count = 0;
    }
    void add(Pet pet);
    Pet pollAll();
    Pet pollDog();
    Pet pollCat();
    bool isEmpty();
    bool isDogEmpty();
    bool isCatEmpty();
private:
    queue<PetEnterQueue> dogQ;
    queue<PetEnterQueue> catQ;
    long count;
};

void DogCatQueue::add(Pet pet) {
    if (pet.getPetType() == "dog")
        dogQ.push(PetEnterQueue(pet, this->count++));
    else if (pet.getPetType() == "cat")
        catQ.push(PetEnterQueue(pet, this->count++));
    else
        throw runtime_error("err, not dog or cat");
}

Pet DogCatQueue::pollAll() {
    if (!dogQ.empty() && !catQ.empty()){
        if (dogQ.front().getCount() < catQ.front().getCount()){
            Pet tmp;
            tmp = dogQ.front().getPet();
            dogQ.pop();
            return tmp;
        } else {
            Pet tmp;
            tmp = catQ.front().getPet();
            catQ.pop();
            return tmp;
        }
    } else if (!dogQ.empty()){
        Pet tmp;
        tmp = dogQ.front().getPet();
        dogQ.pop();
        return tmp;
    } else if (!catQ.empty()){
        Pet tmp;
        tmp = catQ.front().getPet();
        catQ.pop();
        return tmp;
    } else {
        throw runtime_error("Error, empty queue！");
    }
}

Pet DogCatQueue::pollDog() {
    if (!dogQ.empty()){
        Pet tmp = dogQ.front().getPet();
        dogQ.pop();
        return tmp;
    } else {
        throw runtime_error("Error, empty dog queue!");
    }
}

Pet DogCatQueue::pollCat() {
    if (!catQ.empty()){
        Pet tmp = catQ.front().getPet();
        catQ.pop();
        return tmp;
    } else {
        throw runtime_error("Error, empty cat queue!");
    }
}

bool DogCatQueue::isEmpty() {
    return dogQ.empty() && catQ.empty();
}

bool DogCatQueue::isDogEmpty() {
    return dogQ.empty();
}

bool DogCatQueue::isCatEmpty() {
    return catQ.empty();
}

int main(){
    DogCatQueue Animal;
    if (Animal.isEmpty())
        cout << "All queue is empty!" << endl;
    Animal.add(Dog());
    if (Animal.isDogEmpty())
        cout << "Dog queue is empty!" << endl;
    if (Animal.isCatEmpty())
        cout << "Cat queue is empty!" << endl;
}