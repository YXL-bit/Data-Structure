
#include<iostream>
using namespace std;
typedef struct lnode{ int data; lnode *next;}lnode;
class linklist{
    lnode *head;
    public:
    void deletex(int x);//删除函数
    void turn();
    void split();
    void insertx(int x);
    void *midnode();
    void rangedelete(int min,int max);
};
// void deletex(int x){
//     lnode *pr=head,*p=head->next;
//     while(p&&p->data!=x){pr=p;p=p->next;}
//     pr->next=p->next;
//     delete p;
// }
void linklist::deletex(int x){
    lnode *pr=head,*p=head->next;
    while(p){
      if(p->data!=x){pr=p;p=p->next;}
      else{pr->next = p->next; delete p; p = pr->next;}
    }
}
void linklist::turn(){
     lnode *p = head->next;
     if(!p||!p->next) return;
     lnode *qr=p->next,*q;
     p->next=NULL;
     while(qr->next){
       q=qr->next;
       qr->next=p;
       p=qr;
       qr=q;
    }
     qr->next=p;
     head->next=qr;
}
void linklist::split(){
    lnode *hb;
      hb=new lnode;
      hb->next=NULL;
      lnode *par=head,*pa=head->next,*pb;
      while(pa){
        if(pa->data%2==0){par=pa;pa=pa->next;}
        else{pb=new lnode;
             pb->data=pa->data;
             pb->next=hb->next;
             hb->next=pb;
             par->next=pa->next;
             delete pa;
             pa=par->next;             
         }
	  }
}
lnode *midnode(lnode *head){
       lnode *a1=head->next,*a2;
       if(a1==NULL||a1->next==NULL) return a1;
       a2=a1->next;
       while(a2&&a2->next){
        a1=a1->next;
        a2=a2->next->next;
      }
       return a1;
}   
void linklist::insertx(int x){
      lnode *pr=head,*p=head->next;
      while(p&&p->data<x) {pr=p;p=p->next;}        
      lnode *s=new lnode;
      s->data=x;
      s->next=p;
      pr->next=s;
}
void linklist::rangedelete(int min,int max){
  lnode *pr=head,*p=head->next;
  while(p&&p->data<=min){pr=p;p=p->next;}
  while(p&&p->data<max){
    pr->next=p->next;
    delete p;
    p=pr->next;
  }
}
 void linklist::sum(){  //并集
	lnode *par=ha,*pa=ha->next;
	lnode *pbr=hb,*pb=hb->next;
	while(pa !=NULL || pb !=NULL){
		if(pa->data != pb->data){
			while(pa->data < pb->data){
				par=pa;
				pa=pa->next;
			}
			lnode *q=new lnode;
			q->data=pb->data;
			pbr=pb;
			pb=pb->next;
			q->next=par->next;
			par->next=q;
			delete par;
			par=q;
			
		}
	}
	if(!pa && pb){
		lnode *k=new lnode;
		k->data=pb->data;
		pbr=pb;
		pb=pb->next;
		k->next=par->next;
		par->next=k;
		delete par;
		par=k;
		
	}
} 
void linklist::sum(){
	lnode *q;
	lnode *par=ha,*pa=ha->next;
	lnode *pbr=hb,*pb=hb->next;
	lnode *pc=hash;
	while(pa && pb ){
		if(pa->data == pb->data){
			q=new lnode;
			q->data=pa->data;
			q->next=pc->next;
			pc->next=q;
			pc=q;
			pa=pa->next;
			pb=pb->next;
		}
		if(pa->data < pb->data){
			q=new lnode;
			q->data=pa->data;
			q->next=pc->next;
			pc->next=q;
			pc=q;
			pa=pa->next;
		}
		if(pa->data > pb->data){
			q=new lnode;
			q->data=pb->data;
			q->next=pc->next;
			pc->next=q;
			pc=q;
			pb=pb->next;
		}
	}
	if(!pb){
		printresult();
	}
	else{
		if(!pa){
			while(pb){
				q=new lnode;
				q->data=pb->data;
				q->next=pc->next;
				pc->next=q;
				pc=q;
				pb=pb->next;
			}
		}
		linklist lr;
		lr.printresult();
	}
}

