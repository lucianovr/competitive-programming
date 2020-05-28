#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char info;
    struct tree *Left, *Right;
} Tree;

Tree *create() { return NULL; }
bool flag;

void Insert(Tree **p, char v) {
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

int Search(Tree *p, char v) {
    if (p == NULL)
        return 0;
    else if (p->info == v)
        return 1;
    else if (p->info > v)
        return Search(p->Left, v);
    else
        return Search(p->Right, v);
}

void Infixa(Tree *p) {
    if (p == NULL)
        return;

    Infixa(p->Left);

    if (flag)
        printf(" ");
    flag = true;
    printf("%c", p->info);

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
    printf("%c", p->info);
}
void Prefixa(Tree *p) {
    if (p == NULL)
        return;

    if (flag)
        printf(" ");
    flag = true;
    printf("%c", p->info);

    Prefixa(p->Left);
    Prefixa(p->Right);
}

int main() {
    Tree *t;
    t = create();
    char comand[100], v;

    while (scanf("%s", comand) != EOF) {
        if (strcmp(comand, "I") == 0) {
            scanf(" %c", &v);
            Insert(&t, v);
        } else if (strcmp(comand, "P") == 0) {
            scanf(" %c", &v);
            printf("%c %s\n", v, Search(t, v) ? "existe" : "nao existe");
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
