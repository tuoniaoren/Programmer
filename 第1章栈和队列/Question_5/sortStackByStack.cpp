#include <iostream>
#include <stack>
using namespace std;

void sortStackByStack(stack<int> &MyStack){
    stack<int> help;
    int cur;
    int tmp;
    while (!MyStack.empty()){
        cur = MyStack.top();
        MyStack.pop();
        while (!help.empty() && cur > help.top()){
                tmp = help.top();
                help.pop();
                MyStack.push(tmp);
            }
        help.push(cur);
    }
    while (!help.empty()){
        int tmp2 = help.top();
        MyStack.push(tmp2);
        help.pop();
    }
}

int main(){
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(6);
    sortStackByStack(a);
    while (!a.empty()){
        cout << a.top() << endl;
        a.pop();
    }
}