#include <iostream>
#include <malloc.h>

struct Data
{
	int age;
	struct Data* next;
};

struct Data* creat ();

struct Data* creat ()
{
	struct Data* S;
	S = (struct Data*)malloc(sizeof(struct Data));
	if (S == NULL)
	{
		std::cout << "Error" << std::endl;
	}
	else 
	{
		S->next = NULL;
	}
	return S;
}

void Push (int age, struct Data* S);

void Push (int age, struct Data* S)
{
	struct Data *temp;
	temp = (struct Data*)malloc(sizeof(struct Data));
	if (S->next == NULL)
	{
		temp->age = age;
		temp->next = NULL;
		S->next = temp;
	}
	else
	{
		temp->age = age;
		temp->next = S->next;
		S->next = temp;
	}
}

void Pop (struct Data* S);
void Pop (struct Data* S)
{
	struct Data* temp;
	temp = S->next->next;
	S->next->next = NULL;
	free(S->next);
	S->next = temp;
}

void Top(struct Data* S);
void Top(struct Data* S)
{
	std::cout << S->next->age << std::endl;
} 

int IsEmpty(struct Data* S);
int IsEmpty(struct Data* S)
{
	if (S->next == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	struct Data* data = creat();
	Push(13, data);
	std::cout << data->next->age << std::endl;
	Push(14, data);
	std::cout << data->next->age << std::endl;
	Push(15, data);
	std::cout << data->next->age << std::endl;
	Push(16, data);
	std::cout << data->next->age << std::endl;
	Pop(data);
	Top(data);
	return 0;
}