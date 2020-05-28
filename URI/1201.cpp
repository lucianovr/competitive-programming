#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    int info;
    struct tree *Left, *Right;
} Tree;

bool flag;

void Insert(Tree **p, int v) {
    if ((*p) == NULL) {
        (*p) = (Tree *)malloc(sizeof(Tree));
        if ((*p)) {
            (*p)->info = v;
            (*p)->Left = NULL;
            (*p)->Right = NULL;
        }
    } else {
        if (v < (*p)->info)
            Insert(&(*p)->Left, v);
        else
            Insert(&(*p)->Right, v);
    }
}

int Search(Tree *p, int v) {
    if (p == NULL)
        return 0;
    else if (p->info == v)
        return 1;
    else if (p->info > v)
        return Search(p->Left, v);
    else
        return Search(p->Right, v);
}

Tree *Maior(Tree **p) {
    Tree *pAux = *p;
    if (pAux->Right == NULL) {
        *p = (*p)->Left;
        return pAux;
    } else
        return Maior(&(*p)->Right);
}

void Remove(Tree **p, int C) {
    Tree *pN;
    if (*p == NULL)
        return;

    if (C == (*p)->info) {
        pN = *p;
        if ((*p)->Left == NULL)
            *p = (*p)->Right;
        else if ((*p)->Right == NULL)
            *p = (*p)->Left;
        else {
            pN = Maior(&(*p)->Left);
            (*p)->info = pN->info;
        }
        pN = NULL;
    } else if (C < (*p)->info)
        Remove(&(*p)->Left, C);
    else
        Remove(&(*p)->Right, C);
}

void Infixa(Tree *p) {
    if (p == NULL)
        return;

    Infixa(p->Left);

    if (flag)
        printf(" ");
    flag = true;
    printf("%d", p->info);

    Infixa(p->Right);
}

void Posfixa(Tree *p) {
    if (p == NULL)
        return;

    Posfixa(p->Left);
    Posfixa(p->Right);

    if (flag)
        printf(" ");
    flag = true;
    printf("%d", p->info);
}

void Prefixa(Tree *p) {
    if (p == NULL)
        return;

    if (flag)
        printf(" ");
    flag = true;
    printf("%d", p->info);

    Prefixa(p->Left);
    Prefixa(p->Right);
}

int main() {
    Tree *t = NULL;

    char comand[100];
    int v;

    while (scanf("%s", comand) != EOF) {

        if (strcmp(comand, "I") == 0) {
            scanf(" %d", &v);
            Insert(&t, v);
        } else if (strcmp(comand, "P") == 0) {
            scanf(" %d", &v);
            printf("%d %s\n", v, Search(t, v) ? "existe" : "nao existe");
        } else if (strcmp(comand, "R") == 0) {
            scanf(" %d", &v);
            if (Search(t, v))
                Remove(&t, v);
        } else if (strcmp(comand, "INFIXA") == 0) {
            flag = false;
            Infixa(t);
            printf("\n");
        } else if (strcmp(comand, "PREFIXA") == 0) {
            flag = false;
            Prefixa(t);
            printf("\n");
        } else if (strcmp(comand, "POSFIXA") == 0) {
            flag = false;
            Posfixa(t);
            printf("\n");
        }
    }
    return 0;
}
