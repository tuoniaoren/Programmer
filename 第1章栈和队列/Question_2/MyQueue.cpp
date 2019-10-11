//
// Created by qhp on 2019/10/11.
//
#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
public:
    void PushToPop(){
        if (stackPop.empty()){
            int data;
            while (!stackPush.empty()){
                data = stackPush.top();
                stackPop.push(data);
                stackPush.pop();
            }
        }
    }
    void Push(int newData){
        stackPush.push(newData);
    }
    void Pop(){
        PushToPop();
        stackPop.pop();
    }
    void Top(){
        PushToPop();
        cout<< stackPop.top() << endl;
    }
private:
    stack<int> stackPush;
    stack<int> stackPop;
};