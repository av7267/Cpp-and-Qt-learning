#include <iostream>
#include <utility>
using namespace std;
#include "Arnavptr.hpp"


class Node
{
    public:
    int key;
    string value;
    Arnavptr<Node>next; // we create a unique pointer because we dont need to manually free up the space 
};


class Map
{
    private:
    Arnavptr<Node>head;   //unique_ptr is a class template,we are creating an object of that class(head).

    public:
    Map()
    {
        head = nullptr;
    }

    Node* Insert(int key,string value)
    {
        Node* curr = head.Get( );
        

       while(curr != nullptr)
       {
        if(key == curr -> key)
        {
            cout << " Key exists" << "\n";
            return curr;
        }
        curr = curr->next.Get();
       }

        Arnavptr<Node> temp(new Node);
        temp->key = key;
        temp->value = value;
        temp->next = std::move(head);
        head = std::move(temp);

    }
    

    // void Add_Element_End(int key,string value)
    // {
    //     Node *temp = new Node;
    //     temp->key = key;
    //     temp->value = value;
    //     temp->next = nullptr;

    //     if(head == nullptr)
    //     {
    //         head = temp;
    //         return;
    //     }

    //     Node *curr = head;
    //     while(curr->next != nullptr)
    //     {
    //         curr = curr->next;
    //     }
    //     curr->next = temp;
    // }


    void Remove(int key) //remove the particular element from the map using linked list logic based on the key value
    {
        Node *curr = head.Get();
        Node* prev = nullptr;
        
        while(curr != nullptr)
        {
            if(curr -> key == key)
            {
                if(prev == nullptr)
                {
                    head = std::move(curr->next);
                }
                else{
                    prev->next = std::move(curr->next);
                }
                return;
            }
            prev = curr;
            curr = curr -> next.Get();
        }
    }

    void Search(int key)
    {
        Node* curr = head.Get();

        while(curr != nullptr)
        {
            if(curr->key == key)
            {
                cout << curr->key << " " << curr->value << endl;
                return;
            }
            curr = curr->next.Get();
        }

        cout << "Element not found" << endl;
    }

    int Size()
    {
        int count = 0;
        Node *curr = head.Get();

        while(curr != nullptr)
        {
            count++;
            curr = curr->next.Get();
        }
        return count;
    }

    void Clear()
    {
        head = nullptr;
    }

    
};




int main()
{
    Map mp;

    mp.Insert(20,"Arnav");
    mp.Insert(20,"John"); //will not get inserted
    // mp.Add_Element_End(40,"Alex");

    mp.Search(20);

    mp.Remove(30);

    cout << "Size: " << mp.Size() << endl;

    return 0;
}