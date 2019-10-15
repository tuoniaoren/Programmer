#include <iostream>
#include <stack>
using namespace std;

void sortStackByStack(stack<int> &MyStack){
    int cur;
    int tmp;
    int tmp2;
    stack<int> help;
    while (!MyStack.empty()){
        cur = MyStack.top();
        MyStack.pop();
        while (!help.empty() && cur > help.top()){
            tmp = help.top();
            MyStack.push(tmp);
            help.pop();
        }
        help.push(cur);
    }
    while (!help.empty()){
        MyStack.push(help.top());
        help.pop();
    }
}

int main(){
    int nums;
    int data;
    stack<int> MyStack;
    cin >> nums;
    for (int i=0; i<nums; i++){
        cin >> data;
        MyStack.push(data);
    }
    sortStackByStack(MyStack);
    while (!MyStack.empty()){
        cout << MyStack.top() << " ";
        MyStack.pop();
    }
}