#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int a;
    cin >> a;
    stack<int> stackData;
    stack<int> stackMin;
    
    for (int i=0; i<a; i++){
        string s;
        cin >> s;
        if (s=="push"){
            int data;
            cin >> data;
            stackData.push(data);
            if (stackMin.empty()){
                stackMin.push(data);
            } else if (data > stackMin.top()){
                stackMin.push(stackMin.top());
            } else{
                stackMin.push(data);
            }
        } else if (s=="pop"){
            stackData.pop();
            stackMin.pop();
        } else{
            cout << stackMin.top() << endl;
        }
    }
    return 0;
}