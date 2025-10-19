#include "iostream"

using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}node;

class List{
	public:
		node* head;
		node* tail;
		
		// khoi tao.
		List();
		
		// dem phan tu trong ds.
		int length();
		
		// cap phat dong.
		node *makeNode(int x);
		
		// them phan tu vao danh sach.
		void insertFirst(int x); // dau danh sach.
		void insertLast(int x); // cuoi ds.
		void insertMiddle(int x, int pos);// giua ds.
		void insert(int x, int pos); // chen vi tri bat ki.

		// xuat danh sach.
		void print();
		
		// menu.
		int menu();
		
		// ktra rong.
		bool empty();
		
		// tim kiem.
		bool search(int x);
		
		// xoa phan tu ra khoi ds.
		void deleteFirst(); // dau
		void deleteLast(); // cuoi.
		void deleteMiddle(int pos); // giua.
		void Delete(int pos);// bat ki.
		void deleteList();
		
		// sap xep.
		void AscendingSort(); // tang dan.
		void DescendingSort(); // giam dan.
		
		// max va min.
		void Maximum();
		void Minimum();
};

// khoi tao.
List ::List(){
	head = NULL;
	tail = nullptr;
}

// cap phat dong bo nho.
node* List::makeNode(int x){
	node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	return temp;
}

// dem trong danh sch co bao nhieu phan tu.
int List::length(){
	int count = 0;
	node* p = head;
	while(p != NULL){
		count++;
		p = p->next;
	}
	return count;
}

// kiem tra rong.
bool List::empty(){
	return head == NULL;
}

// xuat danh sach.
void List::print(){
	node* i = head;
	int count = 1;
	cout<< endl <<"====== danh sach ======"<< endl;
	cout<<"STT\tGia Tri"<< endl;
	while(i != NULL){
		cout << count << " \t  " << i->data << endl;
		i = i->next;
		count++;
	}
	cout<< endl <<"======================="<< endl;
}

// tim kiem.
bool List::search(int x){
	node* p = head;
	while(p != nullptr){
		if(p->data == x){
			return true;
		}
		    p = p->next;
	}
	return false;
}

// menu.
int List::menu(){
	int choice;
	cout<< endl <<"========= menu ========"<< endl;
	cout<<"1. Them phan tu vao danh sach."<< endl;
	cout<<"2. Chen phan tu vao danh sach."<< endl;
	cout<<"3. Xuat danh sach."<< endl;
	cout<<"4. Dem phan tu trong danh sach."<< endl;
	cout<<"5. Xoa phan tu trong danh sach."<< endl;
	cout<<"6. Tim kiem phan tu trong danh sach."<< endl;
	cout<<"7. Sap xep tang dan."<< endl;
	cout<<"8. Sap xep giam dan."<< endl;
	cout<<"9. Gia tri lon nhat."<< endl;
	cout<<"10.Gia tri nho nhat."<< endl;
	cout<<"11.xoa danh sach hien tai."<< endl;
	cout<<"0. Thoat."<< endl;
	cout<< endl <<"========================"<< endl;
	cout<<"Nhap lua chon cua ban: "; cin>> choice;
	return choice;
}

// them phan tu vao dau danh sach.
void List::insertFirst(int x){
	node* temp = makeNode(x);
	if(head == NULL){
		head = temp;
	}
	else{
		temp->next = head;
		head = temp;
	}
}

// them phan tu vao cuoi danh sach.
void List::insertLast(int x){
	node* temp = makeNode(x);
	if(head == NULL){
		head = temp;
	}
	else{
		tail = head;
		while(tail->next != nullptr){
			tail = tail->next;
		}
		tail->next = temp;
	}
}


