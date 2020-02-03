#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int m,s=4,c,q,p=12;

struct Node
{
    struct Node *ll;
    int data;
    struct Node *rl;
};

struct Node* start=NULL;
struct Node* end=NULL; 

struct Node* cn()//Create node
{
    struct Node* nnode;
    nnode=(struct Node *)malloc(sizeof(struct Node));
    nnode->data=254;
    nnode->rl=NULL;
    nnode->ll=NULL;
    return (nnode);
}

void t()//Traversing
{
    struct Node* temp;

    temp=start;
    while(temp!=end)
    {
        printf("%c ",temp->data);
        temp=temp->rl;
    }
    printf("%c ",temp->data);
    printf("\n");
}

void cl()//Create list
{
    int n,i;

    struct Node *nnode,*temp;

    for(i=0;i<12;i++)
    {
        nnode=cn();
        if(start==NULL)
        {
            start=nnode;
            end=nnode;
        }
        else
        {
            temp=end;
            temp->rl=nnode;
            end=nnode;
        }
    }
    printf("The starting squares are\n");
    t();
}

void dlp()//delete the last node Player
{
    struct Node *temp,*pre;
    temp=start;
    if(c==0)
    return ;
    else
    {
        if(start==end)
        {
            free(end);
            end=NULL;
            start=NULL;
        }
        else
        {
            while(temp->rl!=NULL)
            {
                pre=temp;
                temp=temp->rl;
            }
            free(temp);
            end=pre;
            end->rl=NULL;
        }
        c--;
        p--;
        dlp();
    }
}

void dln()//delete the last node Computer
{
    struct Node *temp,*pre;
    temp=start;
    if(m==0)
    return ;
    else
    {
        if(start==end)
        {
            free(end);
            end=NULL;
            start=NULL;
        }
        else
        {
            while(temp->rl!=NULL)
            {
                pre=temp;
                temp=temp->rl;
            }
            free(temp);
            end=pre;
            end->rl=NULL;
        }
        m--;
        p--;
        dln();
    }
}

void nim()
{
    m=s-q;
    dln();
    printf("Computer played\n");
    t();
}

void player()
{
    dlp();
    printf("You played\n");
    t();
}

void ch()
{
    if(c<4 && c>0)
    return;
    else if(c>3)
    {
        printf("No of squares to be removed cannot exceed 3\nGive the no of squares you want to remove\n");
        scanf("%d",&c);
    }
    else if(c==0)
    {
        printf("You've to remove at least 1 square\nGive the no of squares you want to remove\n");
        scanf("%d",&c);
    }
    else
    {
        printf("Invalid input\nGive the no of squares you want to remove\n");
        scanf("%d",&c);
    }
    ch();
}

int main()
{
    int op;
    printf("There are 12 squares pieces your goal is to pick the last one\n");
    printf("Rules\n1.You can pick 1,2 or 3 squares\n");
    printf("2.You've to remove at least 1 square\n");

    printf("How'd like to play\n1.Have a chance at winning\n2.Computer Always wins\n");
    scanf("%d",&op);
    cl();
    switch(op)
    {
        case 1:
        {
        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
        m=0;
        while(m==0)
        {
            srand(time(0));
            m=rand()%3;
        }
        dln();
        printf("Computer played\n");
        t();
        while(p>4)
        {
            printf("How many squares would you like to remove\n");
            scanf("%d",&c);
            ch();
            q=c;
            player();
            if(p==4)
            {
                printf("Player Wins\n");
                exit(0);
            }
        
            if(p>4 && p<8)
                q=8-p;
            else if(p>8 && p<13)
                q=12-p;
            else if(p==8)
            {
                while(q==0)
                {
                srand(time(0));
                q=rand()%3;
                } 
            }
            nim();

            if(p==4)
            {
                printf("Computer wins\n");
                exit(0);
            }
        }

        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
        if(p==4)
        {
            printf("Player wins\n");
            exit(0);
        }
        if(p>4)
        nim();
        else
        {
            printf("Computer Wins\n");
            exit(0);
        }
        

        if(p>4)
        {
        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
        printf("Computer wins\n"); 
        }


        }
        break;
        
        case 2:
        {
        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
        nim();
        
        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
        nim();
        if(p==4)
        {
            printf("Computer Wins\n");
            exit(0);
        }

        printf("How many squares would you like to remove\n");
        scanf("%d",&c);
        ch();
        q=c;
        player();
            printf("Computer wins by removing %d squares\n",p);
        }
        break;
    }
    return 0;
}