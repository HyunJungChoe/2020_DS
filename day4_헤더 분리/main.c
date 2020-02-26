////������ ���� //5555555@daum.net //010-8976-9600
#pragma warning (disable:4996) //�ֽ�ǥ�ع����� �ƴ�
                               //�������� ��� ����
#include<stdio.h>
#include<stdlib.h> //��ƿ��Ƽ
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define swap(a,b)  do{int t;t=a;a=b;b=t;}while(0)
#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>

int tree_count = 0;

#include "queue.h"s
#include "stack.h"
void counting(Tree* p) {//����Լ��� �̿��� �Լ� �ݽ���
    if (p != NULL)
    {
        tree_count++;
        counting(p->left);
        counting(p->right);
    }
}
void preorder(Tree* p) {//����Լ��� �̿��� �Լ� �ݽ���
    if (p != NULL)
    {
        printf("%d ", p->key);
        preorder(p->left);
        preorder(p->right);
    }
}
void preorder2(Tree* p)
{
    //���ÿ� push
    push(p);
    //������ ������� ������ pop
    while(stack_empty())//if () //stack_empty()�� ��������� 0�� ����
    {
        Tree* k=pop();//pop�� �����͸� ���
        printf("%d ", k->key);
        if (k->right != NULL) //pop�� ����� �������ڽİ� �����ڽ� ������ push push�Ѵ�.
            push(k->right);
        if (k->left != NULL)
            push(k->left);
    }
}

void inorder(Tree* p) { //tree sort (�����ڽ��� �۰� �����ڽ��� ũ��)
    if (p != NULL)
    {        
        inorder(p->left);
        printf("%d ", p->key);
        inorder(p->right);
    }
}
void inorder2(Tree* p) { //tree sort (�����ڽ��� �۰� �����ڽ��� ũ��)
      //root�� ���ÿ� push()
    //222
    //push()�� ����� �����ڽ��� ��� push�Ѵ�.(NULL or tail)
    //NULL or tail�� ������ ���ÿ��� pop �ϰ� ���
    //pop�� �༮�� �������ڽ���  push()�ϰ� 222�� �ݺ�
    while (1)    {
        while (p != NULL)        {
            push(p);
            p = p->left; //t=t->next;
        }
        if (stack_empty())        {
            p = pop();
            printf("%d ", p->key);
            p = p->right;
        }
        else
            break;
    }
}

void postorder(Tree* p) {
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->key);
	}
}
void level_order(Tree* p)
{
    put(p);
    while (queue_empty())
    {
        p = get();
        printf("%d\n", p->key);
        if (p->left != NULL)
            put(p->left);
        if (p->right != NULL)
            put(p->right);
    }
}
int tree_depth(Tree* p, int dep)
{
    int l_dep, r_dep;
    l_dep = r_dep = dep; //l=r=0

    if (p->left != NULL)
        l_dep = tree_depth(p->left, l_dep + 1);
    if (p->right != NULL)
        r_dep = tree_depth(p->right, r_dep + 1);

    if (l_dep >= r_dep)
        return l_dep;
    else
        return r_dep;
}
main()
{
    Tree a = { 1,NULL, NULL }, b = { 2,NULL, NULL },
         c = { 3,NULL, NULL }, d = { 4,NULL, NULL }, 
         e = { 5,NULL, NULL }, f = { 6,NULL, NULL };

    c.left = &a; //          c(3) ----------------- 0
    a.right = &b;//     a(1)       d(4) ----------- 1
    c.right = &d;//        b(2)         f(6) ------ 2
    d.right = &f;//                  e(5)       --- 3
    f.left = &e;//
    //tree �����͸� �߰��ϴٺ��� ���� ����Ʈ���� ���������.
    //��ü������ ������ ������ �ʴ� tree�� �����ɼ� �ִ�.

    //1. ������ �������� Ȯ��(�¿��� ����Ʈ���� depth ��, 
       //                     ����(����� �Ѱ���) ��� depth)

    //2. �������� �������� ����Ʈ���� �籸��

    //3. ó������ ��������Ʈ���� �ִ´�.(�ڵ�:RB-tree, AVL-tree, 234-tree)


    preorder(&c);//����
    puts("");
    init_stack();
    preorder2(&c); //�츮�� ���� ������ �̿��� ������ȸ
    puts("");

    inorder(&c);//����
    puts("");
    inorder2(&c);//����
    puts("");
    postorder(&c);//���� - ����� ���� ��ȸ�� ������� ���Ѵ�.
    puts("");

    //levelorder(&c);//����

    printf("depth : %d\n", tree_depth(&c, 0)) ;
    printf("left depth : %d\n", tree_depth(c.left, 1));//c�� ����
    printf("right depth : %d\n", tree_depth(c.right, 1));//c�� ������

    int t_depth = tree_depth(&c, 0);
    int total = 15;// pow(2, (double)(t_depth + 1)) - 1;
    counting(&c);

    printf("Ʈ���� ���̴� %d\n�ִ��� ���뷮 %d\n�������� ��%d\n\
����� ��뷮%f %%�Դϴ�.\n", t_depth, total, tree_count, (float)6 / 15 * 100);

    //�������� ����Ʈ���� ������ �Ѵ�.


    level_order(&c);
}







