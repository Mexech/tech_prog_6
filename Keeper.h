#include <iostream>
#include "Worker.h"

class Keeper {
    public:
        int amount = 0;
        struct Node {
            Worker *data;
            struct Node *next;
        };
        Keeper();
        ~Keeper();
        
        void push(Worker *val);
        void pop(int num);
        Worker *get(int num);
        void display();
        void save();
        void load();
        void free();

        bool isEmpty();
        Node *getHead();

        void checkEmptiness();
    private:
        Node *head, *tail;
};