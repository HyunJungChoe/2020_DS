////정병재 강사 //5555555@daum.net //010-8976-9600
#pragma warning (disable:4996) //최신표준문법이 아닌
                               //예전문법 사용 가능
#include<stdio.h>
#include<stdlib.h> //유틸리티
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
void counting(Tree* p) {//재귀함수를 이용한 함수 콜스택
    if (p != NULL)
    {
        tree_count++;
        counting(p->left);
        counting(p->right);
    }
}
void preorder(Tree* p) {//재귀함수를 이용한 함수 콜스택
    if (p != NULL)
    {
        printf("%d ", p->key);
        preorder(p->left);
        preorder(p->right);
    }
}
void preorder2(Tree* p)
{
    //스택에 push
    push(p);
    //스택이 비어있지 않으면 pop
    while(stack_empty())//if () //stack_empty()는 비어있으면 0을 리턴
    {
        Tree* k=pop();//pop한 데이터를 출력
        printf("%d ", k->key);
        if (k->right != NULL) //pop한 노드의 오른쪽자식과 왼쪽자신 순으로 push push한다.
            push(k->right);
        if (k->left != NULL)
            push(k->left);
    }
}

void inorder(Tree* p) { //tree sort (왼쪽자식은 작고 오른자식은 크다)
    if (p != NULL)
    {        
        inorder(p->left);
        printf("%d ", p->key);
        inorder(p->right);
    }
}
void inorder2(Tree* p) { //tree sort (왼쪽자식은 작고 오른자식은 크다)
      //root를 스택에 push()
    //222
    //push()한 노드의 왼쪽자식을 계속 push한다.(NULL or tail)
    //NULL or tail을 만나면 스택에서 pop 하고 출력
    //pop한 녀석의 오른쪽자식을  push()하고 222로 반복
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
    //tree 데이터를 추가하다보면 샤향 이진트리가 만들어진다.
    //전체적으로 균형이 잡히지 않는 tree가 생성될수 있다.

    //1. 균형이 깨졌는지 확인(좌우측 서브트리의 depth 차, 
       //                     개수(노드의 총개수) 대비 depth)

    //2. 수동으로 균형잡힌 이진트리를 재구축

    //3. 처음부터 균형이진트리에 넣는다.(자동:RB-tree, AVL-tree, 234-tree)


    preorder(&c);//전위
    puts("");
    init_stack();
    preorder2(&c); //우리가 만든 스택을 이용한 전위순회
    puts("");

    inorder(&c);//중위
    puts("");
    inorder2(&c);//중위
    puts("");
    postorder(&c);//후위 - 비재귀 후위 순회를 어려워서 못한다.
    puts("");

    //levelorder(&c);//층별

    printf("depth : %d\n", tree_depth(&c, 0)) ;
    printf("left depth : %d\n", tree_depth(c.left, 1));//c의 왼쪽
    printf("right depth : %d\n", tree_depth(c.right, 1));//c의 오른쪽

    int t_depth = tree_depth(&c, 0);
    int total = 15;// pow(2, (double)(t_depth + 1)) - 1;
    counting(&c);

    printf("트리의 깊이는 %d\n최대요소 수용량 %d\n현재노드의 수%d\n\
당신의 사용량%f %%입니다.\n", t_depth, total, tree_count, (float)6 / 15 * 100);

    //균형잡힌 이진트리로 만들어야 한다.


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
//    front = rear; //차있는곳 = 비어있는곳
//}
//void put(int data)
//{
//    if (rear + 1 == front)
//    {
//        puts("queue overflow");
//        return;// void함수를 그냥 종료 할 때
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
//   // put(5); //overflow발생 5는 안들어간다.
//    printf("%d ", get()); //1
//    printf("%d ", get()); //2
//    printf("%d ", get()); //3
//    put(5); //rear가 5가 될텐데.. 이때 0이되도록 해야 환형큐가 된다.
//    printf("rear : %d\n", rear);//0이 출력
//    put(6);    put(7);
//    put(8); //queue overflow 이 발생 해야 한다.
//    printf("%d ", get()); //4
//    printf("%d ", get()); //5 오빠 지겠네
//    printf("%d ", get()); //6
//    printf("%d ", get()); //7
//    printf("%d ", get()); //queue empty를 발생
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







//구조체
//품목 단가 판매량  총액
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
//	puts("1. 매출현황 출력");
//	puts("2. 매출현황 내보내기");
//	puts("3. 상품 찾기");
//	puts("4. 상품 삭제");
//	puts("5. 매출현황 배열");
//	puts("6. 정렬");
//	puts("7. 종료");
//	puts("==================== =");
//    int sel;
//    scanf("%d", &sel);
//    return sel;
//      
//}
//void insert_list(char* in, int ip)
//{
//    Item* nw;
//    nw = (Item*)malloc(sizeof(Item));//만든노드에
//    strcpy(nw->i_name, in); //품명복사
//    nw->i_price = ip; //품가 복사
//
//    nw->next = head->next;//head의 뒤쪽에 넣어주네..
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
//    if (wk != tail) //찾았다는 의미 : 업데이트(판매대수, 총액)
//    {
//        wk->i_count = sc; //판매대수
//        wk->i_amount = wk->i_price * sc; //총액
//    }
//    else
//    {
//        puts("없는 품목");
//    }
//}
//main()
//{
//    int sel;
//    init_item(); //초기화
//    //item.txt을 모두 읽어 링크드 리스트 만들기
//    FILE* fr;
//    char iname[20];
//    int iprice;
//    fr = fopen("item.txt", "r");
//    while (1) {
//        if (fscanf(fr, "%s %d", iname, &iprice) == -1)
//            break;        
//        insert_list(iname, iprice);//하나씩 노드생성
//        //printf("%s %d\n", iname, iprice);
//    }
//    fclose(fr);
//    //view_list();
//    //sales.txt을 읽어서 기존의 링크에 update
//    char sname[20];
//    int scount;
//    fr = fopen("sales.txt", "r");
//    while (1) {
//        if (fscanf(fr, "%s %d", sname, &scount) == -1)
//            break;
//        //item을 읽어서 만든 리스트 목록에 
//        //같은 아이템명을 찾아서 해당 노드를 업데이트
//        find_and_update(sname, scount);//품목, 팔린개수
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
///*  노드 추가 */
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
//    /*  노드 5개 추가 */
//    for (i = 0; i < 5; i++) //이 반복문이 3번 도는 경우까지의 
//    {                       //메모리 모양 그리기
//        NewNode = CreateNode(i);
//        AppendNode(&List, NewNode);
//    }
//}


//
////더블링크드 리스트를
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
//	while (grn->next->key < data && grn->next != tail) //다음숫자가 나보다 크거나 tail를 만나지 않았다면
//	{
//		grn = grn->next; //넣고자 하는 값(data)보다 기존값이 작으면 옆으로 옯기겠다
//	}
//	//nw의 key값보다 큰 숫자를 만나거나 tail을 만났을때 while탈출!
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
//    //내부적으로 cmp_i나 cmp_s를 호출한다 //결과는 -1(음수), 0, 1(양수)을 리턴한다.
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
//    qsort(k, 3, sizeof(node*), cmp_node);//범용함수
//
//    puts("\n-----");
//    printf("%s\n", k[0]->name);
//    printf("%s\n", k[1]->name);
//    printf("%s\n", k[2]->name);
//
//}


//다음 구조체를 라이브러리 qsort를 상용하여 itemname의 오름차순으로 정렬하시오
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
////라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
//int comp_d(const void* a, const void* b) {
//    if (*(double*)a > * (double*)b)   //a-b //4.5-4.3
//        return 1;
//    else if (*(double*)a < *(double*)b)
//        return -1;
//    else
//        return 0;
//}
//
////라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
//int comp_s(const void* a, const void* b) {
//
//    return strcmp((char*)a, (char*)b);
//    //const void* a; //a로 값을 못 바꾼다.
//    //void const* a; //a로 값을 못 바꾼다.
//    //void* const a; //a에 다른 주소를 못 넣는다.
//}
//
//
//int main(void) {
//    int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
//    double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5 };
//    char arrs[][7] = { "임창민","박주헌","송지섭","박기웅",
//  "조인희","박소연","류시우","최현정",
//  "이경호","최성훈","김수현" };
//    qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
//    printInt(arri, sizeof(arri) / sizeof(arri[0]));
//
//    qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
//    printDbl(arrd, sizeof(arrd) / sizeof(arrd[0]));
//
//    //라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.
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
//        //pivot보다 큰값을 찾는 구문 //큰값의 index를 big에 넣고 나가기
//        while (arr[++big] <= pivot);
//        //printf("%d ", arr[big]);//4출력
//
//        //pivot 보다 작거나 같은 값을 찾는 구문
//        while (arr[--small] > pivot);
//       // printf("%d ", arr[small]);//2출력
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
//    struct _list* next;//자기참조 구조체
//};
//List* head, * tail;//전역변수로
////모든 자료구조는 초기화가 필요 (빨래기둥 + 줄)
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
//	while (wk->key != fd && wk != tail) //찾는 녀석이 끝기둥을 만나지 않았다면
//	{
//		wk = wk->next; //옆으로 가겠다.
//	}
//    //while문 아래로 있다를 출력하는 코드 !!!
//	if (wk == tail) //wk가 끝까지 가봤다.
//		puts("없다.");
//    else //끝까지 안감
//        printf("%d %s\n", wk->key, "있다.");
//
//    //찾으면 "있다."
//    //없으면 "없다." 출력
//    //List* wk = head->next;
//    //while (wk != tail) //찾는 녀석이 끝기둥을 만나지 않았다면
//    //{
//    //    if (wk->key == fd)
//    //    {
//    //        printf("%d %s\n", fd, "있다.");
//    //        break;
//    //    }
//    //    wk = wk->next; //옆으로 가겠다.
//    //}
//    //if (wk == tail)
//    //    puts("없다.");
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
//    while (grn->next->key<data && grn->next!=tail)//tail을 만나지 않았다면
//    {   //넣고자하는값(data)보다  기존값이 작으면
//        //옆으로 옮기겠다.
//        grn = grn->next;
//    }
//    //while이 실패 이유 , 크거나, tail을 만났을 때
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
//    while (three->key != cd && three != tail) //옆으로가겠다.
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
//    //찾고
//    while (three->key != fd && three != tail) //옆으로가겠다.
//    {
//        two = two->next; //three의 앞노드
//        three = three->next;
//    }
//    //넣기
//    two->next = three->next;
//    three->next=head->next;
//    head->next = three;
//
//}
//main()
//{
//    init_list(); //초기화 함수 호출
//
//    ordered_insert(3);
//    ordered_insert(4);
//    ordered_insert(1);
//    ordered_insert(5);
//    ordered_insert(2);  //1 2 3 4 5
//    view_list();
//    //숫자를 선택
//    int select=3;
//    transfermethod(select); //1 3 2 4 5
//    view_list();
//    select = 5;
//    movetofront(select);
//    view_list();
//    //insert_list(3); //새 노드 3을 넣기(첫번째 빨래)
//    //insert_list(2);
//    //insert_list(1);
//
//    ////널린 빨래 확인
//    //view_list(); // 1-> 2 -> 3
//
//    //delete_list();  
//    //puts("\n-------");
//    //view_list(); // 2 -> 3
//
//    //find_list(3);
//
//    //delete_all_list();  //모두 삭제
//    //                    //free하기 전에 옆칸의 주소를 기억해야 한다.
//    //puts("\n-------");
//    //view_list(); //출력 없음
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