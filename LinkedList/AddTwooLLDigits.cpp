//given two ll , digits are stored in reverse order and each their node contains a single digit
//add two linked list
//a->3->4->3
//b->5->6->4
//343+465=808
//r->8->0->8
// Note: given list is an singly linked list

#include <iostream>
#include <list>
using namespace std;
 /*
https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150
*/
list<int> addTwoLists(const list<int> &list1,const list<int> &list2){
    list<int> result;
    auto it1=list1.begin();
    auto it2=list2.begin();
    
    int sum=0;
    int carry=0;

    while(it1!=list1.end() || it2!=list2.end() ){
        int x = (it1 != list1.end()) ? *it1 : 0;
        int y = (it2 != list2.end()) ? *it2 : 0;
        
        int sum = x + y + carry;
        carry = sum / 10;

        result.push_back(sum % 10);

        if (it1 != list1.end()) {
            ++it1;
        }
        if (it2 != list2.end()) {
            ++it2;
        }
    }
    if (carry > 0) {
        result.push_back(carry);
    }
    return result;
}

int main() {
    list<int> list1 = {3, 4, 3};
    list<int> list2 = {5, 6, 4};
    list<int> result = addTwoLists(list1, list2);

    cout << "List 1: ";
    for (int num : list1) {
        cout << num << " ";
    }
    cout<<endl;

    cout << "List 2: ";
    for (int num : list2) {
        cout << num << " ";
    }
    cout<<endl;

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}
