#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MyQueue{
public:
    void PushToPop(){
        int data;
        if (stackPop.empty()){
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
            cout << stackPop.top() << endl;
    }
private:
    stack<int> stackPush;
    stack<int> stackPop;
};

int main(){
    MyQueue x;
    int nums;
    cin >> nums;
    for (int i=0; i<nums; i++){
        string S;
        cin >> S;
        if (S == "add"){
            int data;
            cin >> data;
            x.Push(data);
        } else if (S == "poll"){
            x.Pop();
        } else{
            x.Top();
        }
    }
    return 0;
}