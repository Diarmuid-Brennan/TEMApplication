// TEMApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Diarmuid Brennan c00133947
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class node
{
public:
    string data;
    node* next;
    node(string input)
    {
        data = input;      
        next = NULL;
    }
};

node* AddWord(node*, int*);
node* Undo(node*, int*);
string lastTypedWord(node*);
bool Update(node*);
int size(int);
bool isEmpty(node*);
node* clear(node*, int*);
void TraverseList(node*);
void uploadListToFile(node*);

int main()
{
    node* head = NULL;
    int numWords = 0;
    string lastWord = "";
    int response = -1;
    while (response != 0)
    {
        cout << "\n********MENU********\n";
        cout << "1. Add a value to the front of the list\n";
        cout << "2. Remove the last value that was entered\n";
        cout << "3. Retrieve the last value that was entered\n";
        cout << "4. Update an existing word\n";
        cout << "5. Return the number of words entered\n";
        cout << "6. Checks if the document is empty\n";
        cout << "7. Remove all the words from the list\n";
        cout << "8. Traverse through each word in the list\n";
        cout << "9. Upload list to a document\n";
        cout << "0. Exit\n";
        cout << "*********************\n\n";

        cout << "Enter a value to select a operation from the menu :  ";
        cin >> response;
      
        switch (response)
        {
        case 1:
            cout << "1. Add a word to be inserted to the list.\n";
            head = AddWord(head, &numWords);
            TraverseList(head);
            break;
        case 2:
            cout << "2. Remove the last word inserted to the list.\n";
            head = Undo(head, &numWords);
            TraverseList(head);
            break;
        case 3:
            cout << "3. View the last word inserted to the list.\n";
            lastWord = lastTypedWord(head);
            if (!isEmpty(head))
            {
                cout << "The last word entered was " << lastWord << ".\n";
            }
            TraverseList(head);
            break;
        case 4:
            cout << "4. Update a previously added word in the list.\n";
            if (Update(head))
            {
                cout << "The list has been successfully updated\n";
                TraverseList(head);
            }
            else
            {
                if (!isEmpty(head))
                {
                    cout << "The word was not found in the list \n";
                    TraverseList(head);
                }
                
            }
            break;
        case 5 :
            cout << "5. Return the size of the list.\n";
            cout << "The number of words currently in the list is " << size(numWords) << "\n";
            TraverseList(head);
            break;
        case 6:
            cout << "6. Check if the list is empty.\n";
            if (isEmpty(head))
            {
                cout << "The list is empty\n";
            }
            else
            {
                cout << "The list is not empty\n";
            }
            break;
        case 7:
            cout << "7. Remove all values from the list.\n";
            head = clear(head, &numWords);
            TraverseList(head);
            break;
        case 8:
            cout << "8. Display all current values in the list.\n";
            TraverseList(head);
            break;
        case 9:
            cout << "9. Upload the list to a text document.\n";
            uploadListToFile(head);
            head = clear(head, &numWords);
            break;    
        case 0:
            cout << "You have exited the application\n";
            break;
        default:
            cout << "That is not an option\n";
        }
    }


    return 0;
}


node* AddWord(node* head, int* size)
{
    
    string word = "";
    cout << "Enter a word to be inserted to the list:   ";
    cin >> word;

    node* newNode = new node(word);
    if (isEmpty(head)) 
    {
        head = newNode;
        *size = *size + 1;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        *size = *size + 1;
    }
    cout << word << " has been successfully added to the list.\n";
    return head;
}

node* Undo(node* head, int* size)
{
    
    if (isEmpty(head))
    {
        cout << "List is Empty\n";
        return head;
    }
    else
    {
        cout << lastTypedWord(head) << " was successfully removed from the list\n";
        head = head->next;
        *size = *size - 1;
        
    }
    return head;
}

string lastTypedWord(node* head)
{
    
    if (isEmpty(head))
    {
        cout << "List is Empty\n";
        return "";
    }
    else
    {
        string value = head->data;
        return value;
    }
}

bool Update(node* head)
{
    
    if (isEmpty(head))
    {
        cout << "List is Empty\n";
        return false;
    }
    else
    {
        string word = "";
        string updatedWord = "";
        TraverseList(head);
        cout << "Enter the word to be updated in the document:  ";
        cin >> word;
        cout << "Enter the word to be updated too:  ";
        cin >> updatedWord;

        node* newNode = new node(word);
        node* current = head;
        bool result = false;
        while (current != NULL)
        {
            if ((current->data).compare(word) == 0)
            {
                current->data = updatedWord;
                result = true;
            }
            current = current->next;
        }
        return result;
    }
}

int size(int size)
{
    
    return size;
}

bool isEmpty(node* head)
{
    
    if (head == NULL)
    {
        return true;
    }
    return false;
}

node* clear(node* head, int* size)
{
    
    if (isEmpty(head))
    {
        cout << "List is Empty\n";
        return head;
    }
    else
    {
        head = NULL;
        *size = 0;
        cout << "List has been cleared\n";
        return head;
        
    }
}

void TraverseList(node* head)
{
    
    if (isEmpty(head))
    {
        cout << "List is Empty\n";
        return;
    }
    else
    {
        cout << "The list contains: ";
        node* current = head;
        while (current != NULL)
        {
            cout << current->data << "  ";
            current = current->next;
        }
        cout << "\n";
    }
}

void uploadListToFile(node* head)
{
    
    if (isEmpty(head))
    {
        return;;
    }
    else
    {
        ofstream file;
        ifstream infile("TEMApplication.txt");
        
        if (infile)
        {
            file.open("TEMApplication.txt", ios::app);
            node* current = head;

            while (current != NULL)
            {
                file << current->data << ",";
                current = current->next;
            }
            cout << "List has been successfully added to file\n";
            file.close();
        }
        else
        {
            file.open("TEMApplication.txt");
            node* current = head;

            while (current != NULL)
            {
                file << current->data << ",";
                current = current->next;
            }
            cout << "File has been successfully created and list added\n";
            file.close();
        }
       
    }
}
