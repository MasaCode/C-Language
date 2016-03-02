#include <stdio.h>
#include <stdlib.h>

struct person{
    int ID;
    char name[30];
    int salary;
    struct person *next;
    struct person *prev;
};

struct person *createfirst(struct person *start){
    struct person *NewStudent = (struct person *)malloc(sizeof(struct person));
    
    printf("Please enter your student ID:");
    scanf("%d",&NewStudent->ID);
    printf("Please enter your name:");
    scanf("%s",NewStudent->name);
    printf("Please enter your salary:");
    scanf("%d",&NewStudent->salary);
    NewStudent->next = 0;
    NewStudent->prev = 0;
    start = NewStudent;
    return start;
}

struct person *createfront(struct person *start){
    struct person *NewStudent = (struct person *)malloc(sizeof(struct person));
    
    printf("Please enter your student ID:");
    scanf("%d",&NewStudent->ID);
    printf("Please enter your name:");
    scanf("%s",NewStudent->name);
    printf("Please enter your salary:");
    scanf("%d",&NewStudent->salary);
    NewStudent->next = start;
    NewStudent->prev = 0;
    start->prev = NewStudent;
    start = NewStudent;
    return start;
}

struct person *createafter(struct person *last){
    struct person *NewStudent = (struct person *)malloc(sizeof(struct person));
    
    printf("Please enter your student ID:");
    scanf("%d",&NewStudent->ID);
    printf("Please enter your name:");
    scanf("%s",NewStudent->name);
    printf("Please enter your salary:");
    scanf("%d",&NewStudent->salary);
    last->next = NewStudent;
    NewStudent->prev = last;
    NewStudent->next = 0;
    last = NewStudent;
    return last;
}


void createbackmiddle(struct person *start,struct person *last){
    int ID;
    struct person *NewStudent = (struct person *)malloc(sizeof(struct person));
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *location = (struct person *)malloc(sizeof(struct person));
    Current = start;
    if(Current == 0){
        printf("There is no linked list\n");
        return;
    }else{
        printf("\n\n\nWhere do you wanna add this Data?\n");
        printf("Please enter the ID that you wanna add right after:");
        scanf("%d",&ID);
    
        while(Current != 0){
            if(Current->ID == ID){
                break;
            }
            Current = Current->next;
        }
        if(Current == 0){
            printf("There is no such ID\n");
            return;
        }else if(Current->next == 0){
            printf("There is not good enough list\n");
            return;
        }else{
            printf("Please enter your student ID:");
            scanf("%d",&NewStudent->ID);
            printf("Please enter your name:");
            scanf("%s",NewStudent->name);
            printf("Please enter your salary:");
            scanf("%d",&NewStudent->salary);
            
            location = Current->next;
            Current->next = NewStudent;
            NewStudent->prev = Current;
            NewStudent->next = location;
            location->prev = NewStudent;
    
        }
    }
}

void createfrontmiddle(struct person *start,struct person *last){
    int ID;
    struct person *NewStudent = (struct person *)malloc(sizeof(struct person));
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *location = (struct person *)malloc(sizeof(struct person));
    Current = start;
    if(Current == 0){
        printf("There is no linked list\n");
        return;
    }else{
        printf("\n\n\nWhere do you wanna add this Data?\n");
        printf("Please enter the ID that you wanna add right after:");
        scanf("%d",&ID);
    
        while(Current != 0){
            if(Current->ID == ID){
                break;
            }
            Current = Current->next;
        }
        if(Current == 0){
            printf("There is no such ID\n");
            return;
        }else if(Current->prev == 0){
            printf("There is not good enough list\n");
            return;
        }else{
            printf("Please enter your student ID:");
            scanf("%d",&NewStudent->ID);
            printf("Please enter your name:");
            scanf("%s",NewStudent->name);
            printf("Please enter your salary:");
            scanf("%d",&NewStudent->salary);
            
            location = Current->prev;
            location->next = NewStudent;
            NewStudent->prev = location;
            NewStudent->next = Current;
            Current->prev = NewStudent;
        }
    }
}

void Delete(struct person **start,struct person **last){
    int ID;
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *Next = (struct person *)malloc(sizeof(struct person));
    struct person *Previous = (struct person *)malloc(sizeof(struct person));
    Current = *start;
    if(Current == 0){
        printf("There is no linked list\n");
        return;
    }else{
        printf("Please enter the ID that you want to delete:");
        scanf("%d",&ID);
    
        while(Current != 0){
            if(ID == Current->ID){
                break;
            }
            Current = Current->next;
        }
        if(Current ==0){
            printf("There is no such kind of ID\n");
            return;
        }else{
            if(Current == *start && Current!= *last){
                Next = Current->next;
                Next->prev = 0;
                *start = Next;
                Current->next = 0;
                free(Current);
            }else if(Current == *last && Current!= *start){
                Previous = Current->prev;
                Previous->next = 0;
                *last = Previous;
                Current->prev = 0;
                free(Current);
            }else if(Current == *last && Current == *start){
                Current->next = 0;
                Current->prev = 0;
                free(Current);
                *last = 0;
                *start = 0;
            }
            else{
                Next = Current->next;
                Previous = Current->prev;
                Previous->next = Next;
                Next->prev = Previous;
                Current->next = 0;
                Current->prev = 0;
                free(Current);
            }
        }
    }
    
}

void DeleteAll(struct person **start,struct person **last){
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *Next = (struct person *)malloc(sizeof(struct person));
    Current = *start;
    if(Current == 0){
        printf("There is no linked list\n");
        return;
    }else{
        while (Current != NULL){
            Next = Current->next;
            free(Current);
            Current = Next;
        }
        *start = NULL;
        *last = NULL;
    }
    
}

