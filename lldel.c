#include <stdio.h>
#include <stdlib.h>
 

struct Node
{
    int data;
    struct Node *next;
};
 

   
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 

void deleteNode(struct Node **head_ref, int key)
{
    
    struct Node* temp = *head_ref, *prev;
 
    
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   
        free(temp);               
        return;
    }
 
    
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    
    if (temp == NULL) return;
 
    
    prev->next = temp->next;
 
    free(temp);  
}
 

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 

int main()
{
int k,n,l,i;
    
    struct Node* head = NULL;
printf("enter the size");
scanf("%d",&k);
for(i=0;i<k;i++)
{
	printf("enter the number");
	scanf("%d",&n);
    	push(&head, n);
}    
 
    puts("Created Linked List: ");
    printList(head);
    printf("enter the node to be deleted");
    scanf("%d",&l);
    deleteNode(&head, l);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}
