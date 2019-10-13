//
// Created by qhp on 2019/10/12.
//
#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>
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
    PetEnterQueue(Pet a, long x){
        pet = a;
        count = x;
    }
    Pet getPet(){
        return pet;
    }
    long getCount(){
        return count;
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
    Dog pollDog();
    Cat pollCat();
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

Dog DogCatQueue::pollDog() {
    if (!dogQ.empty()){
        Pet tmpP = dogQ.front().getPet();
        Dog tmp;
        Pet *p = &tmp;   // 父类变子类
        *p = tmpP;
        dogQ.pop();
        return tmp;
    } else {
        throw runtime_error("Error, empty dog queue!");
    }
}

Cat DogCatQueue::pollCat() {
    if (!catQ.empty()){
        Pet tmpP = catQ.front().getPet();
        Cat tmp;
        Pet *p = &tmp;
        *p = tmpP;
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