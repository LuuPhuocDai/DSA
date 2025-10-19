#include <iostream>
#include <queue>
using namespace std;

// node.
typedef struct Node{
	int data;
	Node* left;
	Node* right;
}node;

// lop binary tree.
class tree{
	public:

		// ham cap phat dong.
		node* createNode(int x){
			node* temp = new Node();
			temp->data = x;
			temp->left = temp->right = NULL;
			return temp;
		}
		
		// ham menu.
		int menu(){
			int choice;
			cout<<"\n================== menu =================\n";
			cout<<"1. Tao cay."<< endl;
			cout<<"2. Duyet cay theo NLR."<< endl;
			cout<<"3. Duyet cay theo LNR."<< endl;
			cout<<"4. Duyet cay theo LRN."<< endl;
			cout<<"5. Duyet cay theo level_Order."<< endl;
			cout<<"6. Tinh chieu cao cua cay."<< endl;
			cout<<"7. Dem so nut."<< endl;
			cout<<"8. Dem so nut la."<< endl;
			cout<<"9. Tim muc cua mot nut."<< endl;
			cout<<"10.Tinh tong gia tri cua cac nut"<< endl;
			cout<<"11.Xoa toan bo cay."<< endl;
			cout<<"0. Thoat"<< endl;
			cout<<"================== ==== =================\n";
			cout<<"Chon chuc nang: "; cin >> choice;
			return choice;
		}
		
		// ham tao cay.
		node* buildTree(node* root){
			int x;
			cout<<"nhap gia tri: "; cin >> x;
			root = createNode(x);
			
			// doan ket thuc cua cay con.
			if(x == -1){
				return NULL;
			}
			
			// nhap tiep phan con cau cay.
			// nhap trai.
			cout<<"cay con cua nut ben trai (nhap -1 neu cay khong con con) cua "<< x << endl;
			root->left = buildTree(root->left);
			
			// nhap phai.
			cout<<"cay con cua nut ben phai (nhap -1 neu cay khong con con) cua "<< x << endl;
			root->right = buildTree(root->right);
			return root;
		}
		
		// ham xuat theo NLR
		void pre_Order(node* root){
			if(root == NULL){
				return;
			}
			cout<< root->data << " ";
			pre_Order(root->left);
			pre_Order(root->right);
		}
		
		// ham xuat theo LNR.
		void in_Order(node* root){
			if(root == NULL){
				return;
			}
			in_Order(root->left);
			cout<< root->data << " ";
			in_Order(root->right);
		}
		
		// ham xuat theo LRN.
		void post_Order(node* root){
			if(root == NULL){
				return;
			}
			post_Order(root->left);
			post_Order(root->right);
			cout<< root->data << " ";
		}
		
		// ham xuat theo level Order.
		void level_Order_traversal(node* root){
			if(root == NULL){
				cout<<"Cay rong!"<< endl;
				return;
			}
			queue<node*> p;
			p.push(root);
			p.push(NULL);
			
			// duyet cay.
			while(!p.empty()){
				node* temp = p.front();
				p.pop();
				
				if(temp == NULL){
					cout<< endl;
					if(!p.empty()){
						p.push(NULL);
					}
				}
				else{	
					cout<< temp->data <<" ";
				    if(temp->left){
					    p.push(temp->left);
				    }
				    if(temp->right){
					    p.push(temp->right);
				    }
				}
			}
        }

        // ham tinh chieu cao cua cay.
		int height(node* root){
			if(root == NULL){
				return 0;
		    }
			int count = 0;   
            queue<node*> q;
            q.push(root);
            q.push(NULL);
            
            while(!q.empty()){
            	node* temp = q.front();
            	q.pop();
            	
            	if(temp == NULL){
            		count++;
            		if(!q.empty()){
            			q.push(NULL); 
					}
				}
				else {
					if(temp->left){
						q.push(temp->left);
					}
					if(temp->right){
						q.push(temp->right);
					}
				}
			}
			return count;
        }

