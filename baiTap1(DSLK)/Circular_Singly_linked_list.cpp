#include "iostream"

using namespace std;

typedef struct Node{
	int data;
	Node *next;
	
	Node(int val){
		data = val;
		next = nullptr;
	}
}node;

// classs.
class List{
	public:
		// khoi tao.
	    node* tail;
	    node* head;
	    List();
	
	    // xuat danh sach.
	    void Print();
	    
	    // menu.
	    int menu();
	    
	    // kiem tra phan tu.
	    bool search(int x);
	    
	    // dem phan tu trong danh sach.
	    int length();
        
        // chen phan tu vao danh sach.
        void insertFirst(int x);
        void insertLast(int x);
        void insertMiddle(int x, int pos);
        void insert(int x, int pos);
        
        // xoa phan tu trong danh sach.
        void removeFirst();
        void removeLast();
        void removeMiddle(int pos);
        void Delete(int pos);
        void deleteList();
        
        // sap xep phan tu.
        void AscendingSort();
        void DescendingSort();
};

// khoi tao.
List::List(){
	tail = nullptr;
	head = NULL;
}


// xuat danh sach.
void List::Print(){
	if(head == nullptr) return;
	node* i = head;
	int count = 2;
	cout<<"\n============ Danh sach ==============\n";
	cout<<"STT\tGia Tri"<< endl;
	cout <<"1\t  "<< i->data << endl;
	i = i->next;
	while(i != head){
		cout<< count <<"\t  "<< i->data<< endl;
		i = i->next;
		count++;
	}
	cout<<"\n=====================================\n";
}

// dem phan tu trong ds.
int List::length(){
	int count = 0;
	if(head == nullptr){
		return count;
	}
	node* p = head;
	p = p->next;
	count++;
	while(p != head){
		count++;
		p = p->next;
	}
	return count;
}

// kiem tra phan tu trong ds.
bool List::search(int x){
	node* p = head;
	if(x == p->data){
		return true;
	}
	p = p->next;
	while(p != head){
		if(x == p->data){
			return true;
		}
		p = p->next;
	}
	return false;
}

// menu.
int List::menu(){
	int choice;
	cout<<"\n============== menu ===============\n";
	cout<<"1. Them phan tu vao ds.."<< endl;
	cout<<"2. Chen phan tu vao ds."<< endl;
	cout<<"3. Xoa phan tu"<< endl;
	cout<<"4. xuat ds."<< endl;
	cout<<"5. dem phan tu trong ds."<< endl;
	cout<<"6. Kiem tra phan tu trong ds."<< endl;
	cout<<"7. sap xep tang."<< endl;
	cout<<"8. sap xep giam."<< endl;
	cout<<"9. Xoa ds hien tai."<< endl;
	cout<<"0. thoat."<< endl;
	cout<<"\n===================================\n";\
	cout<<"nhap lua chon: "; cin >> choice;
	return choice;
}

// chen pan tu vao dau danh sach.
void List::insertFirst(int x){
	node* temp = new Node(x);
	if(head == nullptr){
		head = tail = temp;
		tail->next = head;
	}else{
		temp->next = head;
		head = temp;
		tail->next = head;
	}
}

// chen phan tu vao cuoi ds.
void List::insertLast(int x){
	node* temp = new Node(x);
	if(head == nullptr){
		head = tail = temp;
		tail->next = head;
	}else{
		tail->next = temp;
		tail = temp;
		tail->next = head;
	}
}

// chen phan tu vao giua ds.
void List::insertMiddle(int x, int pos){
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"\nVi tri chen khong hop le!!!"<< endl;
		return;
	}
	
	// chen phan tu giua ds.
	node* temp = new Node(x);
	node* p = head;
	for(int i = 1; i < pos - 1; i++){
		p =p->next;
	}	
	temp->next = p->next;
	p->next = temp;
}

// chen.
void List::insert(int x, int pos){
	int n = length();
	if(pos == 1){
		insertFirst(x); return;
	}
	else if(pos == n){
		insertLast(x); return;
	}
	else if(n == 0){
		insertLast(x); return;
	}
	insertMiddle(x, pos);
}

// xoa phan tu dau cua ds.
void List::removeFirst(){
	if(head == NULL) return;
	else{
		head = head->next;
	    tail->next = head;
	}
}

// xoa pha tu cuoi ds.
void List::removeLast(){
	if(head == NULL) return;
	else{
		node* p = head;
		while(p->next != tail ){
			p = p->next;
		}
		delete tail;
		p->next = head;
		tail = p;
	}
}

// xoa phan tu giua ds.
void List::removeMiddle(int pos){
	int n = length();
	if(pos <= 0 || pos > n + 1){
		cout<<"\nVi tri khong hop le!!"<< endl;
		return;
	}
	node* p = head;
	node* temp = nullptr;
	for(int i = 1; i < pos; i++){
		temp = p;
		p = p->next;
	}
	temp->next = p->next;
}

// xoa.
void List::Delete(int pos){
	int n = length();
	if(pos == 1){
		removeFirst(); return;
	}
	else if(pos == n){
		removeLast(); return;
	}
	
	removeMiddle( pos);
}

// xoa danh sach hien tai.
void List::deleteList(){
	if(head == nullptr) return;
	node* p = head;
	node* temp;
	while(p != head){
		temp = p;
		p = p->next;
		delete temp;
	}
	head = tail = nullptr;
}
  
// sap xep tang.
void List::AscendingSort(){
	 for(node* p = head; p->next != head; p = p->next){
	 	node* min = p;
	 	for(node* q = p->next; q != head; q = q->next){
	 		if(min->data > q->data){
	 			min = q;
			 }
		 }
		 swap(p->data, min->data);
	 }
}

// sap xep giam.
void List::DescendingSort(){
	 for(node* p = head; p->next != head; p = p->next){
	 	node* min = p;
	 	for(node* q = p->next; q != head; q = q->next){
	 		if(min->data < q->data){
	 			min = q;
			 }
		 }
		 swap(p->data, min->data);
	 }
}

int main(){
	List a;
	int choice;
	do{
		choice = a.menu();
		switch(choice){
			case 1:
				int c;
				cout<<"nhap phan tu: "; cin >> c;
				a.insertLast(c);
				break;
				
			case 2:
				int d, pos;
				cout<<"nhap phan tu: "; cin >> d;
				cout<<"nhap vi tri: "; cin >> pos;
				a.insert(d, pos);
				break;
				
		    case 3:
		    	int pos1;
		    	cout<<"Nhap vi tri: "; cin >> pos1;
		        a.Delete(pos1);
		    	break;
			
			case 4:
				a.Print();
				break;
				
			case 5:
				cout<<"\nTrong ds co " << a.length() <<" phan tu"<< endl;
				break;
				
			case 6:
				int x;
				cout<<"nhap phan tu: "; cin >> x;
				if(a.search(x)) cout<<"\nTrong ds co ton tai phan tu "<< x << endl;
				else cout<<"\nTrong ds khong ton tai phan tu "<< x << endl;
				break;
				
			case 7:
				a.AscendingSort();
				cout<<"\nDs da duoc sap xep tang dan."<< endl;
				break;
				
			case 8:
				a.DescendingSort();
				cout<<"\nDs da duoc sap xep giam dan."<< endl;
				break;

			case 9:
			    a.deleteList();
				break;
				
			case 0:
				cout<<"-the end-"<< endl;
				break;
			
			default:
				cout<<"lua chon khong hop le vui long chon lai."<< endl;
				break;
		}
	}while(choice != 0);
	return 0;
}