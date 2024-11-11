#include "list.h"

int main() {
    List list;


    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout << "List after push_back: ";
    list.show();

    
    list.push_front(5);
    list.push_front(1);
    cout << "List after push_front: ";
    list.show();

  
    list.clear();
    cout << "List after clear: ";
    list.show();

   
    list.push_back(100);
    list.push_back(200);
    List copyList = list;
    cout << "Original list: ";
    list.show();
    cout << "Copied list: ";
    copyList.show();

 
}
