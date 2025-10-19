#include "iostream"
using namespace std;

typedef struct Node{
	int data;
	Node *next;
	Node *prev;
} node;

// class.
class List{
	public:
		
	// khoi tao.
	List();
	node* head;
	node* tail;

	// xuat danh sach.
	void outPut();

	// cap phat dong.
	node* makeNode(int x);

	// dem phan tu trong danh sach.
	int length();

	// menu.
	int menu();

	// chen phan tu.
	void insertFirst(int x);
	void insertLast(int x);
	void insertMiddle(int x, int pos);
	void insert(int x, int pos);

	// xoa phan tu.
	void deleteFirst();
	void deleteLast();
	void deleteMiddle(int pos);
	void Delete(int pos);
	void deleteList();

	// sap xep.
	void AscendingSort();
	void DescendingSort();

	// kiem tra rong.
	bool empty();

	// kiem tra phan tu trong ham.
	bool search(int x);
	
	// dao cac phan tu trong danh sach.
	void reverse1();
	
	
};

List ::List(){
	head = NULL;
	tail = nullptr;
}

// cap phat dong.
node* List::makeNode(int x){
	node* temp = new Node();
	temp->data = x;
	temp->prev = temp->next = nullptr;
	return temp;
}

// xuat danh sach.
void List::outPut(){
	node* i = head;
	int count = 1;
	cout<<"\n================ danh sach ==============\n";
	cout<<"STT\tGia Tri"<< endl;
	while(i != nullptr){
		cout<< count << "\t  "<< i->data << " " << endl;
		i = i->next;
		count++;
	}
	cout<<"\n=========================================\n";
}

// dao phan tu trong sach.
void List::reverse1(){
	node* i = tail;
	cout<<"\nDanh sach sau khi dao"<< endl;
	while(i != nullptr){
		cout<< i->data << endl;
		i = i->prev;
	}
}

// dem phan tu trong danh sach.
int List::length(){
	int count = 0;
	node* p = head;
	while(p != nullptr){
		count++;
		p = p->next;
	}
	return count;
}

// menu.
int List::menu(){
	int choice; 
	cout<<"\n================ menu ===================\n";
	cout<<"1. Them phan tu vao danh sach."<< endl;
	cout<<"2. Chen phan tu vao danh sach."<< endl;
	cout<<"3. Dem phan tu trong danh sach."<< endl;
	cout<<"4. Xuat danh sach."<< endl;
	cout<<"5. Dao danh sach."<< endl;
	cout<<"6. Kiem tra phan tu trong danh sach."<< endl;
	cout<<"7. Xoa phan tu trong danh sach."<< endl;
	cout<<"8. Sap xep danh sach tang dan."<< endl;
	cout<<"9. Sap xep danh sach giam dan."<< endl;
	cout<<"10.Xoa danh sach hien tai."<< endl;
	cout<<"0. Thoat chuong trinh."<< endl;
	cout<<"\n=========================================\n";
	cout<<"Chon chuc nang: "; cin>> choice;
	return choice;
}

// kiem tra rong.
bool List::empty(){
	return head == nullptr;
}

// kiem tra phan tu trong danh sach.
bool List::search(int x){
	node* p = head;
	while(p != nullptr){
		if(x == p->data){
			return true;
		}
		p = p->next;
	}
	return false;
}

