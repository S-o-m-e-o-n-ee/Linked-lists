/* Project: Homework 5
 * Name   : Sarah Wilkinson
 * Date   : 04/25/2024
 * File   : Q1.c
 * Notes  : Inserts a node at the begining of a singly linked list. 
*/

#include <stdio.h>
#include <stdlib.h>


//Create a struct node for linked list
struct Node{
    int item;
    struct Node * next;
} *Node;


// Function prototypes
struct Node * createNodeList(int n);
struct Node * insert(struct Node *firstNode, int data);
void displayList(struct Node *firstNode);   

// Main function
int main() {
    int n, data;

    // Displaying the purpose of the program
    printf("\n\n Linked List : Inserts a node at the begining of a singly linked list:\n");
    printf("--------------------------------------------------------------------------\n");

    // Inputting the number of nodes for the linked list
    printf("Input the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list with n nodes
    struct Node *linkedList = createNodeList(n);

    // Displaying the data entered in the linked list
    printf("\nLinked list before operation: \n");	   
    displayList(linkedList);

    // Inputting the data to be added to the linked list
    printf("\nInput data to be added to the linked list: ");
    scanf("%d", &data);

    // Adding the new node 
    linkedList = insert(linkedList, data);

    // Displaying the new linked list
    printf("\nLinked list after operation: \n");	   
    displayList(linkedList);

    // Freeing all the memory used by the linked list
    while (1) { 
        struct Node *previousNode = linkedList;

        if (linkedList->next == NULL) {
            break;
        } else {
            linkedList = linkedList->next;
        }

        free(previousNode);
    }
    free(linkedList);

    // Returns 0
    return 0;
}

// Function to create a linked list with n nodes
struct Node * createNodeList(int n) {

    // Declares and Inicializes the first node in the linked list;
    struct Node *firstNode;
    firstNode = (struct Node *) malloc(sizeof(struct Node));
    
    // Gathers the first item from user input and stores it in the first node
    int data;
    printf("Input data for node 1: ");
    scanf("%d", &data);
    firstNode->item = data;
    
    // Declares the nodes that are used to create the linked list
    struct Node *currentNode;
    struct Node *previousNode;

    // Inicializes previousNode to firstNode
    previousNode = firstNode;

    // Starting at two (because the first item has already been added) and continuing up to and including n...
    for (int i = 2; i <= n; i++) {
        // Inicializes currentNode to a new node
        currentNode = (struct Node *) malloc(sizeof(struct Node));
        
        // Gathes the data from user input and stores it in currentNode
        printf("Input data for node %d: ", i);
        scanf("%d", &data);
        currentNode->item = data;

        // Conects the previous node and the current node
        previousNode->next = currentNode;

        // Steps forward one
        previousNode = currentNode;    
    }

    // Returns a refrence to the first node in the linked list
    return firstNode;
}

// Function to add a node to the beginning of the linked list
struct Node * insert(struct Node *firstNode, int data) {

    // Creates the new node to be inserted with the proper values and conects it to the previous first node in the linked list
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));;
    newNode->item = data;
    newNode->next = firstNode;

    // Returns a refrence to the new first node in the linked list
    return newNode;
}

// Function to display the linked list
void displayList(struct Node *firstNode) {

    // Declares and inicializes a node to store the current node that we are on in the orriginal linked list, begining with the first one
    struct Node *currentNode;
    currentNode = firstNode;

    // Iterates over the linked list
    while (1) { 
        // Prints the item from the current node
        printf("Data = %d\n", currentNode->item);

        // Breaks if we've reached the end of the linked list, and moves the current node forward if not
        if (currentNode->next == NULL) {
            break;
        } else {
            currentNode = currentNode->next;
        }
    }
}