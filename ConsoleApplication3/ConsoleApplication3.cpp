#include <iostream>
#include <conio.h>
using namespace std;


struct tqueue { //type queue
	int    data;
	tqueue* next;
};

void push(tqueue** head, tqueue** tail, int data) {
	tqueue* ptr = new tqueue();
	(*ptr).data = data;
	(*ptr).next = NULL;

	if (*head == NULL)
		*head = *tail = ptr;
	else {
		(*tail)->next = ptr;
		*tail = ptr;
	}
}

void set_max_first(tqueue** head) {
	tqueue* max = *head;     //елемент з максимальним значенням
	tqueue* premax = NULL;   //елемент перед максимальним
	tqueue* preiter = *head; //тимчасове звереження попереднього елемента в циклі

	bool flag = false;

	for (tqueue* iter = *head; iter != NULL; iter = (*iter).next) {
		if ((*iter).data > (*max).data) {
			//premax = tmp;
			flag = true;
			max = iter;
		}

		if (flag)
		{
			premax = preiter;
			flag = false;
		}
		preiter = iter;
	}
	if (max == *head) //alredy first
	{
	}
	//else if (premax == NULL) //max second
	//{
	//	tqueue* temp = max;
	//	(*max).next = *head;
	//	*head = max;
	//	(*head)->next = temp;
	//}
	else {
	
		//tqueue* temp = max;
		(*premax).next = (*max).next;
		(*max).next = *head;
		*head = max;
		//(*head)->next = temp;
	}

}

void print(tqueue** head) {

	tqueue* tmp = *head;;
	while (tmp != NULL) {
		//cout << "||" << (*tmp).data << "||" << '\n';
		printf(" %5d", (*tmp).data);
		//tmp = head;
		tmp = (*tmp).next;

	}
	cout << endl;
}

void start() {

	tqueue* head = NULL, * tail = NULL;
	for (int i = 0; i < 20; i++)
		push(&head, &tail, -50 + rand() % (100));
	
	/*push(&head, &tail, 5);
	push(&head, &tail, 40);
	push(&head, &tail, 4);
	push(&head, &tail, 10);*/

	print(&head);	//до переміщення
	set_max_first(&head);
	print(&head);	//після переміщення
	//tqueue* tmp;
	//while (head != NULL) {
	//	cout << "||" << (*head).data << "||" << '\n';

	//	//tmp = head;
	//	head = (*head).next;
	//	//delete tmp;
	//}
	_getch(); //чекаємо натиснення будь-якої клавіші.
}

int main(void) {
	start();
	return 0;
}