// chen phan tu o dau danh sach.
void List::insertFirst(int x){
	node* temp = makeNode(x);
	if(head == nullptr){
		head = tail = temp;
	}else{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

// chen vao cuoi danh sach.
void List::insertLast(int x){
	node* temp = makeNode(x);
	if(head == nullptr){
		head = tail = temp;
	}else{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

// chen vao giua phan tu.
void List::insertMiddle(int x, int pos){
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"Vi tri chen khong hop le!!!"<< endl;
		return;
	}
	node* temp = makeNode(x);
	node* p = head;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	temp->next = p->next;
	p->next->prev = temp;
	p->next = temp;
	temp->prev = p;
}

// chen phan tu vao danh sach o vi tri bat ki.
void List::insert(int x, int pos){
	int n = length();
	if(pos == 1){
		insertFirst(x); return;
	}
	else if(pos == n + 1){
		insertLast(x); return;
	}
	insertMiddle(x, pos);
}

// xoa phan tu dau ra khoi danh sach.
void List::deleteFirst(){
	if(head == nullptr) return;
	if(head == tail) head = tail = nullptr; // trg hop con 1 node.
	else{
		head = head->next;
	    head->prev = NULL;
	}
}

// xoa phan tu o cuoi danh sach.
void List::deleteLast(){
	if(tail == NULL) return;
	node* p = head;
	if(head == tail) head = tail = nullptr;
	else{
		tail = tail->prev;
		tail->next = nullptr;
	}
}


// xoa phan tu o giua danh sach.
void List::deleteMiddle(int pos){
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"\nvi tri khong hop le!!!"<< endl;
	}
	node* p = head;
	node* temp = NULL;
	for(int i = 1; i < pos; i++){
		temp = p;
		p = p->next;
	}
	if(temp == NULL){
		head = head->next;
	}
	else{
		temp->next = p->next;
		p->next->prev = temp;
	}
}

// xoa phan tu trong danh sach.
void List::Delete(int pos){
	int n = length();
	if(pos == 1){
		deleteFirst(); return;
	}
	else if(pos == n){
		deleteLast(); return;
	}
	deleteMiddle(pos);
}

// xoa danh sach hien tai.
void List::deleteList(){
	if(head == nullptr) return;
	while(head->next != nullptr){
		head = head->next;
	}
	head = head->next;
}

// sap xep tang dan.
void List::AscendingSort(){
	for(node* p = head; p->next != nullptr; p = p->next){
		node* min = p;
		for(node* q = p->next; q != nullptr; q = q->next){
			if(q->data < min->data){
				min = q;
			}
		}
		swap(p->data, min->data);
	}
}


// sap xep giam dan.
void List::DescendingSort(){
	for(node* p = head; p->next != NULL; p = p->next){
		node* min = p;
		for(node* q = p->next; q != NULL; q = q->next){
			if(q->data > min->data){
			 min = q;
		    }
		}
		swap(p->data, min->data);
	}
}

// chuwong trinh chinh.
int main(){
	List a;
	int choice;
	
	do{
		choice = a.menu();
		switch(choice){
			case 1:
				int b;
			    cout<<"nhap phan tu: "; cin>> b;
			    a.insertLast(b);
			    break;
			
			case 2:
				int d,  pos;
				cout<<"nhap phan tu: "; cin>> d;
				cout<<"nhap vi tri can chen: "; cin>> pos;
				a.insert(d, pos);
				break;
				
			case 4:
				a.outPut();
				break;
				
			case 3:
				cout<<"\ntrong danh sach co "<< a.length() <<" phan tu"<< endl;
				break;
				
			case 5:
				a.reverse1();
				break;
				
			case 6:
				int x;
				cout<<"\nNhap phan tu: "; cin >>x;
				if(a.search(x)) cout<<"\nPhan tu ton tai trong danh sach."<< endl;
				else cout<<"\nPhan tu khong ton tai trong danh sach."<< endl;
				break;
				
			case 7:
				 int pos1;
				 cout<<"\nNhap vi tri: "; cin >> pos1;
				a.Delete(pos1);
				break;
				
			case 8:
				a.AscendingSort();
				break;
				
			case 9:
				a.DescendingSort();
				break;
				
			case 10:
				a.deleteList();
				cout<<"\nDanh sach xoa thanh cong"<< endl;
				break;
				
			case 0:
				cout<<"-----The end------";
				break;
				
			default:
				cout<<"Chuc nang khong hop le!!!"<< endl;
				break;
		}
	}while(choice != 0);
	
	return 0;
}
