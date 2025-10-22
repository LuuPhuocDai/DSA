#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

// node.
typedef struct Node{
	int data;
	Node* left;
	Node* right;
}node;

// lop binary tree.
class binaryTree{
	public:

		// ham cap phat dong.
		node* createNode(int x){
			node* temp = new Node();
			temp->data = x;
			temp->left = temp->right = NULL;
			return temp;
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
            root = NULL;
		}
};

// ke  thua binary tree.
class BST : public binaryTree{
    public:
        // chen theo quy tac BST.
        // tao quy tac chen BST.
        node* insertNodeBST(node* root, int x){
            if(root == NULL){
                root = binaryTree::createNode(x);
                return root;
            }

            if(x > root->data){
                root->right = insertNodeBST(root->right, x);
            }
            else{
                root->left = insertNodeBST(root->left, x);
            }
            return root;
        }

        // ham chen.
        void takeInPut(node* &root){
            
            // nut dau tien cua cay.
            int x;
            cout<<"Nhap gia tri cua nut(nhap -1 neu muon ket thuc): "; cin >> x;
            while(x != -1){// nhap tru neu ket thuc doan cay.
                root = insertNodeBST(root, x);
                cout<<"Nhap gia tri cua nut(nhap -1 neu muon ket thuc): "; cin >> x;
            }
        }

        // ham menu.
		int menu(){
			int choice;
			cout<<"\n================== menu =================\n";
			cout<<"0. Chen phan tu theo quy tac binary tree."<< endl;
			cout<<"1. Chen phan tu(BST)."<< endl;
			cout<<"2. Duyet cay theo NLR."<< endl;
			cout<<"3. Duyet cay theo LNR."<< endl;
			cout<<"4. Duyet cay theo LRN."<< endl;
			cout<<"5. Duyet cay theo level_Order."<< endl;
			cout<<"6. Tinh chieu cao cua cay."<< endl;
			cout<<"7. Dem so nut."<< endl;
			cout<<"8. Dem so nut la."<< endl;
			cout<<"9. Tim muc cua mot nut."<< endl;
			cout<<"10.Tinh tong gia tri cua cac nut"<< endl;
			cout<<"11.Tim max/min(BST)."<< endl;
            cout<<"12.Tim kiem phan tu(BST)."<< endl;
            cout<<"13.Xoa phan tu(BST)."<< endl;
            cout<<"14.Kiem tra tinh hop le cua BST."<< endl;
            cout<<"15.Tim successor va predecessor cua mot nut(BST)."<< endl;
            cout<<"16.Tim to tien chung thap nhat(BST)."<< endl;
            cout<<"17.Xoa toan bo cay."<< endl;
			cout<<"Thoat chuong trinh(an -1)."<< endl;
			cout<<"================== ==== =================\n";
			cout<<"Chon chuc nang: "; cin >> choice;
			return choice;
		}

        // tim kiem BST.
        bool search_BST(node* root, int x){
            if(root == nullptr){
                return false;
            }
            
            if(root->data == x){
                return true;
            }
            
            if(x < root->data){
                return search_BST(root->left, x);
            }else{
                return search_BST(root->right, x);
            }
        }
        

		// tim max/ min cua BST.
		node* maximumBST(node* root){
			node* max = root;
			while(max->right != NULL){
				max = max->right;
			}
			return max;
		}

		node* minimumBST(node* root){
			node* min = root;
			while(min->left != NULL){
				min = min->left;
			}
			return min;
		}

		// kiem tra tinh hop le cua BST.
		bool isBST(node* root){
			return is_valid_BST(root, INT_MIN, INT_MAX);
		}

		bool is_valid_BST(node* root, int minBst, int maxBst){
			if(root == NULL){
				return true;
			}
			// kiem tra xem co phai BST khong.
			if(maxBst <= root->data || minBst >= root->data){
				return false;
			}
			//
			bool left = is_valid_BST(root->left, minBst, root->data);
			bool right = is_valid_BST(root->right, root->data, maxBst);
			if(left == true && right == true){
				return true;
			}
			else{
				return false;
			}
		}

		// tim ke nhiem va tien nhiem cua mot nut.
		void inOder_pre_suc(node* root, int x, node* &pre, node* &suc){
			if(root == nullptr){
				return;
			}
			// cang tang dan
			if(x > root->data && (pre == nullptr || pre->data < root->data)){
				pre = root;
			}
			// cang giam dan.
			if(x < root->data && (suc == nullptr || suc->data > root->data)){
				suc = root;
			}
			// de quy.
			inOder_pre_suc(root->left, x, pre, suc);
			inOder_pre_suc(root->right, x, pre, suc);
		}

		// dung vector de luu gia tri pre va suc.
		vector<node*> find_pre_suc(node* root, int x){
			node* pre = nullptr;
			node* suc = nullptr;
			inOder_pre_suc(root, x, pre, suc);
			return {pre, suc};
		}
		