//#define QUEUE_SIZE 5    
//int Queue[QUEUE_SIZE];
//int front, rear;
//
//void init_queue(void){
//    front = rear = 0;
//}
//void clear_queue(void) {
//    front = rear; //���ִ°� = ����ִ°�
//}
//void put(int data)
//{
//    if (rear + 1 == front)
//    {
//        puts("queue overflow");
//        return;// void�Լ��� �׳� ���� �� ��
//    }
//    Queue[rear++] = data;
//    //if (rear == 5)
//    //    rear = 0;
//    rear = rear % 5;
//}
//int get(void)
//{
//    int save;
//    if (front == rear)
//    {
//        puts("queue empty");
//        return -1;
//    }
//    save = front;
//    front = ++front % 5;
//    return Queue[save];
//    
//}
//main()
//{
//    init_queue();
//    put(1);    put(2);    put(3);    put(4);
//   // put(5); //overflow�߻� 5�� �ȵ���.
//    printf("%d ", get()); //1
//    printf("%d ", get()); //2
//    printf("%d ", get()); //3
//    put(5); //rear�� 5�� ���ٵ�.. �̶� 0�̵ǵ��� �ؾ� ȯ��ť�� �ȴ�.
//    printf("rear : %d\n", rear);//0�� ���
//    put(6);    put(7);
//    put(8); //queue overflow �� �߻� �ؾ� �Ѵ�.
//    printf("%d ", get()); //4
//    printf("%d ", get()); //5 ���� ���ڳ�
//    printf("%d ", get()); //6
//    printf("%d ", get()); //7
//    printf("%d ", get()); //queue empty�� �߻�
//}

//#define STACK_SIZE 5    
//int Stack[STACK_SIZE];
//int top;
//void init_stack(void){
//    top = -1;// top=0;
//}
//void push(int data){
//    if (top >= STACK_SIZE - 1)    {
//        puts("stack overflow");
//        return;
//    }
//    Stack[++top] = data;
//}
//int pop(void){
//    if (top <= -1)
//    {
//        puts("stack underflow");
//        return -1;
//    }
//    return Stack[top--];
//}
//main()
//{
//    init_stack();  push(3); push(2); push(1);
//    printf("%d\n", pop());
//    printf("%d\n", pop());
//    printf("%d\n", pop());
//    printf("%d\n", pop());
//}
//







