//
// Created by qhp on 2019/10/12.
//
#include <iostream>
#include <stack>
using namespace std;

// 将栈底元素取出来，并删除。栈内元素相对位置保持不变
int getAndRemoveLastElement(stack<int> &stack1){
    int result = stack1.top();
    stack1.pop();
    if (stack1.empty()){
        return result;
    } else{
        int last = getAndRemoveLastElement(stack1);
        stack1.push(result);
        return last;
    }
}

// 递归取栈底元素
void reverse(stack<int> &stack1){
    if (stack1.empty()){
        return;
    }
    int i = getAndRemoveLastElement(stack1);
    reverse(stack1);
    stack1.push(i);
}

int main(){
    stack<int> MyStack;
    MyStack.push(1);
    MyStack.push(2);
    MyStack.push(3);
    cout << MyStack.top() << endl;
    reverse(MyStack);
    cout << MyStack.top() << endl;
}
