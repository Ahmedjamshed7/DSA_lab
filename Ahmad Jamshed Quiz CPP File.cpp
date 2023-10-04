
void printlist(){
	struct node*ptr= head;
	printf("\n[");
	if(head!=NULL);{
	while(ptr->next!=ptr){
		printf("c%% d", ptr->key,ptr->data);
		ptr=ptr->next;
		
	}
	
	}
	  }
    cout<<(" ]");
}
    int main(){
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56);
    printf("Circular Linked List: ");
    printlist();
    return 0;
}
    