		// xuat ham tien va ke nhiem.
		void print_PreSuc(node* root, int x){
			vector<node*> result = find_pre_suc(root, x);
			node* pre = result[0];
			node* suc = result[1];
			// in pre.
			if(pre != nullptr){
				cout<< pre->data << " ";
			}
			else{
				cout<<"NULL ";
			}
			// in suc.
			if(suc != nullptr){
				cout<< suc->data <<" ";
			}
			else{
				cout<<"NULL ";
			}
		}
		
		// xoa phan tu.
		node* deleteNode(node* root, int x){
			if(root == nullptr){
				return root;
			}
			
			if(x == root->data){
			    // truong hop khong co con(0 child).
			    if(root->left == nullptr && root->right == nullptr){
			    	delete root;
			    	return NULL;
				}
				
				// truong hop co 1 con.
				// con ben trai.
				else if(root->left != nullptr && root->right == nullptr){
					node* temp = root->left;
					delete root;
					return temp;
				}
				
				// con ben phai.
				if(root->right != nullptr && root->left == nullptr){
					node* temp = root->right;
					delete root;
					return temp;
				}
				// truong hop co 2 con.
				if(root->left != nullptr && root->right != nullptr){
					int min = minimumBST(root->right)->data;
					root->data = min;
					root->right = deleteNode(root->right, min);
					return root;
				}
			}
			// de quy.
			else if(x < root->data){
				root->left = deleteNode(root->left, x);
				return root;
			}
			else{
				root->right = deleteNode(root->right, x);
				return root;
			}
		}
		
		// tim to tien chung thap nhat.
		node* LCA(node* root, int n1, int n2){
			if(root == nullptr){
				return nullptr;
			}
			if(root->data == n1 || root->data == n2){
				return root;
			}
			
			node* leftLCA = LCA(root->left, n1, n2);
			node* rightLCA = LCA(root->right, n1, n2);
			
			if(leftLCA && rightLCA){
				return root;
			}
			
			return leftLCA ? leftLCA : rightLCA;
		}
		
};

// chuong trinh chinh.
int main(){
	BST a;

    // khoi tao.
    node* root = NULL;

    // chon chuc nang
	int choice;
	do{
		choice = a.menu();
		switch(choice){
			case -1:
				a.Delete_Tree(root);
				cout<<"\n -- the end --";
                break;
			
			case 1:
				cout<<"\n-----Tao cay theo quy tac BST-----"<< endl;
				a.Delete_Tree(root);
				a.takeInPut(root);
                cout<<"cap nhap cay thanh cong!";
				cout<<"\n-----------------"<< endl;
				break;

			case 0:
				cout<<"\n-----Tao cay binary tree-----"<< endl;
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
			    cout<<"\nGia tri lon nhat la: " << a.maximumBST(root)->data << endl;
			    cout<<"Gia tri nho nhat la: " << a.minimumBST(root)->data << endl;
				break;

            case 12:
                cout<<"\nTim kiem gia tri cua nut:\n";
                int x;
                cout<<"Nhap gia tri: "; cin >> x;
                if( a.search_BST(root, x)) cout<<"Gia tri ton tai trong cay."<< endl;
                else cout<<"Gia tri khong ton tai trong cay!!!"<< endl;
                break;
                
            case 13:
            	cout<<"\nXoa nut."<< endl;
            	int b;
            	cout<<"Nhap gia tri: "; cin >> b;
            	cout<<"xoa thanh cong!"<< endl;
            	a.deleteNode(root, b);
            	break;

			case 14:
			    cout<<"\nKiem tra tinh hop le cua BST."<< endl;
				if(a.isBST(root)){
					cout<<"La cay nhi phan tim kiem"<< endl;
				}
				else{
					cout<<"Khong phai la cay nhi phan tim kiem!!!"<< endl;
				}
				
				break;

			case 15:
		        int data;
				cout<<"\nTim tien va ke nhiem cua mot nut."<< endl;
				cout<<"Nhap gia tri: "; cin >> data;
			    cout<<"Tien nhiem va ke nhiem cua "<< data << " lan luoc la: ";
				a.print_PreSuc(root, data);				
				break;
				
			case 16:
			    int n1, n2;
				cout<<"\nTim to tien chung thap nhat."<< endl;
				cout<<"Nhap n1: "; cin >> n1;
				cout<<"Nhap n2: "; cin >> n2;
				cout<<"To tien chung thap nhat cua "<< n1 <<" va "<< n2<< " la "<< a.LCA(root, n1, n2)->data<< endl;
                break;
                
            case 17:
            	a.Delete_Tree(root);
            	cout<<"\nCay da xoa!"<< endl;
            	root = nullptr;                                                                                                                                                                                                                
            	break;

			default:
				cout<<"\nLua chon khong co trong menu!!!"<< endl;
				break;
		}
		
	}while(choice != -1);
	return 0;
}