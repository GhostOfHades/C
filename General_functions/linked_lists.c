#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE; // type NODE in stead of struct Node

NODE *head = NULL; //start linked list but leave it empty

NODE * createNode (int val) //does not but it into the linked list)
{
    NODE * ptr = (NODE *) malloc (sizeof(NODE));
    if (ptr = NULL)
    {
        printf("failed to create new node\n");
        exit(1);
    }
    ptr -> data =val;
    ptr -> next = NULL;
    return ptr;
}

void insertHead (NODE *newNode)
{
    NODE * ptr = head;
    if (ptr == NULL)
        head = newNode;
    else
    {
        newNode -> next = head;
        head = newNode;
    }
}

void insertTail (NODE *newNode)
{
    NODE *ptr = head;
    if (ptr = NULL)
        head = newNode;
    else
    {
        while (ptr -> next != NULL) //transverse list to end
        ptr = ptr -> next;
        ptr -> next = newNode;
    }

}

void insertNode (NODE *newNode)
{
    NODE * ptr = head;
    NODE *prevNode = NULL;
    
    if (ptr == NULL)
    {
        head = newNode;
        return;
    }
    //Find the first node with higher value than the new node
    while ( (ptr !=NULL) && (ptr -> data < newNode -> data))
    {
        prevNode =ptr;
        ptr = ptr -> next;
    }

    if (prevNode == NULL) // new node has smallest value, insert at head
    {
        newNode -> next = head;
        head = newNode;
    }
    else if (ptr == NULL) // new node has biggest value, insert at tail
    prevNode -> next = newNode;
    else 
    {
        prevNode -> next = newNode;
        newNode -> next = ptr;
    }
}

void deleteNode (int val)
{
    NODE * ptr =head;
    NODE * temp =NULL;
    NODE * prevNode = NULL;

    if (ptr == NULL) // if list is empty, do nothing
    return 0;
    else if (ptr -> data == val) // head is the node to delete
    {
        temp = ptr -> next;
        free (ptr);
        head = temp;
    }
    else // search for node to delete
    {
        while ((ptr != NULL) && (ptr -> data != val))
        {
            prevNode = ptr;
            ptr = ptr -> next;
        }

        // link prev node to the next node
        if (ptr != NULL)
        {
            prevNode -> next = ptr -> next;
            free (ptr);
        }
    }
}

NODE * findNode (int val)
{
    NODE * ptr = head;

    while (ptr != NULL)
    {
        if (ptr -> data == val)
            return ptr;
        else
            ptr =ptr -> next;
    }
    return ptr;
}

void destroylist()
{
    NODE * ptr = head;
    NODE *nextNode = NULL;

    while (ptr != NULL)
    {
        nextNode = ptr -> next;
        free (ptr);
        ptr = nextNode;
    }
    head = NULL;
}

void printList ()
{
    NODE * ptr = head;
    while (ptr != NULL)
    {
        printf(" %d",ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

int main (void)
{
    
    return 0;
}