        // ham dem so nut.
        int count_Total_Nodes(node* root){
            if(root == NULL){
                return 0;
            }
            return 1 + count_Total_Nodes(root->left) + count_Total_Nodes(root->right);
        }

        // ham dem so nut la tren cay.
        int count_Leaf_Nodes(node* root){
            if(root == nullptr){
                return 0;
            }
            else if(root->left == nullptr && root->right == nullptr){
                return 1;
            }
            return count_Leaf_Nodes(root->left) + count_Leaf_Nodes(root->right);
        }

        // ham tinh tong gia tri cac nut.
        int sum_Of_Node_Values(node* root){
            if(root == NULL){
                return 0;
            }
            return root->data + sum_Of_Node_Values(root->left) + sum_Of_Node_Values(root->right);
        }
        
        // ham tim muc cua mot nut.
        void find_Depth_Level(node* root){
        	if(root == nullptr){
        		cout<<"Cay rong!"<< endl;
        		return;
        	}
        	
        	// nhap gia tri nut can tim.
        	int x;
        	cout<<"Nhap gia tri nut: "; cin >> x;
        	
            queue<node*> q;
			q.push(root);
			int level = 0;
			
			while(!q.empty()){
				int size = q.size();
				
				for(int i = 0; i < size; ++i){
					node* temp = q.front();
					q.pop();
					
					if(x == temp->data){
						cout<< x <<" dang o level "<< level << endl;
						return;
					}
					
					if(temp->left){
						q.push(temp->left);
					}
					if(temp->right){
						q.push(temp->right);
					}
				}
				level++;
			}
			cout<<"Nut khong ton tai trong cay!!!"<< endl;	
		}
		
		// xoa toan bo cac nut hien tai.
		void Delete_Tree(node* root){
			if(root == nullptr) return;
			Delete_Tree(root->left);
			Delete_Tree(root->right);
			delete(root);
			root = nullptr;
		}
};

// chuong trinh chinh.
int main(){
	tree a;
	
	// khoi tao.
	node* root = NULL;
	
	// chon chuc nang
	int choice;
	do{
		choice = a.menu();
		switch(choice){
			case 0:
				a.Delete_Tree(root);
				cout<<"\n -- the end --";
                break;
			
			case 1:
				cout<<"\n-----Tao cay-----"<< endl;
				a.Delete_Tree(root);
				root = a.buildTree(root);
                cout<<"cap nhap cay thanh cong!";
				cout<<"\n-----------------"<< endl;
				break;
				
			case 2:
				cout<< "\nDuyet theo NLR: ";
				a.pre_Order(root);
				cout<< endl;
				break;
				
			case 3:
				cout<< "\nDuyet theo LNR: ";
				a.in_Order(root);
				cout<< endl;
				break;
				
			case 4:
				cout<< "\nDuyet theo LRN: ";
				a.post_Order(root);
				cout<< endl;
				break;
				
			case 5:
				cout<<"\nDuyet theo level Order:"<< endl;
				a.level_Order_traversal(root);
				break;
				
			case 6:
				cout<<"\nChieu cao cua cay: "<< a.height(root) << endl;
				break;
				
            case 7:
                cout<<"\nSo nut cay la: "<< a.count_Total_Nodes(root) << endl;
                break;

            case 8:
                cout<<"\nSo nut la tren cay la: "<< a.count_Leaf_Nodes(root) << endl;
                break;
                
            case 9:
            	cout<<"\nTim level cua nut: ";
            	a.find_Depth_Level(root);
            	break;

            case 10:
                cout<<"\nTong gia tri cua cac nut la: "<< a.sum_Of_Node_Values(root) << endl;
                break;
                
            case 11:
            	a.Delete_Tree(root);
            	cout<<"\nCay da xoa!"<< endl;
            	root = nullptr;                                                                                                                                                                                                                
            	break;

			default:
				cout<<"\nLua chon khong co trong menu!!!"<< endl;
				break;
		}
		
	}while(choice != 0);
	
	return 0;
}