#include <stdio.h>
#include <stdlib.h>

struct dict
{
    struct dict *left,*right;
    char word[20],meaning[20];
}*Root=NULL;

typedef struct dict dict;

void Search();
void Insert(dict *);
void View(dict *);
int Check(char[],char[]);

int main()
{
    int ch;
    dict *temp;
    while(ch!=4)
    printf("1.Search\n2.Insert\n3.View\n4.Quit\n");
    printf("Please Enter your choice:\n");
    scanf("%d",&ch);
       switch(ch)
       {
           case 1:
           Search();
           break;

           case 2:
           temp=(dict*)malloc(sizeof(dict));
           temp->left=NULL;
           temp->right=NULL;
           printf("\nInsert Word:");
           scanf("%s",temp->word);
           printf("\nInsert Meaning:\n");
           scanf("%s",temp->meaning);
           Insert(temp);
           break;

           case 3:
           View(Root);
           break;
           
           case 4:
           exit(0);
       }
       return 0;
    }

int Check(char a[],char b[])
{
    int i,j,c;
    for(i=0,j=0;a[i]!='\0'&&a[j]!='\0';i++,j++)
    {
        if(a[i]>b[j])
        {
            c=1;
            break;
        }
        else if(a[i]<a[j])
        {
            c=-1;
        }
        else{
            c=0;
        }
    }
    if(c==1)
    {
        return 1;
    }
    else if(c==-1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void Search()
{
    char word[30];
    dict *ptr;
    int flag=0;
    ptr=Root;
    
    printf("\nEnter the word you want to search....:\n");
    scanf("%s",word);
    while(ptr!=NULL&&flag==0)
    {
        if(Check(word,ptr->word)==1)
        {
            ptr=ptr->right;
        }
        else if(Check(word,ptr->word)==1)
        {
            ptr=ptr->left;
        }
        else{
            flag=1;
            printf("\nMeaning:%s",ptr->meaning);
            break;
        }
    }
    if(flag==0 && ptr==NULL)
    {
        printf("\nWord Not Found!!!");
    }
}

void Insert(dict *temp)
{
    dict *ptr,*par;
    int flag=0;
    ptr=Root;
    if(Root==NULL)
    {
        Root=temp;
    }
    else{
        while(ptr!=NULL)
    {
        if(Check(temp->word,ptr->word)==1)
        {
            par=ptr;
            ptr=ptr->right;
        }
        else if(Check(temp->word,ptr->word)==1)
        {
            par=ptr;
            ptr=ptr->left;
        }
        else{
            flag=1;
            printf("Word Exist!\n");
            break;
        }
    }
    if(flag==0)
    {
        if(Check(par->word,temp->word)==1)
        {
            par->left=temp;
        }
        else if(Check(par->word,temp->word)==-1)
        {
            par->right=temp;
        }

    }
    }
}

void View(dict *ptr)
{
    if(Root==NULL)
    {
        printf("\nEmpty Dictionary\n");
    }
    else{
        if(ptr!=NULL)
        {
            ptr=ptr->left;
            printf("\nWord:%s",ptr->word);
            printf("\nWord:%s",ptr->meaning);
            View(ptr->right);
        }
    }
}