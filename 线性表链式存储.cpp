#include<iostream>
using namespace std;
typedef struct lnode{ //lnode结构体里面包含data数据域和next指针域
  int data;
  lnode *next;
}lnode; //lnode---->等价于struct lnode
class linklist{
  lnode *head;//定义一个结构体头指针
  public:
    linklist();//初始化链式表
    void initlist(int n);//输入数据
    void print();//输出数据
    void insertlist(int pos,int e);
    void deletelist(int pos,int &e);
    int locatex(int x);
    int countnode();
};
linklist::linklist(){
  head=new lnode;//给lnode型指针head赋一个lnode结构体，使head拥有data和next指针
  head->next=NULL;
}
/*
void linklist::initlist(int n){  //头插法
  lnode *p;
  for(int i=0;i<n;i++){
    p=new lnode;//给lnode型指针p赋一个lnode结构体，使head拥有data和next指针
    cin>>p->data;
    p->next=head->next;
    head->next=p;
  }
}
*/
void linklist::initlist(int n){  //尾插法
  lnode *p,*s;
  s=head;
  cout<<"输入数据：";
  for (int i = 0; i < n; i++){
    p=new lnode;
    cin>>p->data;
    p->next=s->next;
    s->next=p;
    s=p;//重点
  }
}
  
int linklist::locatex(int x){ //查找函数
  lnode *p=head->next;
  while(p){
    if(p->data==x)return 1;
    p=p->next;
  }
  return 0;
}
void linklist::insertlist(int pos,int e){  //插入函数 
  int j=0;
  lnode *p=head;
  while(p&&j<pos-1){p=p->next;j++;}
  if(!p||j>pos-1)return  ;
  lnode *s=new lnode;
  s->data=e;
  s->next=p->next;
  p->next=s;
}
void linklist::deletelist(int pos,int &e){
  int j=0;lnode *p=head;
  while(p->next&&j<pos-1){p=p->next;j++;}
  if(!p->next||j>pos-1)return;
  lnode *q=p->next;//p的下一个数据域和next指针赋值给q
  p->next=q->next;
  e=q->data;
  cout<<"已删除第"<<pos<<"位数据:"<<e;
  delete q;
}
  int linklist::countnode(){
     lnode *p=head->next;//p=head;
     int count=0;
     while(p){
      if(p->data%2==0)count++; 
      p=p->next;      
    }
     return count;
   }
void linklist::print(){
    lnode *p=head->next;
    while(p){
      cout<<p->data<<' ';
      p=p->next;
    }
    cout<<endl;
}
int main(void){
   linklist l;
   l.initlist(5);
   l.print();
   l.insertlist(3,100);
   l.print();
   int e;
   l.deletelist(4,e);
   cout<<endl;
   cout<<l.locatex(3);
   return 0;
  }
  