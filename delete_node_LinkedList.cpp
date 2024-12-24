
#include <iostream>
#include <unordered_map>
#include <list>
#include <cstdio>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };





//function to delete a node of a specific value from the list
ListNode* List_Deleteval( ListNode* head, int delval)
{
    ListNode* temp = head;
    
    cout << delval<<" \n";

    //DELETE HEAD IF VALUE MATCH!!
    //DELETE HEAD IF VALUE MATCH!!
    //DELETE HEAD IF VALUE MATCH!!
    //DELETE HEAD IF VALUE MATCH!!

    if (temp != nullptr && head->val == delval)
    {
        head = temp->next;
        delete temp;
        cout << "**\n";
        return head;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;



// LOOK FOR SUCCESSIVE MATCHES AND DELETE NODE IF NECESSARY
// LOOK FOR SUCCESSIVE MATCHES AND DELETE NODE IF NECESSARY
// LOOK FOR SUCCESSIVE MATCHES AND DELETE NODE IF NECESSARY
// LOOK FOR SUCCESSIVE MATCHES AND DELETE NODE IF NECESSARY


      while (current != nullptr) {
        if (current->val == delval) {
            // Node with the given value found; unlink it from the list
            // if (prev != nullptr)
            //     {
                prev->next = current->next;
            //   } else {
            //     // If prev is null, we're at the head; update head
            //     head = current->next;
            // }
            delete current;      // Free the memory of the deleted node
            current = prev->next; // Move to the next node
        } else {
            // Move both pointers forward if no deletion occurs
            prev = current;
            current = current->next;
        }
    }
    cout << "^^";
    return head;
}



void List_addnode(ListNode* head, int val)
{

ListNode* prev = nullptr;
 
    while(head != nullptr)
    {
        prev = head;
        head = head->next;
    }

 
    ListNode * newnode = new ListNode(val);
    newnode->val = val;
    newnode->next = nullptr;
 

    prev->next = newnode;
 

cout << "insert node " << val <<"\n";
}


main()
{

     ListNode * list = new ListNode(1);


List_addnode(list, 2);
List_addnode(list, 3);
List_addnode(list, 4);
List_addnode(list, 5);
List_addnode(list, 6);
List_addnode(list, 7);

List_Deleteval( list, 4);
List_Deleteval( list, 5);
List_Deleteval( list, 5);


cout <<" list \n";
while(list!= nullptr)
{
    cout << list->val <<"\n";
    list = list->next;
}

}
