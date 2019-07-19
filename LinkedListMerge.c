/* author: Prashant Mahure */
#include<stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *next;
	int data;

};

struct Node *appendNewNode(int x){

	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;

}

void sortList(struct Node *head){
	int tempInt,no_elements=10;
	struct Node *temp = head;
	
	printf("\nNow Sorting the List....\n");
	
	for (int i = 0; i < no_elements; ++i){
		temp = head;
		
		while(temp->next!=NULL){
			
			if (temp->next->data < temp->data)
			{
				tempInt = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tempInt;
				
			}
			temp = temp->next;
		}
	}
}

int main(){
	int a,arr[] = {4,7,9,6,5};
	int arr_length = sizeof(arr)/sizeof(a);
	struct Node *head = appendNewNode(2);
	struct Node *temp = head;
	
	head->next = appendNewNode(3);
	head->next->next = appendNewNode(11);
	head->next->next->next = appendNewNode(4);

	printf("List:\n");
	do{
		printf("%d\t", temp->data );
		temp = temp->next;
	}while(temp->next!=NULL);
	printf("%d\n", temp->data );
	
// Adding array data
	printf("Appending Array to List...\n");
	for (int i = 0; i <= arr_length; i++)
	{	
		temp->next = appendNewNode(arr[i]);
		temp = temp->next;
	}
	
//Printing new List
	printf("Appended List:\n");
	temp = head;
	while(temp->next!=NULL){
		
		printf("%d\t", temp->data );
		temp = temp->next;
		
	}
	//sorting list
	sortList(head);
	
	//printing sorted list
	printf("Sorted List:\n");
	temp = head->next;
	while(temp->next!=NULL){
		
		printf("%d\t", temp->data );
		temp = temp->next;
		
	}
	printf("%d\n", temp->data );
	
	return 0;
}