//����ü
//ǰ�� �ܰ� �Ǹŷ�  �Ѿ�
//i_name i_price i_count i_amount
//
//typedef struct _item {
//    char i_name[20];
//    int i_price;
//    int i_count;
//    int i_amount;
//    struct _item* next;
//}Item;
//Item* head, * tail;
//
//void init_item(void)
//{
//    head = (Item*)malloc(sizeof(Item));
//    tail = (Item*)malloc(sizeof(Item));
//    head->next = tail;
//}
//int menu_select(void)
//{
//	puts("==== = M E N U  ==== =");
//	puts("1. ������Ȳ ���");
//	puts("2. ������Ȳ ��������");
//	puts("3. ��ǰ ã��");
//	puts("4. ��ǰ ����");
//	puts("5. ������Ȳ �迭");
//	puts("6. ����");
//	puts("7. ����");
//	puts("==================== =");
//    int sel;
//    scanf("%d", &sel);
//    return sel;
//      
//}
//void insert_list(char* in, int ip)
//{
//    Item* nw;
//    nw = (Item*)malloc(sizeof(Item));//�����忡
//    strcpy(nw->i_name, in); //ǰ����
//    nw->i_price = ip; //ǰ�� ����
//
//    nw->next = head->next;//head�� ���ʿ� �־��ֳ�..
//    head->next = nw;
//}
//void view_list(void)
//{
//    Item* wk;
//    wk = head->next;
//    while (wk != tail)
//    {
//        printf("%s %d\n", wk->i_name, wk->i_price);
//        wk = wk->next;
//    }
//}
//void view_list2(void)
//{
//    Item* wk;
//    wk = head->next;
//    while (wk != tail)
//    {
//        printf("%20s %7d", wk->i_name, wk->i_price);
//        printf("%7d %7d\n", wk->i_count, wk->i_amount);
//        wk = wk->next;
//    }
//}
//void find_and_update(char *sn, int sc)
//{
//    Item* wk;
//    wk = head->next;
//
//    while (strcmp(wk->i_name, sn)!=0 && wk != tail) {
//        wk = wk->next;
//    }
//    if (wk != tail) //ã�Ҵٴ� �ǹ� : ������Ʈ(�ǸŴ��, �Ѿ�)
//    {
//        wk->i_count = sc; //�ǸŴ��
//        wk->i_amount = wk->i_price * sc; //�Ѿ�
//    }
//    else
//    {
//        puts("���� ǰ��");
//    }
//}
//main()
//{
//    int sel;
//    init_item(); //�ʱ�ȭ
//    //item.txt�� ��� �о� ��ũ�� ����Ʈ �����
//    FILE* fr;
//    char iname[20];
//    int iprice;
//    fr = fopen("item.txt", "r");
//    while (1) {
//        if (fscanf(fr, "%s %d", iname, &iprice) == -1)
//            break;        
//        insert_list(iname, iprice);//�ϳ��� ������
//        //printf("%s %d\n", iname, iprice);
//    }
//    fclose(fr);
//    //view_list();
//    //sales.txt�� �о ������ ��ũ�� update
//    char sname[20];
//    int scount;
//    fr = fopen("sales.txt", "r");
//    while (1) {
//        if (fscanf(fr, "%s %d", sname, &scount) == -1)
//            break;
//        //item�� �о ���� ����Ʈ ��Ͽ� 
//        //���� �����۸��� ã�Ƽ� �ش� ��带 ������Ʈ
//        find_and_update(sname, scount);//ǰ��, �ȸ�����
//        //printf("%s %d\n", sname, scount);
//    }
//    fclose(fr);
//    view_list2();
//    while (1) {
//        sel = menu_select();
//    }
//
//}
//









