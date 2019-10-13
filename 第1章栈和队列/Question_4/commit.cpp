#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Animal{
public:
    Animal(string type){
        this->type = type;
    }
    Animal(){}
    string getType(){
        return type;
    }
private:
    string type;
};

class AnimalQueue{
public:
    AnimalQueue(Animal a, long x, long y){
        pet = a;
        count1 = x;
        count2 = y;
    }
    long getCount1(){
        return count1;
    }
    long getCount2(){
        return count2;
    }
private:
    Animal pet;
    long count1;
    long count2; // time
};

class DogCatQueue{
public:
    DogCatQueue(){
        this->count = 0;
    }
    void add(Animal pet, long x){
        if (pet.getType() == "dog"){
            dogQ.push(AnimalQueue(pet, x, this->count++));
        } else {
            catQ.push(AnimalQueue(pet, x, this->count++));
        }
    }
    void pollAll(){
        while (!dogQ.empty() && !catQ.empty()){
            if (dogQ.front().getCount2() < catQ.front().getCount2()){
                cout << "dog" << " " << dogQ.front().getCount1() << endl;
                dogQ.pop();
            } else {
                cout << "cat" << " " << catQ.front().getCount1() << endl;
                catQ.pop();
            }
        }
        while (!dogQ.empty()){
            cout << "dog" << " " << dogQ.front().getCount1() << endl;
            dogQ.pop();
        }
        while (!catQ.empty()){
            cout << "cat" << " " << catQ.front().getCount1() << endl;
            catQ.pop();
        }
    }
    
    void pollDog(){
        while (!dogQ.empty()){
            cout << "dog" << " " << dogQ.front().getCount1() << endl;
            dogQ.pop();
        }
    }
    
    void pollCat(){
        while (!catQ.empty()){
            cout << "cat" << " " << catQ.front().getCount1() << endl;
            catQ.pop();
        }
    }
    
    void isEmpty(){
        if (dogQ.empty() && catQ.empty()){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    void isDogEmpty(){
        if (dogQ.empty()){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    void isCatEmpty(){
        if (catQ.empty()){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
private:
    queue<AnimalQueue> dogQ;
    queue<AnimalQueue> catQ;
    long count;
};

int main(){
    int nums;
    cin >> nums;
    DogCatQueue MyQueue;
    
    for (int i=0; i<nums; i++){
        string s;
        cin >> s;
        if (s=="add"){
            string type;
            long id;
            cin >> type >> id;
            Animal x(type);
            MyQueue.add(x, id);
        } else if (s=="pollAll"){
            MyQueue.pollAll();
        } else if (s=="pollDog"){
            MyQueue.pollDog();
        } else if (s=="pollCat"){
            MyQueue.pollCat();
        } else if (s=="isEmpty"){
            MyQueue.isEmpty();
        } else if (s=="isDogEmpty"){
            MyQueue.isDogEmpty();
        } else {
            MyQueue.isCatEmpty();
        } 
    }
    return 0;
}