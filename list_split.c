#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct split_list {
    struct node *before;
    struct node *after;
};

struct split_list *split(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct split_list *list_split = split(head);
    printf("before = ");
    print_list(list_split->before);
    printf("after = ");
    print_list(list_split->after);
    return 0;
}


// Given a list with at least one node, and exactly one 0,
// split the list into a list with everything before the 0,
// and a list with the 0 and everything after.
// Return a malloced split_list struct with each of these lists.
struct split_list *split(struct node *head) {
    // PUT YOUR CODE HERE (change the next line!)
    struct split_list *split = malloc(sizeof(struct split_list));
    struct node *curr = head;
    struct node *start = head;
    struct node *temp = head;
    struct node *ptr = head;

    if (head->data == 0) {
        split->before = NULL;
        split->after = curr;
    } else {
        while (curr != NULL && curr->data != 0) { 
            split->after = curr->next;
            curr = curr->next;
        }

        int zero_index = 0;
        while (start->data != 0) {
            zero_index++;
            start = start->next;
        }

        start = head;
        while (temp->data != 0) {
            temp = temp->next;
        }
        int i = 0;
        while (i < zero_index - 1) {
            ptr = ptr->next;
            i++;
        }
        ptr->next = NULL;
        split->before = start;
    }
    return split;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}