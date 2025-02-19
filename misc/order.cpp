#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


struct Order
{
    int id;       // Order ID
    string name;  // Product name
    int quantity; // Product quantity
    Order *next;  // Pointer to the next node
};
map<int, Order*> morder;
void printOrders(Order *head)
{
    if (head == nullptr)
    { // If the list is empty
        cout << "No orders available!" << endl;
        return;
    }

    cout << "Order list:" << endl;
    while (head != nullptr)
    {
        cout << "Order ID: " << head->id
             << ", Product Name: " << head->name
             << ", Quantity: " << head->quantity << endl;
        head = head->next;
    }
}

void addOrder(Order *&head, int id, string name, int quantity)
{
    Order *newOrder = new Order{id, name, quantity, nullptr};
    morder[id] = newOrder;
    if (head == nullptr)
    {
        head = newOrder;
    }
    else
    {
        Order *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newOrder;
    }

//    cout << "Order added successfully!" << endl;
}

void searchOrder(Order *head, int id)
{/*
    while (head != nullptr)
    {
        if (head->id == id)
        {
            cout << "Order found: Order ID: " << head->id
                 << ", Product Name: " << head->name
                 << ", Quantity: " << head->quantity << endl;
            return;
        }
        head = head->next;
    }*/
    if(morder.count(id)==0)  cout << "No order found with ID: " << id << endl;
    else{
        head = morder[id];
            cout << "Order found: Order ID: " << head->id
                 << ", Product Name: " << head->name
                 << ", Quantity: " << head->quantity << endl;
    }
    return;
}

void deleteOrder(Order *&head, int id)
{
    if (head == nullptr)
    {
        cout << "No orders available!" << endl;
        return;
    }

    if (head->id == id)
    {
        Order *temp = head;
        head = head->next;
        delete temp;
        cout << "Order with ID " << id << " has been deleted!" << endl;
        return;
    }

    Order *current = head;
    Order *previous = nullptr;

    while (current != nullptr && current->id != id)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "No order found with ID: " << id << endl;
        return;
    }

    previous->next = current->next;
    delete current;
    morder.erase(id);
    cout << "Order with ID " << id << " has been deleted!" << endl;
}

int main()
{
    Order *head = nullptr; // Start of the order linked list
    int choice, id, quantity;
    string name;

    while (true)
    {
        /*
        cout << "\nOrder Management System:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Search Order" << endl;
        cout << "3. Delete Order" << endl;
        cout << "4. List All Orders" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
*/
        cin >> choice;

        switch (choice)
        {
        case 1:
          //  cout << "Enter Order ID: ";
            cin >> id;
        //    cout << "Enter Product Name: ";
            //cin.ignore(); // To clear the newline character from input buffer
//            getline(cin, name);
            cin >> name;
  //          cout << "Enter Quantity: ";
            cin >> quantity;
            addOrder(head, id, name, quantity);
            break;
        case 2:
    //        cout << "Enter the Order ID to search: ";
            cin >> id;
            searchOrder(head, id);
            break;
        case 3:
      //      cout << "Enter the Order ID to delete: ";
            cin >> id;
            deleteOrder(head, id);
            break;
        case 4:
            printOrders(head);
            break;
        case 5:
            cout << "System exiting, thank you for using!" << endl;
            return 0;
        default:
            break;
        }
    }

    return 0;
}
