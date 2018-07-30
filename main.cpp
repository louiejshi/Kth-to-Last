//
//  main.cpp
//  ReturnKthToLast
//
//  Created by Louie Shi on 7/26/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode* kthToLast(ListNode* ln, int k)
{
    ListNode* p = ln;
    ListNode* q = ln;
    
    for(int i = 1; i < k; i++)
    {
        q = q->getNext();
    }

    if(!q)
    {
        cout << "Invalid value of k!" << endl;
        return NULL;
    }
    
   // cout << "Initial P value: " << p->getData() << endl;
   // cout << "Initial Q value: " << q->getData() << endl;
    
    while(q->getNext() != NULL)
    {
        p = p->getNext();
        q = q->getNext();
    }
    
   //cout << "Final P value: " << p->getData() << endl;
   //cout << "Final Q value: " << q->getData() << endl;
    
    return p;
}


int main(int argc, const char * argv[])
{
    LinkedList* l1 = new LinkedList();
    int validKVal = 4;
    int inValidKVal = 7;
    ListNode* ln;
    
    ListNode* ln1 = new ListNode(1);
    ListNode* ln2 = new ListNode(2);
    ListNode* ln3 = new ListNode(3);
    ListNode* ln4 = new ListNode(4);
    ListNode* ln5 = new ListNode(5);
    ListNode* ln6 = new ListNode(6);
    
    l1->insertEnd(ln1);
    l1->insertEnd(ln2);
    l1->insertEnd(ln3);
    l1->insertEnd(ln4);
    l1->insertEnd(ln5);
    l1->insertEnd(ln6);
    
    l1->print();
    
    cout << endl;
    cout << "Valid K value: " << endl;
    ln = kthToLast(l1->head, validKVal);
    cout << ln->getData() << endl;
    cout << endl;
    
    cout << "Invalid K value: " << endl;
    kthToLast(l1->head, inValidKVal);
    
    return 0;
}