//typedef int ElementType;
//
//typedef struct tagNode
//{
//    ElementType Data;
//    struct tagNode* PrevNode;
//    struct tagNode* NextNode;
//} Node;
//Node* CreateNode(ElementType NewData)
//{
//    Node* NewNode = (Node*)malloc(sizeof(Node));
//
//    NewNode->Data = NewData;
//    NewNode->PrevNode = NULL;
//    NewNode->NextNode = NULL;
//
//    return NewNode;
//}
//
//
//
///*  ��� �߰� */
//void AppendNode(Node * *Head, Node * NewNode){
//
//    if ((*Head) == NULL){
//        *Head = NewNode;
//        (*Head)->NextNode = *Head;
//        (*Head)->PrevNode = *Head;
//    }    else    {
//
//        Node* Tail = (*Head)->PrevNode;
//
//        Tail->NextNode->PrevNode = NewNode;
//        Tail->NextNode = NewNode;
//
//        NewNode->NextNode = (*Head);
//        NewNode->PrevNode = Tail;
//    }
//}
//int main(void)
//{
//    int   i = 0;
//    Node* List = NULL;
//    Node* NewNode = NULL;
//
//    /*  ��� 5�� �߰� */
//    for (i = 0; i < 5; i++) //�� �ݺ����� 3�� ���� �������� 
//    {                       //�޸� ��� �׸���
//        NewNode = CreateNode(i);
//        AppendNode(&List, NewNode);
//    }
//}


//
////����ũ�� ����Ʈ��
//
//typedef struct _list List;
//
//struct _list {
//	int key;
//	struct _list* prev;
//	struct _list* next;
//};
//List* head, * tail;
//
//void init_list(void)
//{
//	head = (List*)malloc(sizeof(List));
//	tail = (List*)malloc(sizeof(List));
//
//	head->next = tail;
//	head->prev = head;
//	tail->prev = head;
//	tail->next = tail;
//}
//
//void view_list(void)
//{
//	List* wk = head;
//	while (wk->next != tail) {
//		printf("%d ", wk->next->key);
//		wk = wk->next;
//	}
//}
//
//
//
//void insert(int data)
//{
//	List* grn, * nw;
//	grn = head;
//	while (grn->next->key < data && grn->next != tail) //�������ڰ� ������ ũ�ų� tail�� ������ �ʾҴٸ�
//	{
//		grn = grn->next; //�ְ��� �ϴ� ��(data)���� �������� ������ ������ ����ڴ�
//	}
//	//nw�� key������ ū ���ڸ� �����ų� tail�� �������� whileŻ��!
//	nw = (List*)malloc(sizeof(List));
//	nw->key = data;
//
//	nw->next = grn->next;
//	grn->next->prev = nw;
//	grn->next = nw;
//	nw->prev = grn;
//	//nw->next = grn->next;
//	//nw->prev = grn->prev;
//	//nw->prev->next = nw;
//	//grn->next->prev = nw;
//}
//
//void del(int a)
//{
//	List* k;
//	k = head->next;
//	while (k->key != a && k != tail)
//	{
//		k = k->next;
//	}
//	k->prev->next = k->next;
//	k->next->prev = k->prev;
//	free(k);
//}
//
//void main(void)
//{
//	init_list();
//
//	insert(2);
//	insert(9);
//	insert(7);
//	insert(1);
//	insert(4);
//
//	view_list();
//	puts("----------------");
//	del(4);
//	view_list();
//
//}

//main()
//{
//    printf("%c%c\n", -80, -95);
//    printf("%c%c\n", -56, -2);
//}
//typedef    int (*FCMP)(const void*, const void*);
//int cmp_i(const void* p, const void* k)
//{
//
//}
//
//int cmp_s(const void* p, const void* k)
//{
//
//}
//void* func(void* base, size_t num, size_t width, FCMP fcmp){
//
//    //���������� cmp_i�� cmp_s�� ȣ���Ѵ� //����� -1(����), 0, 1(���)�� �����Ѵ�.
//    printf("%d\n", fcmp()); //1000000 - 3  /aaaa aaaa  - 0
//
//}
//main(){
//    int a[5] = { 10000000,3,1,5,2 };
//    char b[10][10] = { "aaaa","aaaa" };
//    func(a, 5, sizeof(int), cmp_i);
//    func(b, 2, sizeof(b[0]), cmp_s);
//}
//
//typedef struct _node node;
//struct _node {
//    char name[10];
//    struct _node* next;
//};
////int gg = 0;
//int cmp_node(const void* a, const void* b)
//{
//    return strcmp((*(node**)a)->name, (*(node**)b)->name);
//}
//node* p, * q;
//main()
//{
//    node* k[4];
//
//    p = (node*)malloc(sizeof(node));
//    strcpy(p->name, "ccc");
//    p->next = NULL;
//    q = (node*)malloc(sizeof(node));
//    strcpy(q->name, "aaa");
//    q->next = NULL;
//
//
//    k[0] = p;
//    k[1] = q;
//    k[2] = (node*)malloc(sizeof(node));
//    strcpy(k[2]->name, "bbb");
//    printf("%s\n", k[0]->name);
//    printf("%s\n", k[1]->name);
//    printf("%s\n", k[2]->name);
//    puts("=====================");
//    qsort(k, 3, sizeof(node*), cmp_node);//�����Լ�
//
//    puts("\n-----");
//    printf("%s\n", k[0]->name);
//    printf("%s\n", k[1]->name);
//    printf("%s\n", k[2]->name);
//
//}