struct person *DeleteFirst(struct person *start){
    struct person *Current;
    struct person *Next;
    Current = start;
    if(Current == 0){
        printf("There is no linked list\n");
    }else{
        Next = Current->next;
        Next->prev = 0;
        start = Next;
        Current->next = 0;
    }
    return start;
}

struct person *DeleteLast(struct person *last){
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *Previous = (struct person *)malloc(sizeof(struct person));
    Current = last;
    if(Current == 0){
        printf("There is no linked list\n");
    }else{
        Previous = Current->prev;
        Previous->next = 0;
        last = Previous;
        Current->prev = 0;
        free(Current);
    }
    return last;
}

void printforward(struct person *start){
    struct person *Current;
    Current = start;
    if(Current == 0){
        printf("There is nothing to print out\n");
        return;
    }else{
        printf("\n\n%s\t%s\t%s\t\n","ID","Name","Salary");
        while(Current != NULL){
            printf("%d\t",Current->ID);
            printf("%s\t",Current->name);
            printf("%d\t\n",Current->salary);
            Current = Current->next;
        }
        printf("\n\n\n");
    }
}


void printbackward(struct person *last){
    struct person *Current;
    Current = last;
    if(Current == 0){
        printf("There is nothing to print out\n");
        return;
    }else{
        printf("\n\n%s\t%s\t%s\t\n","ID","Name","Salary");
        while(Current != NULL){
            printf("%d\t",Current->ID);
            printf("%s\t",Current->name);
            printf("%d\t\n",Current->salary);
            Current = Current->prev;
        }
        printf("\n\n\n");
    }
}

struct person *Deleteafter(struct person *start,struct person *last){
    int ID;
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *Next = (struct person *)malloc(sizeof(struct person));
    struct person *Nextafter = (struct person *)malloc(sizeof(struct person));
    Current = start;
    if(Current == 0){
        printf("There is no linked list\n");
        return last;
    }else{
        printf("Please enter the ID that is right before you want to delete:");
        scanf("%d",&ID);
        
        while(Current != 0){
            if(ID == Current->ID){
                break;
            }
            Current = Current->next;
        }
        Next = Current->next;
        Nextafter = Next->next;
        if(Nextafter==0){
            Current->next = 0;
            Next->prev = 0;
            last = Current;
        }else{
            Current->next = Nextafter;
            Nextafter->prev = Current;
            Next->next = 0;
            Next->prev = 0;
        }
        free(Next);
    }
    return last;
}

struct person *Deletefront(struct person *start,struct person *last){
    int ID;
    struct person *Current = (struct person *)malloc(sizeof(struct person));
    struct person *Previous = (struct person *)malloc(sizeof(struct person));
    struct person *Previousbefore = (struct person *)malloc(sizeof(struct person));
    Current = start;
    if(Current == 0){
        printf("There is no linked list\n");
        return start;
    }else{
        printf("Please enter the ID that is right after you want to delete:");
        scanf("%d",&ID);
        
        while(Current != 0){
            if(ID == Current->ID){
                break;
            }
            Current = Current->next;
        }
        Previous = Current->prev;
        Previousbefore->next = Current;
        if(Previousbefore == 0){
            Current->prev = 0;
            Previous->next = 0;
            start = Current;
        }else{
            Current->prev = Previousbefore;
            Previous->next = 0;
            Previous->prev = 0;
        }
        free(Previous);
    }
    return start;
}



int menu(){
    int decision;
    printf("Data Linked List Processing Program\n");
    printf("1 . Add the Data in front of previous Data\n");
    printf("2 . Add the Data right after previous Data\n");
    printf("3 . Add the Data middle right after\n");
    printf("4 . Add the Data middle right before\n");
    printf("5 . Print the Data from front to back\n");
    printf("6 . Print the Data from back to front\n");
    printf("7 . Delete the Data\n");
    printf("8 . Delete all of the Data\n");
    printf("9 . Delete first Data\n");
    printf("10. Delete last Data\n");
    printf("11. Delete after\n");
    printf("12. Delete front\n");
    printf("13. Exit\n");
    printf("your Choice:");
    scanf("%d",&decision);
    while(decision > 13){
        printf("Please enter again:");
        scanf("%d",&decision);
    }
    return decision;
}

int main(){
    int decision;
    struct person *start = (struct person *)malloc(sizeof(struct person));
    struct person *last = (struct person *)malloc(sizeof(struct person));
    start = 0;
    last = 0;
    do{
        decision = menu();
        if(decision == 1 || decision == 2){
            if(start == 0 && last == 0){
                start = createfirst(start);
                last = start;
            }else if(decision == 1){
                start = createfront(start);
            }else{
                last = createafter(last);
            }
            
        }else if(decision == 3){
            createbackmiddle(start,last);
        }else if(decision == 4){
            createfrontmiddle(start,last);
        }else if(decision == 5){
            printforward(start);
        }else if(decision == 6){
            printbackward(last);
        }else if(decision == 7){
            Delete(&start,&last);
        }else if(decision == 8){
            DeleteAll(&start,&last);
        }else if(decision == 9){
            start = DeleteFirst(start);
        }else if(decision == 10){
            last = DeleteLast(last);
        }else if(decision == 11){
            last = Deleteafter(start,last);
        }else if(decision == 12){
            start = Deletefront(start,last);
        }else{
            break;
        }
    }while(true);
    return 0;
}