/* File:   main.c
 * Author: Ritesh Kudalkar
 * Team: Veyd Kurup, Pradnesh Khedekar, Kumar Mantha, Aditya Kurup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char ch;
FILE *f1;
struct element
{
    char symbol[3];
};
void display()
{
    struct element e[8][19];
    int i,j,grp,prd,an;
    float aw;
    char nm[20], sy[3];
    //char s1[1]=".";
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=18;j++)
        {
            e[i][j].symbol[0]='\0';
            e[i][j].symbol[1]='\0';
            e[i][j].symbol[2]='\0';
        }
    }
    system("clear");
    f1=fopen("ModernPeriodicTable.txt","r");
    for(i=0;i<118;i++)
    {
        fscanf(f1,"%s %s %d %f %d %d",nm,sy,&an,&aw,&grp,&prd);
        strcpy(e[prd][grp].symbol,sy);
    }
    printf("\n The Modern Periodic Table: \n");
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=18;j++)
        {
            if(e[i][j].symbol==NULL)
            {
                printf(" \t");
            }
            else
            {
                printf("%s\t",e[i][j].symbol);
            }
        }
        printf("\n");
    }
    fclose(f1);
    ch=getchar();
}
void searchByAN()
{
    int an=0;
    printf("\nEnter the Atomic Number of the element: ");
    scanf("%d",&an);
    if(an>118)
    {
        printf("Element not discovered yet!!");
    }
    else
    {
        f1=fopen("ModernPeriodicTable.txt","r");
        char nm1[15], sy1[3];
        float aw1=0.0;
        int an1=0,found=0,i,grp1=0,prd1=0;
        for(i=1;i<=118;i++)
        {
            fscanf(f1," %s %s %d %f %d %d",nm1,sy1,&an1,&aw1,&grp1,&prd1);
            if(an==an1)
            {
                printf("Name of the element is: %s",nm1);
                printf("\nSymbol of the element is: %s",sy1);
                printf("\nAtomic Weight of the element is: %.4f",aw1);
                printf("\nAtomic Number of the element is: %d",an);
                printf("\nIt belongs to period %d and group %d",prd1,grp1);
                found=1;
                ch=getchar();
                break;
            }
        }
        if(found==0)
            printf("Element Not Found!!");
        fclose(f1);
    }
    ch=getchar();
}
void searchByAW()
{
    float aw=0.0,aw1;
    printf("Enter the atomic weight of the element: ");
    scanf("%f",&aw);
    f1=fopen("ModernPeriodicTable.txt","r");
    char nm1[15], sy1[3];
    int an1=0,found=0,i,grp1=0,prd1=0;
        for(i=1;i<=118;i++)
        {
            fscanf(f1," %s %s %d %f %d %d",nm1,sy1,&an1,&aw1,&grp1,&prd1);
            if(aw==aw1)
            {
                printf("Name of the element is: %s",nm1);
                printf("\nSymbol of the element is: %s",sy1);
                printf("\nAtomic Weight of the element is: %.4f",aw1);
                printf("\nAtomic Number of the element is: %d",an1);
                printf("\nIt belongs to period %d and group %d",prd1,grp1);
                found=1;
                ch=getchar();
                break;
            }
        }
        if(found==0)
            printf("Element Not Found!!");
        fclose(f1);
        ch=getchar();
}
void searchByName()
{
    char nm[15];
    printf("Enter the name of the element: ");
    scanf("%s",nm);
    f1=fopen("ModernPeriodicTable.txt","r");
        char nm1[15], sy1[3];
        float aw1=0.0;
        int an1=0,found=0,i,grp1=0,prd1=0;
        for(i=1;i<=118;i++)
        {
            //fflush(stdout);
            fscanf(f1," %s %s %d %f %d %d",nm1,sy1,&an1,&aw1,&grp1,&prd1);
            //fflush(stdin);
            if(strcmp(nm,nm1)==0)
            {
                //system("clear");
                printf("Name of the element is: %s",nm1);
                printf("\nSymbol of the element is: %s",sy1);
                printf("\nAtomic Weight of the element is: %.4f",aw1);
                printf("\nAtomic Number of the element is: %d",an1);
                printf("\nIt belongs to period %d and group %d",prd1,grp1);
                found=1;
                ch=getchar();
                break;
            }
        }
        if(found==0)
            printf("Element Not Found!!");
        fclose(f1);
        ch=getchar();
}
void searchBySym()
{
    char sy[3];
    printf("Enter the Symbol of the element: ");
    scanf("%s",sy);
    f1=fopen("ModernPeriodicTable.txt","r");
    char nm1[15], sy1[3];
    float aw1=0.0;
    int an1=0,found=0,i,grp1=0,prd1=0;
        for(i=1;i<=118;i++)
        {
            fscanf(f1," %s %s %d %f %d %d",nm1,sy1,&an1,&aw1,&grp1,&prd1);
            if(strcmp(sy,sy1)==0)
            {
                //system("clear");
                printf("Name of the element is: %s",nm1);
                printf("\nSymbol of the element is: %s",sy1);
                printf("\nAtomic Weight of the element is: %.4f",aw1);
                printf("\nAtomic Number of the element is: %d",an1);
                printf("\nIt belongs to period %d and group %d",prd1,grp1);
                found=1;
                ch=getchar();
                break;
            }
        }
        if(found==0)
            printf("Element Not Found!!");
        fclose(f1);
        ch=getchar();
}
void insert()
{
    char nm[10], sy[3];
    float aw;
    int an,grp,prd;
    f1=fopen("ModernPeriodicTable.txt","a");
    printf("Enter the name of the element: ");
    scanf("%s",nm);
    printf("Enter the Symbol of the element: ");
    scanf("%s",sy);
    printf("Enter the Atomic Weight of the element: ");
    scanf("%f",&aw);
    printf("Enter the Atomic Number of the element: ");
    scanf("%d",&an);
    printf("Enter the group to which it belongs: ");
    scanf("%d",&grp);
    printf("Enter the period to which the element belongs: ");
    scanf("%d",&prd);
    fflush(stdin);
    fprintf(f1,"%s\t\t",nm);
    fprintf(f1,"%s\t ",sy);
    fprintf(f1,"%d\t ",an);
    fprintf(f1,"%f\t\t ",aw);
    fprintf(f1,"%d\t ",grp);
    fprintf(f1,"%d\n",prd);
    fclose(f1);
}
int main() 
{
    int c1=0;
    do
    {
        system("clear");
        printf("\nEnter: \n 1 - Display Modern Periodic Table \n 2 - Search an element \n 3 - To add a new element \n 4 - To Exit");
        printf("\nEnter your choice: \n");
        scanf("%d",&c1);
        switch(c1)
        {
            case 1:
                display();
                printf("\n");
                ch=getchar();
                break;
            case 2:
                system("clear");
                int c2;
                do
                {
                    printf("\nEnter: \n 1 - Search by Symbol \n 2 - Search by Atomic Number \n 3 - Search by Atomic Weight \n 4 - Search by Name \n 5 - To enter main menu");
                    printf("\nEnter your choice: ");
                    scanf("%d",&c2);
                    switch(c2)
                    {
                        case 1:
                            searchBySym();
                            break;
                        case 2:
                            searchByAN();
                            break;
                        case 3:
                            searchByAW();
                            break;
                        case 4:
                            searchByName();
                            break;
                        case 5:
                            break;
                        default:
                            printf("\nWrong choice! Enter again!! \n");
                    }
                    system("clear");
                }while(c2!=5);
                break;
            case 3:
                insert();
                break;
            case 4:
                break;
            default:
                printf("Wrong choice!! Enter again: ");
        }
    }while(c1!=4);
    return 0;
}