//���� ����ü�� ���̺귯�� qsort�� ����Ͽ� itemname�� ������������ �����Ͻÿ�
//typedef struct _sales
//{
//	char itemname[20];
//	int unitprice;
//	int count;
//	int amount;
//}Sales;
//int prd_item(const void* a, const void* b)
//{
//	return strcmp(((Sales*)a)->itemname, ((Sales*)b)->itemname);
//}
//main()
//{
//	Sales prd[5] = {
//	 { "ccc", 10,90,900 },
//	{ "aaa", 20,80,1600 },
//	{ "ddd", 30,70,2100 },
//	{ "eee", 40,60,2400 },
//	{ "bbb", 50,50,2500 }
//	};
//	Sales* p = prd;
//	puts(p->itemname);
//
//	void* v = prd;
//	puts(((Sales *)p)->itemname);
//
//
//	int dx;
//
//	qsort(prd, 5, sizeof(prd[0]), prd_item);
//
//
//	for (dx = 0; dx < 5; dx++)
//		printf("%s %d %d %d\n", prd[dx].itemname,
//			prd[dx].unitprice, prd[dx].count, prd[dx].amount);
//
//
//}
//void printInt(int* arr, int size);
//void printDbl(double* arr, int size);
//void printstr(char(*arr)[7], int size);
//
//int comp_i(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
////���̺귯�� �����ϴ� qsort�� ���� comp_d �Լ� �ϼ�
//int comp_d(const void* a, const void* b) {
//    if (*(double*)a > * (double*)b)   //a-b //4.5-4.3
//        return 1;
//    else if (*(double*)a < *(double*)b)
//        return -1;
//    else
//        return 0;
//}
//
////���̺귯�� �����ϴ� qsort�� ���� comp_s �Լ� �ϼ�
//int comp_s(const void* a, const void* b) {
//
//    return strcmp((char*)a, (char*)b);
//    //const void* a; //a�� ���� �� �ٲ۴�.
//    //void const* a; //a�� ���� �� �ٲ۴�.
//    //void* const a; //a�� �ٸ� �ּҸ� �� �ִ´�.
//}
//
//
//int main(void) {
//    int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
//    double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5 };
//    char arrs[][7] = { "��â��","������","������","�ڱ��",
//  "������","�ڼҿ�","���ÿ�","������",
//  "�̰�ȣ","�ּ���","�����" };
//    qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
//    printInt(arri, sizeof(arri) / sizeof(arri[0]));
//
//    qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
//    printDbl(arrd, sizeof(arrd) / sizeof(arrd[0]));
//
//    //���̺귯�� qsort�� �̿��Ͽ� 2�����迭�� �ִ� ���ڿ��� �����սô�.
//
//    qsort(arrs, sizeof(arrs) / sizeof(arrs[0]), sizeof(arrs[0]), comp_s);
//    printstr(arrs, sizeof(arrs) / sizeof(arrs[0]));
//
//    return 0;
//}
//void printInt(int* arr, int size) {
//    int dx = 0;
//    for (dx = 0; dx < size; ++dx) {
//        printf("%d ", arr[dx]);
//    }
//    printf("\n");
//}
//
//void printDbl(double* arr, int size) {
//    int dx = 0;
//    for (dx = 0; dx < size; ++dx) {
//        printf("%.1f  ", arr[dx]);
//    }
//    printf("\n");
//}
//
//void printstr(char(*arr)[7], int size) {
//    int dx = 0;
//    for (dx = 0; dx < size; ++dx) {
//        printf("%s ", arr[dx]);
//    }
//    printf("\n");
//}




