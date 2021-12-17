#include <iostream>
#include <conio.h>
using namespace std;


struct tqueue {
	int    val;
	tqueue* next;
};


void push(tqueue** head, tqueue** tail, int val) {
	tqueue* ptr = new tqueue();
	(*ptr).val = val;
	(*ptr).next = NULL;

	if (*head == NULL)
		*head = *tail = ptr;
	else {
		(*tail)->next = ptr;
		*tail = ptr;
	}
}


void max_first(tqueue** head) {
	tqueue* tmp = *head;
	tqueue* pretmp = NULL;
	tqueue* preiter = *head;

	bool flag = false;

	for (tqueue* iter = *head; iter != NULL; iter = (*iter).next) {
		if ((*iter).val > (*tmp).val) {
			//pretmp = tmp;
			flag = true;
			tmp = iter;
		}

		if (flag)
		{
			pretmp = preiter;
			flag = false;
		}
		preiter = iter;
	}
	if (tmp == *head) //alredy first
	{
	}
	else if (pretmp == NULL) //max second
	{
		//надо дописать


	}
	else {
		/*int  val = (*tmp).val;
		(*tmp).val = (*head)->val;
		(*head)->val = val;*/
		tqueue* temp = tmp;
		(*pretmp).next = (*tmp).next;
		(*tmp).next = *head;
		*head = tmp;
		//(*head)->next = temp;
	}

	//kjhkjghhjlkj


}

void print(tqueue** head) {

	tqueue* tmp = *head;;
	while (tmp != NULL) {
		cout << "||" << (*tmp).val << "||" << '\n';

		//tmp = head;
		tmp = (*tmp).next;

	}
	cout << endl;
}


void start() {

	tqueue* head = NULL, * tail = NULL;
	for (int i = 0; i < 10; i++)
		push(&head, &tail, -50 + rand() % (100));
	print(&head);
	max_first(&head);
	print(&head);
	//tqueue* tmp;
	//while (head != NULL) {
	//	cout << "||" << (*head).val << "||" << '\n';

	//	//tmp = head;
	//	head = (*head).next;
	//	//delete tmp;
	//}
	_getch(); //??
}

int main(void) {
	start();
	return 0;
}
