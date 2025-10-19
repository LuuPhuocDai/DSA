#include "iostream"
using namespace std;

// struct.
typedef struct Stack{
	int data;
	Stack *next;
}stack;


// List.
class List{
	public:
		// khai bao.
		List();
		stack* s;
		
		// ktra rong.
		int empty();
		
		// dem phan tu.
		int Size();
		
		// cap phat dong.
		stack* makeStack(int x);
		
		// them phan tu.
		void push(int x);
		
		// xoa phan tu.
		void pop();
		
		// menu.
		int menu();
		
		// xuat danh sch trong stack.
		void outPut();
		
};

// khai bao.
List::List(){
	s = NULL;
}

// ktra rong.
int List::empty(){
	return s == nullptr;
}

// cap phat dong.
stack* List::makeStack(int x){
	stack* temp = new Stack();
	temp->data = x;
	temp->next = nullptr;
	return temp;
}

// dem phan tu trong stack.
int List::Size(){
	int count = 0;
	stack* p = s;
	while(p != nullptr){
		p = p->next;
		count++;
	}
	return count;
}

// them phan tu vao stack.
void List::push(int x){
	stack* temp = makeStack(x);
	if(s == nullptr) s = temp;
	else{
		temp->next = s;
		s = temp;
	}
}

// xoa phan tu ra khoi stack.
void List::pop(){
	if(s == nullptr) return;
	stack* temp = s;
	s = s->next;
	delete temp;
}

// xuat danh sach cua stack.
void List::outPut(){
	cout<<"\n   == STACK ==\n";
	stack* p = s;
	while(p != nullptr){
		cout<<"_________________"<< endl;
		cout<<"|\t"<< p->data <<"\t|"<< endl;
		p = p->next;
	}
	cout<<"_________________"<< endl;
}

// menu
int List::menu(){
	int choice;
	cout<<"\n============== menu ==============\n";
	cout<<"1. them phan tu vao stack."<< endl;
	cout<<"2. xoa phan tu ra khoi stack."<< endl;
	cout<<"3. Dem phan tu trong Stack."<< endl;
	cout<<"4. xuat phan tu trong Stack."<< endl;
	cout<<"0. thoat";
	cout<<"\n==================================\n";
	cout<<"nhap lua chon: "; cin >> choice;
	return choice;
}



int main(){
	List a;
	
	int choice;
	do{
		choice = a.menu();
		switch(choice){
			case 1:
				int b;
				cout<<"nhap phan tu: "; cin >> b;
				a.push(b);
				break;
			case 2:
				a.pop();
				break;
			case 3:
				cout<<"Trong danh sach co "<< a.Size() << " phan tu."<< endl;
				break;
			case 4:
				a.outPut();
				break;
			case 0:
				cout<<"----Tam biet----"<< endl;
				break;
			default:
				cout<<"lua chon cua ban khong hop le!!!"<< endl;
				break;
		}
	}while(choice != 0);
	return 0;
}