// them phan tu vao giua danh sach.
void List::insertMiddle(int x, int pos){
	node* temp = makeNode(x);
	node* ptr = head;
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"Lua chon khong hop le!!!"<< endl;
		return;
	}
	if(ptr == nullptr){
		ptr = temp;
	}
	for(int i = 1; i < pos - 1 && ptr != nullptr; i++){
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

// chen phan tu o vi tri bat ki.
void List::insert(int x, int pos){
	int n = length();
	if(pos == 1){
		insertFirst(x); return;
	}
	else if(pos == n){
		insertLast(x); return;
	}
	insertMiddle(x, pos); 
}

// xoa dau danh sach.
void List::deleteFirst(){
	if(head == NULL) return;
	node* p = head;
	head = p->next;
	delete(p);
}

// xoa cuoi danh sach.
void List::deleteLast(){
	if(head == nullptr) return;
	node *p = head;
	while(p->next != nullptr){
		tail = p;
		p = p->next;
	}
	if(tail == nullptr) head = nullptr;
	else tail->next = nullptr;
	delete(p);
}


// xoa phan tu o giua ds.
void List::deleteMiddle(int pos){
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"Vi tri khong hop le!!!"<< endl;
		return;
	}
	node* temp = NULL;
	node* p = head;
	for(int i = 1; i < pos; i++){
		temp = p;
		p = p->next;
	}
	if(temp == NULL){
		head = head->next;
	}
	else{
		temp->next = p->next;
	}
}

// xoa o vi tri bat ki.
void List::Delete(int pos){
	int n = length();
	if(n == 1){
		deleteFirst(); return;
	}
    else if(pos == n){
		deleteLast(); return;
	}
	deleteMiddle(pos);
}

// xoa danh sach hien tai.
void List::deleteList(){
	if(head == NULL) return;
	while(head->next != nullptr){
		head = head->next;
	}
	head = head->next;
	cout<<"\nDanh sach da duoc xoa."<< endl;
}

// sap xep tang.
void List::AscendingSort(){ // selection sort.
	for(node* p = head; p->next != nullptr; p = p->next){
		node* min = p;
		for(node* q = p->next; q != nullptr; q = q->next){
			if(q->data < min->data){
				min = q;
			}
			swap(p->data, min->data);
		}
	}
}

// sap xep giam.
void List::DescendingSort(){ // selection sort.
	for(node* p = head; p->next != nullptr; p = p->next){
		node* min = p;
		for(node* q = p->next; q != nullptr; q = q->next){
			if(q->data > min->data){
				min = q;
			}
			swap(p->data, min->data);
		}
	}
}

// gia tri lon nhat.
void List::Maximum(){
	DescendingSort();
	node* max = head;
	cout<<"\nGia tri lon nhat trong danh sach: "<< max->data << endl; // =)))
}

// gia tri nho nhat.
void List::Minimum(){
	AscendingSort();
	node* min = head;
	cout<<"\nGia tri nho nhat trong danh sach: "<< min->data << endl; // =)))
}

// ham main.
int main(){
	List a;
	int choice;

	do{
		choice = a.menu();
		switch(choice){
			case 0:
				cout<<"\nThe end"<< endl;
				break;
				
			case 1:
				int c;
				cout<<"Nhap phan tu muon them: "; cin>> c;
				a.insertLast(c);
				break;
				
			case 2:
				int d, pos;
				cout<<"Nhap phan tu ban muon them: "; cin>> d;
				cout<<"Vi tri ban muon chen: "; cin>> pos;
				a.insert(d, pos);
				break;
				
			case 3:
				a.print();
				break;
				
			case 4:
				cout<<"\nTrong danh sach co "<< a.length() <<" phan tu."<< endl;
				break;
				
			case 5:
				int pos1;
				cout<<"Nhap vi tri ban muon xoa: "; cin>> pos1;
				a.Delete(pos1);
				break;
				
			case 6:
				int pos2;
				cout<<"\nNhap phan tu ban muon tim kiem: "; cin>> pos2;
				if(a.search(pos2)) cout<<"\nPhan tu co trong danh sach."<< endl;
				else cout<<"\nPhan tu khong ton tai trong danh sach!!!."<< endl;
				break;
			
			case 7:
				a.AscendingSort();
				break;
				
			case 8:
				a.DescendingSort();
				break;
				
			case 9:
				a.Maximum();
				break;
				
			case 10:
				a.Minimum();
				break;

			case 11:
			    a.deleteList();
				break;
				
			default:
				cout<<"\nLua chon khong hop le!!!"<< endl;
				break;
				
		}
	}while(choice != 0);
	return 0;
}