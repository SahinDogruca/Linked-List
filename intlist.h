//
//  intlist.h
//  LinkedLists
//
//  Created by Şahin Doğruca on 21.10.2023.
//

#ifndef intlist_h
#define intlist_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int val;
    struct Node * next;
}*head = NULL;


struct Node * create(struct Node * first, int arr[], int n) {
    struct Node *t, *last;
    int i;
    first = (struct Node *) malloc(sizeof(struct Node));
    first->val = arr[0];
    first->next = NULL;
    
    last = first;
    head = first;

    
    for(i = 1;i < n; i++) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->val = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
    return head;
}


void display(struct Node * p) {
    printf("\n");
    if(!p) printf("list is empty");
    while(p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node * p) {
    if(p) return length(p->next) + 1;
    return 0;
}

int find(struct Node * p, int elem) {
    int count = 0;
    if(!p) {
        printf("list is empty");
        return -1;
    }
    while(p) {
        if(p->val == elem) return count;
        count++;
        p = p->next;
    }
    printf("element is not find");
    return -1;
}

struct Node * insert(struct Node * p, int elem, int index) {
    struct Node * t = (struct Node *) malloc(sizeof(struct Node));
    t->val = elem;
    t->next = NULL;
    
    if(index == 0) {
        t->next = p;
        head = t;
    } else {
        index--;
        while(index != 0) {
            p = p->next;
            index--;
        }
        t->next = p->next;
        p->next = t;
    }
    
    return head;
}

struct Node * delete(struct Node * p, int index) {
    struct Node * t = (struct Node *) malloc(sizeof(struct Node));
    struct Node * q = NULL;
    
    if(index == 0) {
        t = p;
        head = p->next;
        free(t);
    } else {
        index--;
        while(index != 0){
            q = p;
            p = p->next;
            index--;
        }
        t = p;
        q->next = p->next;
        free(t);
    }
    
    return head;
}


#endif /* intlist_h */
