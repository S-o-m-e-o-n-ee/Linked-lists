/* Project: Homework 5
 * Name   : Sarah Wilkinson
 * Date   : 04/25/2024
 * File   : Q4.c
 * Notes  : Deletes the first node of a liked list.
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
struct Node * deleteFirst(struct Node *firstNode);
void displayList(struct Node *firstNode);   

// Main function
int main() {
    int n;

    // Displaying the purpose of the program
    printf("\n\n Linked List : Deletes the first node of a liked list: \n");
    printf("-----------------------------------------------------------\n");

    // Inputting the number of nodes for the linked list
    printf("Input the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list with n nodes
    struct Node *linkedList = createNodeList(n);

    // Displaying the data entered in the linked list
    printf("\nLinked list before operation: \n");	   
    displayList(linkedList);

    // Deletes the first node in the linked list
    linkedList = deleteFirst(linkedList);

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

// Function to delete the first node in the linked list
struct Node * deleteFirst(struct Node *firstNode) {

    // Displays the data that is being deleted
    printf("\nData from node 1 that is being deleted: %d\n", firstNode->item);

    // Creates a temp variable to store the old first node
    struct Node *oldFirstNode = firstNode;

    // Moves the pointer from the old first node to the new first node, the old second node
    firstNode = firstNode->next;

    // Frees the old first node
    free(oldFirstNode);

    // Returns a refrence to the new first node
    return(firstNode);
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