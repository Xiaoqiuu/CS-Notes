#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 2000

typedef struct student{
    int num;
    char name[20];
    char sex;
    char add[40];
}stu;

typedef struct {
    stu s[N];
    int length;//记录实际存放个数
}SqlList;

void InitList(SqlList *&L)
{
    L = (SqlList *)malloc(sizeof(SqlList));
    L -> length = 0;
}

void CreatList (SqlList *&L)
{
    int i, x;
    InitList(L);
    if (L == NULL){
        cout << "SQL FAILED." << '\n';
    }
    else {
        scanf("%d", &x);
        for (i = 0;i < x; ++ i) {
            scanf("%d", L -> s[i].num);
            scanf("%s", L -> s[i].name);
            getchar();
            scanf("%c", L -> s[i].sex);
            scanf("%s", L -> s[i].add);
            L -> length ++;
        }   
    }
}

void ShowList (SqlList *L)
{
    for(int i = 0; i < L -> length; ++ i) {
        cout << L -> s[i].num;
    }
}

int main()
{
    int x;
    SqlList *L = NULL;
    cout << "-----------Menu----------";
}