#include<bits/stdc++.h>
using namespace std;
typedef struct student
{
    int num;
    int score;
    struct student *next;
}stu;

stu *create(int x)
{
    stu *p,*head=NULL,*q=head;
    for (int i=0;i<x;i++)
    {
        p=(stu *)malloc(sizeof(stu));
        scanf("%d%d",&p->num,&p->score);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            q->next=p;
        q=p;
    }
    return head;
}

stu *change(stu *head)
{
    stu *p=head;
    stu *q;
    stu *pointer;
    p=head->next;
    head->next=NULL;
    while (p!=NULL)
    {
        pointer=p->next;
        q=head;
        if(q->num>p->num)
        {
            p->next=head;
            head = p;
        }
        else
        {
            while (q->next!=NULL && q->next->num<p->num)
            {
                q=q->next;
            }
                p->next=q->next;
                q->next=p;
        }
        p = pointer;
    }
    pointer = head;
    return head;
}
stu *link(stu *p1,stu *p2)
{
    stu *p,*head;
    if (p1->num<p2->num)
    {
        head=p1;
        p=p1;
        p1=p1->next;
    }
    else
    {
        head=p2;
        p=p2;
        p2=p2->next;
    }
    while (p1!=NULL&&p2!=NULL)
    {
        if (p1->num<p2->num)
        {
            p->next=p1;
            p=p1;
            p1=p1->next;
        }
        else
        {
            p->next=p2;
            p=p2;
            p2=p2->next;
        }
    }
    if(p1!=NULL)
        p->next=p1;
    else
        p->next=p2;

    return head;
}

void output(stu *p)
{
    while (p!=NULL)
    {
        printf("%d %d\n",p->num,p->score);
        p=p->next;
    }
}

int main()
{
    stu *a,*b,*c;
    int m,n;
    scanf("%d%d",&n,&m);
    a=create(n);
    b=create(m);
    c=link(a,b);
    c=change(c);
    output(c);
}
