#include<iostream>
#include<sstream>
#include<stdexcept>
#include<string>
#include <algorithm>

#include "Lab13.hpp"

/*
In a nutshell: a singly-linked list is a data structure for implementing a generic array of elements,
 where each node has data, and a pointer to the next node. 
 The list structure typically has pointers to the list’s first node and last node. 
 A singly-linked list’s first node is typically called the head, and the last node the tail.
Linked above is a header file containing the definition for a singly-linked list class named SingleLink, and a definition for a linked list node class named Node.
Below is the interface for the two classes as it stands right now:
struct Node {
    public:
        int data_;
        Node *next_;
    
        Node() : data_(0), next_(nullptr) {};
        Node(int d) : data_(d), next_(nullptr) {};
};
Node has two private members, Node* next_ and int data_.
next_ is a pointer to another instance of type Node; the “chain” that makes up the structure of the entire list.
data_ is the value held by the Node. For the purposes of today’s lab, it’ll only be allowed to hold integers.
It has two constructors, a default that initializes data_ to 0, 
and a one-parameter variant that initializes data_ to the incoming argument.

class SingleLink {
    private:
        Node *head_;
        Node *tail_;

    public:
        SingleLink();         
        SingleLink(int dat);    
        void append_back(int);

        friend std::ostream& operator<<(std::ostream &out, SingleLink &s);
        bool del(int val);
        Node& operator[](size_t index);
        
        // Rule of three stuff
        ~SingleLink();
        SingleLink(const SingleLink &);
        SingleLink& operator=(SingleLink);
};
SingleLink has two private members, Node* head_ and Node* tail_, which are pointers to the first and last node of the list, respectively.
If the list is ever empty, head_ and tail_ should point to nullptr.
If the list ever has one Node, both the head_ and tail_ should point to that one Node.
SingleLink has two constructors; a default with no arguments, and a one-parameter variant that should add a Node with data, dat, to the list.
If the one-parameter variant is invoked, the head and tail pointers will need to be adjusted to point to this new Node.

What’s missing?
Pretty much everything. But, this is an opportunity to get more practice with pointers, 
and get a feel for how to program something you’ll be becoming much more familiar with in CSE 331. 
You may not finish all of it during the lab session, 
but work through from the beginning and see how far you can get! (asynchronous expectations are listed below)

None of the Rule of Three functions have been implemented. If you have the time, it would be good if you implemented those.
Before jumping into the member functions, you should make the default and one-parameter constructors.
Listed below are the member functions that you need to implement. They are presented below in the order that they should be easiest to design and implement.
void append_back(int dat)
Member function; creates a new Node instance with data_=dat and appends it to the end of the list.
Make sure that you use dynamic allocation (the new keyword) so that the Node you create is not deleted when it falls out of scope.
Also make sure that you are re-routing the head_ and tail_ pointers correctly (what happens when this is the first Node being appended vs. when it is the second Node being appended?)
ostream & operator<<(ostream &out, const SingleLink &s)
Friend function; pushes the data_ member of each Node instance in the list to the output stream, out, and returns ostream &.
A good programming technique would be to modify ‘main.cpp’ to show that your member function works before moving on. Call the append_back() member function with, say, integers {1, 2, 4, 8}, and then use cout to print them.
The next task on our list is the del() method (we can’t call it delete(), since delete is a keyword in C++ ☹️). del() should remove a particular value from the list. Before you write any code, identify any edge cases your list might have to deal with. Type them as comments under the del() method.
⭐ Show the TA your working append_back() and operator<<() functions. And, show your TA all of the cases del() must account for before moving on.
bool del(int val)
Searches through the list for the first Node that has the same data_ value as val. If found, deletes the Node and returns true, otherwise it returns false.
Again, make sure to modify ‘main.cpp’ for testing.
Node & operator[](size_t index)
This member function is an override for the [] operator. On a call, such as sl[3], the argument, 3, is assigned to the parameter, index. The return value is a reference to a Node so that the Node can be modified (i.e., can show up on either side of an assignment operator).
You’ll have to search the list (starting from the head_ pointer) for the index-th Node. Then, return a reference to that Node, or throw an out_of_range exception if you have traversed all the way to the end of the list.


*/
SingleLink::SingleLink() : head_(nullptr), tail_(nullptr) {}

SingleLink::SingleLink(int dat) {
    head_ = new Node(dat);
    tail_ = head_;
}

void SingleLink::append_back(int dat) {
    Node *new_node = new Node(dat);

    if (head_ == nullptr) {
        head_ = new_node;
        tail_ = head_;
    } else {
        tail_->next_ = new_node;
        tail_ = new_node;
    }
}

std::ostream& operator<<(std::ostream &out, const SingleLink &s) {
    Node *current_node = s.head_;

    while (current_node != nullptr) {
        out << current_node->data_;
        if (current_node->next_ != nullptr) {
            out << ", ";
        }
        current_node = current_node->next_;
    }

    return out;
}

bool SingleLink::del(int val) {
    if (head_ == nullptr) {
        return false;
    }

    if (head_->data_ == val) {
        Node *temp = head_;
        head_ = head_->next_;
        delete temp;
        return true;
    }

    Node *current_node = head_;
    while (current_node->next_ != nullptr) {
        if (current_node->next_->data_ == val) {
            Node *temp = current_node->next_;
            current_node->next_ = current_node->next_->next_;
            delete temp;
            return true;
        }
        current_node = current_node->next_;
    }

    return false;
}

Node& SingleLink::operator[](size_t index) {
    Node *current_node = head_;
    size_t counter = 0;

    while (current_node != nullptr) {
        if (counter == index) {
            return *current_node;
        }
        current_node = current_node->next_;
        ++counter;
    }

    throw std::out_of_range("out of range");
}

SingleLink::~SingleLink() {
    while (head_ != nullptr) {
        Node *temp = head_;
        head_ = head_->next_;
        delete temp;
    }
}

SingleLink::SingleLink(const SingleLink &other) : head_(nullptr), tail_(nullptr) {
    Node *current_node = other.head_;

    while (current_node != nullptr) {
        append_back(current_node->data_);
        current_node = current_node->next_;
    }
}

SingleLink& SingleLink::operator=(SingleLink other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    return *this;
}