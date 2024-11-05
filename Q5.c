/* Project: Homework 5
 * Name   : Sarah Wilkinson
 * Date   : 04/25/2024
 * File   : Q5.c
 * Notes  : Sorts a linked list using merge sort (Extra credit)
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
struct Node * sortList(struct Node *firstNode);
void displayList(struct Node *firstNode);  
struct Node * murgeSort(struct Node *firstNode, int first, int last);
struct Node * murge(struct Node *firstNode, int first, int pivot, int last);

// Main function
int main() {
    int n;

    // Displaying the purpose of the program
    printf("\n\n Linked List : Sorts a linked list using merge sort (Extra credit):\n");
    printf("-----------------------------------------------------------------------\n");

    // Inputting the number of nodes for the linked list
    printf("Input the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list with n nodes
    struct Node *linkedList = createNodeList(n);

    // Displaying the data entered in the linked list
    printf("\nLinked list before operation: \n");	   
    displayList(linkedList);

    // Sorts the linked list
    linkedList = sortList(linkedList);

    // Displaying the sorted linked list
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

// Function to sort the linked list
struct Node * sortList(struct Node *firstNode) {

    // Calculates the index of the last element in the linked list
    int last = 0;
    struct Node *currentNode = firstNode;
    while(currentNode->next != NULL) {
        last++;
        currentNode = currentNode->next;
    }
    
    // Calls murgeSort with the correct arguments
    firstNode = murgeSort(firstNode, 0, last);
    
    // Returns a refrence to the first node in the sorted linked list
    return firstNode;
} 

// Function implement murge sort
struct Node * murgeSort(struct Node *firstNode, int first, int last) {

    // If the index of the first item in the section to be sorted is smaller than the index of the last index in the section to be sorted...
    if (first < last) {
        // Calculates the pivot index
        int pivot = (first + last) / 2;

        // Calls murgeSort recursively using the pivot element
        firstNode = murgeSort(firstNode, first, pivot);
        firstNode = murgeSort(firstNode, pivot + 1, last);

        // Calls murge with the correct arguments
        firstNode = murge(firstNode, first, pivot, last);
    }

    // Returns a refrence to the first node in the sorted linked list
    return firstNode;
}

// Fuction to murge two sorted sections of a linked list together
struct Node * murge(struct Node *firstNode, int first, int pivot, int last) {

    // Calculates the sizes of the two sections to be murged
    int sizeOfFirstSection = pivot - first + 1;
    int sizeOfOtherSection = last - pivot;

    // Inicializes a variable to store the current node of the section to be murged to the first node in the linked list
    struct Node *CurrentNodeOfTheSection = firstNode;

    // Updates the node stored in CurrentNodeOfTheSection to the first node in the section using a for loop
    for (int i = 0; i < first; i++) {
        CurrentNodeOfTheSection = CurrentNodeOfTheSection->next;
    }

    // Inicializes arrays to hold the data from the two sections to be murged
    int firstSection[sizeOfFirstSection], otherSection[sizeOfOtherSection];

    // Gathers the data from the two sections to the arrays
    struct Node *currentNode = CurrentNodeOfTheSection;
    for (int i = 0; i < sizeOfFirstSection; i++) {
        firstSection[i] = currentNode->item;
        currentNode = currentNode->next;
    }
    for (int i = 0; i < sizeOfOtherSection; i++) {
        otherSection[i] = currentNode->item;
        currentNode = currentNode->next;
    }

    // Inicializes the index variables to 0
    int i = 0;
    int j = 0;

    // While we don't hit the end of either section to be murged...
    while (i < sizeOfFirstSection && j < sizeOfOtherSection) {
        
        // If the current item in the first section is less than or equal to the current item in the other section...
        if (firstSection[i] <= otherSection[j]) {
        
            // Sets the data of the current node to the current item in the first section
            CurrentNodeOfTheSection->item = firstSection[i]; 

            // Increments the counter for the first section
            i++; 
        } else { // Otherwise...
        
            // Sets the data of the current node to the current item in the second section
            CurrentNodeOfTheSection->item = otherSection[j]; 

            // Increments the counter for the second section
            j++; 
        } 
        
        CurrentNodeOfTheSection = CurrentNodeOfTheSection->next;
    }

    // Adds any items left over from either section to the linked list in the correct position
    while (i < sizeOfFirstSection) { 
        CurrentNodeOfTheSection->item = firstSection[i]; 
        i++; 
        CurrentNodeOfTheSection = CurrentNodeOfTheSection->next;
    } 
    while (j < sizeOfOtherSection) { 
        CurrentNodeOfTheSection->item = otherSection[j]; 
        j++; 
        CurrentNodeOfTheSection = CurrentNodeOfTheSection->next;
    } 

    // Returns a refrence to the first node in the partialy sorted linked list
    return firstNode;
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