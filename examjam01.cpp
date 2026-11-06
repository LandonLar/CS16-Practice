
    //Landon Larson, 11/04/2026

    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    //Q1

    struct Photo{
        int resolution;
        int date;
        vector<string> tags;
        Photo* next;
    };

    Photo* filter(Photo* head, int reqResolution, int reqDate, string tag){
        Photo* current = head;
        Photo* previous = nullptr;

        while(current != nullptr){
            bool remove = false;

            if(current->resolution < reqResolution){
                remove = true;
            }

            if(current->date > reqDate){
                remove = true;
            }

            for(string t : current->tags){
                if(t == tag){
                    remove = true;
                }
            }

            if(remove){
                Photo* temp = current;

                if(previous == nullptr){
                    head = current->next;
                }
                else{
                    previous->next = current->next;
                }

                current = current->next;
                delete temp;
            }
            else{
                previous = current;
                current = current->next;
            }
        }

        return head;
    }

    //Q2

    struct Node
    {
        int data;
        Node* next;
    };

    Node* findTail(Node* head){
        if(head == nullptr){
            return nullptr;
        }

        Node* current = head;

        while(current->next != nullptr){
            current = current->next;
        }

        return current;
    }

    void append(Node* head, int newValue){
        if(head == nullptr){
            return;
        }

        Node* newNode = new Node;
        newNode->data = newValue;
        newNode->next = nullptr;

        Node* tail = findTail(head);
        tail->next = newNode;
    }

    void removeTail(Node* head){
        if(head == nullptr || head->next == nullptr){
            return;
        }

        Node* current = head;

        while(current->next->next != nullptr){
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    //Q3

    bool palindrome(string word){
        if(word.length() <= 1){
            return true;
        }

        if(word[0] != word[word.length() - 1]){
            return false;
        }

        return palindrome(word.substr(1, word.length() - 2));
    }