//int partition(int arr[], int s, int e)
//{
//    int big, small, pivot;
//    big = s;
//    small = e + 1;
//    pivot = arr[big];
//    while (big < small) {
//        //pivot���� ū���� ã�� ���� //ū���� index�� big�� �ְ� ������
//        while (arr[++big] <= pivot);
//        //printf("%d ", arr[big]);//4���
//
//        //pivot ���� �۰ų� ���� ���� ã�� ����
//        while (arr[--small] > pivot);
//       // printf("%d ", arr[small]);//2���
//
//        if (big < small) {
//            swap(arr[big], arr[small]);
//        }
//    }
//    swap(arr[s], arr[small]);
//    return small;
//}
//void qsort(int arr[], int s, int e)
//{
//    int mid;
//    if (s < e) {
//        mid = partition(arr, s, e);
//        qsort(arr, s, mid - 1);
//        qsort(arr, mid + 1, e);
//    }
//}
//main(){
//    int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
//    qsort(arri, 0, 9);
//    int dx;
//    for (dx = 0; dx < 10; dx++)    {
//        printf("%d ", arri[dx]);
//    }
//
//}


//
//struct engine {
//    int piston;
//    int fan;
//    int pipe;
//};
//struct car {
//    struct engine* sedan, * sports;
//};
//void hyundai(struct car* man)
//{
//    struct engine* p = man->sedan;
//    p->piston = 50;
//    p->fan = 30;
//    p->pipe = 20;
//}
//void main()
//{
//    struct car hi;
//    hi.sedan = (struct engine*)malloc(sizeof(struct engine));
//    hyundai(&hi);
//    printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan, hi.sedan->pipe);
//}

