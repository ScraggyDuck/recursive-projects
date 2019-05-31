#include<iostream>
using namespace std;

//Khai bao cay tim kiem
struct TNode{
	int data;
	TNode *pLeft, *pRight;
};

typedef TNode *TREE;

//Khoi tao cay
void init(TREE &root){
	root = NULL;
}

//Tao node
TNode* createNode(int x){
    TNode *p = new TNode;
    if(p == NULL) return NULL;
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

//Them phan tu vao cay
void insert(TREE &t, int x){
    TNode *p = createNode(x);
    if(t == NULL)
        t = p;
    else{
        if(x > t->Data)
            insertTREE(t->pRight, x);
        else if(x < t->Data)
            insertTREE(t->pLeft, x);
    }
}

//NodeLeftRight
void output_TLR(TREE &t){
    if(t != NULL){
        cout << t->data << " ";
        otput_NLR(t->pLeft);
        output_NLR(t->pRight);
    }
}

//RightNodeLeft
void output_RTL(TREE &t){
    if(t != NULL){
        output_RNL(t->pRight);
        cout << t->data << " ";
        output_RNL(t->pLeft);
    }
}

void replace(TREE &p, TREE &t) {
    if (t->pLeft != NULL)
            replace(p, t->pLeft);
    else{
        p->data = t->data; // Gán giá trị xóa = giá trị thay thế
        p = t; // Gán node cần xóa thành node thế mạng
        t = t->pRight; //Xóa node thế mạng, có 2 trường hợp
        /*
        vì Node thế mạng là node bên trái ngoài cùng của nhánh bên phải nên chỉ xử lí con trỏ bên phải
        trường hợp 1: k có node bên phải - > gán bằng null
        trường hợp 2: giống như xóa 1 node có nhánh con bên phải
        */
    }
}

void deleteNodeX(TREE &t, int x) {
    if (t != NULL){
        if (t->data < x) deleteNodeX(t->pRight, x);
        else{
            if (t->data > x) deleteNodeX(t->pLeft, x);
            else { //tim thấy Node có trường dữ liệu = x
                TNode *p;
                p = t;
                if (t->pLeft == NULL) t = t->pRight;
                else {
                        if (t->pRight == NULL) t = t->pLeft;
                        else replace(p, t->pRight); // tìm bên cây con phải
                }
            delete p;
            }
        }
    }
}

bool search(TREE &t, int x){
    if(t == NULL)
        return false;
    else if(t->data == x)
        return true;
    else if(t->data > x)
        search(t->pLeft, x);
    else if (t->data < x)
        search(t->pRight);
}

void freeTree(TREE &t ){
    if (t == NULL)
        return;
    freeTree(t->pLeft);
    freeTree(t->pRight);
    delete t;
}

int main(){
	TREE T;
	init(T);
	int lc, key, keySearch, keyDelete;
		do {
		system("cls");
		cout << "===============================================\n";
		cout << "===============CAY NHI PHAN TIM KIEM===============\n";
		cout << "\n1. Them 1 node vao cay";
		cout << "\n2. Xuat cay theo thu tu TLR";
		cout << "\n3. Xuat cay theo thu tu RTL";
		cout << "\n4. Tim kiem node";
		cout << "\n5. Xoa mot node";
		cout << "\n0. Ket thuc!";
		cout << "\n===============================================\n\n";
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc){
            case 0:
                break;
            case 1:
                cout << "\nNhap du lieu node them vao: ";
                cin >> key;
                insertTree(T, key);
                break;
            case 2:
                output_TLR(T);
                break;
            case 3:
                output_RTL(T);
                break;
            case 4:
                cout << "\nNhap du lieu node can tim kiem: ";
                cin >> keySearch;
                if(search(T, keySearch) == true)
                    cout << "\nTim thay du lieu!\n"
                else
                    cout << "\nKhong tim thay du lieu!\n";
                break;
            case 5:
                cout << "\nNhap du lieu node can tim xoa: ";
                cin >> keyDelete;
                deleteNodeX(T, keyDelete);
                break;
            default:
                cout << "Lua chon khong hop le!\n";
                break;
            system("pause");
        }
	} while (lc != 0);
    FreeTREE(root);
	return 0;
}
