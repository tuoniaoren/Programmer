//
// Created by qhp on 2019/10/11.
// 思路2
//
#include <iostream>
#include <stack>
using namespace std;

class MyStack1{
public:
    void Push(int newData){
        stackData.push(newData);
        if (stackMin.empty()){
            stackMin.push(newData);
        } else if(newData <= stackMin.top()){
            stackMin.push(newData);
        }
    }
    void Pop(){
        if (stackData.top() == stackMin.top()){
            stackMin.pop();
        }
        stackData.pop();
    }
    int getMin(){
        if (stackMin.empty()){
            cout << "this stack is empty" << endl;
            return -1;
        }
        return stackMin.top();
    }
private:
    stack<int> stackData;
    stack<int> stackMin;
};

int main(){
    MyStack1 s;
    int minNum;
    s.Push(4);
    s.Push(2);
    s.Push(3);
    s.Push(1);
    minNum = s.getMin();
    cout << "此时最小值： " << minNum << endl;
    s.Pop();
    minNum = s.getMin();
    cout << "pop之后的最小值： " << minNum << endl;
    return 0;
}