//
//
//typedef struct _list List;
//struct _list {
//    int key;
//    struct _list* next;//�ڱ����� ����ü
//};
//List* head, * tail;//����������
////��� �ڷᱸ���� �ʱ�ȭ�� �ʿ� (������� + ��)
//void init_list(void)
//{
//    head = (List*)malloc(sizeof(List));
//    tail = (List*)malloc(sizeof(List));
//    head->next = tail;
//    tail->next = tail;
//}
//void insert_list(int data)
//{
//    List* nw;
//    nw = (List*)malloc(sizeof(List));
//    nw->key = data;
//
//    nw->next = head->next;
//    head->next = nw;
//}
//void view_list(void)
//{
//    List* wk = head->next;
//    while (wk!=tail) {
//        printf("%d ", wk->key);
//        wk = wk->next;
//    }
//    //List* wk;
//    //wk = head->next;
//    //printf("%d\n", wk->key);
//    //wk = wk->next;
//    //printf("%d\n", wk->key);
//    //wk = wk->next;
//    //printf("%d\n", wk->key);
//}
//void delete_list(void)
//{
//    List* del;
//    del = head->next;
//    head->next = del->next;
//    free(del);
//}
//void find_list(int fd)
//{
//	List* wk = head->next;
//	while (wk->key != fd && wk != tail) //ã�� �༮�� ������� ������ �ʾҴٸ�
//	{
//		wk = wk->next; //������ ���ڴ�.
//	}
//    //while�� �Ʒ��� �ִٸ� ����ϴ� �ڵ� !!!
//	if (wk == tail) //wk�� ������ ���ô�.
//		puts("����.");
//    else //������ �Ȱ�
//        printf("%d %s\n", wk->key, "�ִ�.");
//
//    //ã���� "�ִ�."
//    //������ "����." ���
//    //List* wk = head->next;
//    //while (wk != tail) //ã�� �༮�� ������� ������ �ʾҴٸ�
//    //{
//    //    if (wk->key == fd)
//    //    {
//    //        printf("%d %s\n", fd, "�ִ�.");
//    //        break;
//    //    }
//    //    wk = wk->next; //������ ���ڴ�.
//    //}
//    //if (wk == tail)
//    //    puts("����.");
//}
//void delete_all_list(void)
//{
//    List* kill, * fkill;
//    kill = head->next;
//
//    while (kill != tail)
//    {
//        fkill = kill;
//        kill = kill->next;
//        free(fkill);
//    }
//
//    head->next = tail;
//}
//void ordered_insert(int data)
//{
//    List* grn;
//    grn = head;
//
//    while (grn->next->key<data && grn->next!=tail)//tail�� ������ �ʾҴٸ�
//    {   //�ְ����ϴ°�(data)����  �������� ������
//        //������ �ű�ڴ�.
//        grn = grn->next;
//    }
//    //while�� ���� ���� , ũ�ų�, tail�� ������ ��
//    List* nw = (List*)malloc(sizeof(List));
//    nw->key = data;
//
//    nw->next = grn->next;
//    grn->next = nw;
//
//    //nw->next = head->next;
//    //head->next = nw;
//}
//
//void transfermethod(int cd)
//{
//    List* three, * two, * one;
//    two = one = head;
//    three = head->next;
//    while (three->key != cd && three != tail) //�����ΰ��ڴ�.
//    {
//        one = two;
//        two = two->next;
//        three = three->next;
//    }
//    two->next = three->next;
//    three->next = two;
//    one->next = three;
//}
//void movetofront(int fd)
//{
//    List* three, *two;
//    two = head;
//    three = head->next;
//    //ã��
//    while (three->key != fd && three != tail) //�����ΰ��ڴ�.
//    {
//        two = two->next; //three�� �ճ��
//        three = three->next;
//    }
//    //�ֱ�
//    two->next = three->next;
//    three->next=head->next;
//    head->next = three;
//
//}
//main()
//{
//    init_list(); //�ʱ�ȭ �Լ� ȣ��
//
//    ordered_insert(3);
//    ordered_insert(4);
//    ordered_insert(1);
//    ordered_insert(5);
//    ordered_insert(2);  //1 2 3 4 5
//    view_list();
//    //���ڸ� ����
//    int select=3;
//    transfermethod(select); //1 3 2 4 5
//    view_list();
//    select = 5;
//    movetofront(select);
//    view_list();
//    //insert_list(3); //�� ��� 3�� �ֱ�(ù��° ����)
//    //insert_list(2);
//    //insert_list(1);
//
//    ////�θ� ���� Ȯ��
//    //view_list(); // 1-> 2 -> 3
//
//    //delete_list();  
//    //puts("\n-------");
//    //view_list(); // 2 -> 3
//
//    //find_list(3);
//
//    //delete_all_list();  //��� ����
//    //                    //free�ϱ� ���� ��ĭ�� �ּҸ� ����ؾ� �Ѵ�.
//    //puts("\n-------");
//    //view_list(); //��� ����
//
//}








//
//
//
//
//
//
////int ala(int a, int b){
////    int mul=0;
////    while(a){// (a > 0)    {
////        if (a&0x1) //((a&0x1)==1)//(a % 2 == 1)
////            mul += b;
////        a >>= 1;//a = a / 2;
////        b <<= 1;//b = b * 2;
////    }
////    return mul;
////}
////#define swap(a,b) do{int t;t=a;a = b;b = t; }while(0)
////int gcd(int a, int b)
////{
////    while (a)    {
////        if (b > a)
////            swap(a, b);
////        a -= b;
////    }
////    return b;
////}
////int gcd2(int a, int b)
////{
////    while (b) {
////        a %=  b;
////        swap(a, b);
////    }
////    return a;
////}
////main()
////{
////    printf("%d\n", ala(27, 65));
////    printf("%d\n", gcd2(220, 30));
////}