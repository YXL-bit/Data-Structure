#include<iostream>
using namespace std;
typedef struct lnode{
	int data;
	lnode *next;
}lnode;
class linklist{
    lnode *head;
    public:
    
    linklist();
    void Union(linklist *&,linklist *&);//并集
    void Inter(linklist *&,linklist *&);//交集
    void initlist();
    void print();
};
linklist::linklist(){
	head=new lnode;
	head->next=NULL;
}
void linklist::initlist(){
    lnode *s=head,*p;
    int n1;
    cout<<"你想输入几个数据：";
    cin>>n1;
    cout<<"输入数据:";
    for(int i=0;i<n1;i++){
        p=new lnode;
        cin>>p->data;
        p->next=s->next;
        s->next=p;
        s=p;
    }
}
void linklist::print(){
    lnode *p=head->next,*q;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
void linklist::Union(linklist *&ha,linklist *&hb){
    lnode *pc=head;
    lnode *q;
    lnode *pa=ha->head->next,*pb=hb->head->next;
    while(pa && pb){
        if(pa->data == pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            q=pb;
            pb=pb->next;
            delete q;
        } 
        else if(pa->data < pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa ? pa : pb;
}
void  linklist::Inter(linklist *&ha,linklist *&hb){
    lnode *pc=head;
    lnode *q;
    lnode *pa=ha->head->next,*pb=hb->head->next;
    while(pa && pb){
        if(pa->data == pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            q=pb;
            pb=pb->next;
            delete q;
        }
        else if(pa->data < pb->data){
            q=pa;
            pa=pa->next;
            delete q;

        }
        else {
            q=pb;
            pb=pb->next;
            delete q;
        }
    }
    pc->next=NULL;
}
#if 0 //并集
int main(){
    linklist l1,l2,l3;
    linklist *le,*lr;
    l1.initlist();
    l2.initlist();
    l1.print();
    le=&l1;
    l2.print();
    lr=&l2;
    cout<<"ha,hb并集为:";
    l3.Union(le,lr);
    l3.print();
    cout<<endl;
    return 0;
}
#endif
#if 1 //交集
int main(){
    linklist l1,l2,l3;
    linklist *le,*lr;
    l1.initlist();
    l2.initlist();
    l1.print();
    l2.print();
    le=&l1;
    lr=&l2;
    cout<<endl;
    cout<<"ha,hb交集为:";
    l3.Inter(le,lr);
    l3.print();
    cout<<endl;
    return 0;
}
#endif