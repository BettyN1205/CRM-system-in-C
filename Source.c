#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct CUSTOMER {
	int id;
	int age;
	char name[10];
	char gender;
	char phone[16];
	char email[25];
};
struct CUSTOMER customer[100];

int loop = 1;//control quit menu
int key;
char quit;
int customerNum = 0;
int i;

//printf a customer's info
void printcustomerinfo(struct CUSTOMER* c) {
	printf("\n%d\t%s\t%c\t%d\t%s\t%s\n", (*c).id, (*c).name, (*c).gender, (*c).age, (*c).phone, (*c).email);//c->id
}

//1 add customers
void add_customers() {
	customer[customerNum].id = customerNum + 1;
	printf("-----------Adding customers-----------\n");
	printf("\nname:");
	scanf("%s", customer[customerNum].name);
	getchar();
	printf("\ngender:");
	scanf("%c", &customer[customerNum].gender);
	getchar();
	printf("\nage:");
	scanf("%d", &customer[customerNum].age);
	getchar();
	printf("\nphone:");
	scanf("%s", customer[customerNum].phone);
	getchar();
	printf("\nemail:");
	scanf("%s", customer[customerNum].email);
	getchar();
	customerNum++;
}

//2 modify customers
void modify_customers() {
	int id;
	char choice;
	printf("----------Modifying----------\n");
	printf("Please enter the id of the customer\n");
	scanf("%d", &id);
	getchar();
	int index = findindex(id);
	if(index == -1) {
		printf("The customer id is not exist.\n");
		return 0;
	}
	else {
		printf("the name of the customer is %s\n", customer[id - 1].name);
		printf("Are you sure to modify it? y/n\n");
		scanf("%c", &choice);
		getchar();
		if (choice == 'y') {
			printf("please enter the new name\n");
			scanf("%s", customer[id - 1].name);
			getchar();
			printf("please enter the new gender\n");
			scanf("%c", &customer[id - 1].gender);
			getchar();
			printf("please enter the new age\n");
			scanf("%d", &customer[id - 1].age);
			getchar();
			printf("please enter the new phone\n");
			scanf("%s", customer[id - 1].phone);
			getchar();
			printf("please enter the new email\n");
			scanf("%s", customer[id - 1].email);
			getchar();
		}
	}
}

//3 delete customers: 
//根据输入的id,遍历所有id，返回index；如果index为-1，说明所查找的id不存在，如果index不为-1，则找到了输入的id
int findindex(int id) {
	int index = -1;
	for (i = 0; i < customerNum; i++) {
		if (customer[i].id == id) {
			index = i;
		}
	}
	return index;
}

int delete_customer(int id) {
	int index = findindex(id);
	if (index == -1) {
		printf("The customer id is not exist.\n");
		return 0;
	}
	else {
		//删除的本质，就是将后面的数据整体前移。
		for (i = index + 1; i < customerNum; i++) {
			customer[i - 1] = customer[i];//替换
		}
		customerNum--;
		printf("successfully deleted\n");
			return 1;
	}
}

void delete_customer_view() {
	int id;
	printf("----------------delete--------------------\n");
	printf("Please enter the id of the customer:(enter -1 to quit)\n");
	scanf("%d", &id);
	getchar();
	if (id == -1) {
		printf("----------------you quit deleting--------------\n");
	}
	else {
		delete_customer(id);
	}
}

//4 view customers
void view_customers() {
	printf("----------------list--------------------\n");
	printf("\nid\tname\tgender\tage\tphone\temail\n");
	for (i = 0; i<customerNum; i++) {
		printcustomerinfo(&customer[i]);
	}
}

//menu
void menu() {
	do {
		printf("------------CRM SYSTEM--------------\n");
		printf("            1. add customer              \n");
		printf("            2. modify customer           \n");
		printf("            3. delete customer           \n");
		printf("            4. view customers            \n");
		printf("            5. quit           \n");
		printf("Please chose 1-5\n");
		scanf("%d", &key);
		getchar();

		switch (key)
		{
		case 1:
			add_customers();

			break;
		case 2:
			modify_customers();

			break;
		case 3:

			delete_customer_view();

			break;
		case 4:
			view_customers();

			break;

		case 5:
			printf("Quit? y/n\n");
			scanf("%c", &quit);
			getchar();
			if (quit == 'y') {
				loop = 0;
			}
			break;

		default:
			printf("error,please re-enter\n");
			break;
		}
	} while (loop);

	printf("\n Quit the system\n");
	getchar();
}

int main() {

	menu();

	return 0;
}