#define STACKSIZE 100

typedef struct ns_{
	NODE node[STACKSIZE];
	int size;
}nSTACK;

void initStack(Stack *S){
	S->size = 0;
}

int stackTop(Stack *S){
	if (S ->size ==0){
		fprintf(stderr, "Stack is empty\n");
		return -1;
	}

	return S->node[S->size-1];
}

void Stack_Push(Stack *S,int d){
	if (S->size <STACKSIZE){
		S->
	}

}