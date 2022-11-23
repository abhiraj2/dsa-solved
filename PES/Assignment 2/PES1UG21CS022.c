#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100



typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

//void friends(int id, struct node *users);

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {
        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    struct node* tr = users;
    struct node* pr = NULL;
    if(!tr) return NULL;
    while(tr && tr->id != key){
        pr = tr;
        if(tr->id > key){
            tr = tr->left;
        }
        else tr = tr->right;
    }
    if(!tr){
        return NULL;
    }
    else return tr;

}

void delFre(struct node* user,struct node* users,int changed, int newSize){
    
    int i=0;
    int j=0;
    
    if(changed){
        int* newArr = (int*)malloc(MAX * sizeof(int));
        while(j<newSize){
            if(user->friends[i] == -99999){
                i++;
                continue;
            }
            else{
                newArr[j] = user->friends[i];
                j++;
                i++;
            }
            
        }
        if(!j){
            //printf("Hello\n");
            newArr[j] = -1;
        }
        free(user->friends);
        user->friends = newArr;
        user->numfren = newSize;
    }
    // for(int i=0; i<user->numfren; i++){
    //     printf("%d ", user->friends[i]);
    // }
    // printf("\n%d %d\n", user->numfren, newSize);
}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    user->left = NULL;
    user->right = NULL;
    struct node* existing = search(user->id, users);
    //if(existing)printf("%d\n", existing->id);
    while(existing){
        user->id++;
        //printf("%d\n", user->id);
        existing = search(user->id, users);     
    }


    
    int changed = 0;
    int newSize = 0;
    for(int i=0; i<user->numfren; i++){
        existing = search(user->friends[i], users);
        if(existing){
            existing->friends[existing->numfren++] = user->id;
            newSize++;
            continue;
        }
        user->friends[i] = -99999;
        changed = 1;
    }
    
    delFre(user, users,changed, newSize);

    return user;

}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{   
    struct node* tr = root;
    struct node* pr = NULL;
    while(tr){
        pr = tr;
        if(tr->id > user->id){
            tr = tr->left;
        }
        else tr = tr->right;
    }
    if(!pr){
        root = user;
    }
    else 
    if(pr->id > user->id){
        pr->left = user;
    }
    else pr->right = user;
    // for(int i=0; i<user->numfren; i++){
    //     printf("%d ", user->friends[i]);
    // }
    // printf("\n%d\n", user->numfren);
    return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
    struct node* user = search(id, users);
    if(!user){
        //printf("bro user ILlla\n");
        return;
    }
    else if(!user->numfren) printf("%d\n", -1);
    else{
        for(int i=0; i<user->numfren; i++){
            printf("%d\n", user->friends[i]);
        }
    }
}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
    struct node* tr = node;
    struct node* pr = NULL;
    while(tr){
        pr = tr;
        tr = tr->left;
    }
    return pr;
    
    //printf("Hello");
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //printf("Hello");
    struct node* user = search(key, users);
    if(!user) return NULL;
    struct node* tr;
    for(int i=0; i<user->numfren; i++){
        tr = search(user->friends[i], users);
        if(!tr) continue;
        int newSize = 0;
        int changed = 0;
        for(int j=0; j<tr->numfren; j++){
            if(tr->friends[j] == user->id){
                tr->friends[j] = -99999;
                changed = 1;
            }
            else newSize++;
        }
        delFre(tr, users, changed, newSize);
    }   
    
    return users;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    struct node *temp, *p;
    //printf("Hello");
    if(!root){
        return NULL;
    }
    if(root->id > key){
        root->left = deleteNode(root->left, key);
    }
    else if(root->id < key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(!root->left){
            temp = root->right;
            free(root);
            return temp;   
        }
        else if(!root->right){
            temp = root->left;
            free(root);
            return temp;   
        }
        else{
            p = minValueNode(root->right);
            root->id = p->id;
            strcpy(root->name, p->name);
            root->friends = p->friends;
            root->numfren = p->numfren;
            root->right = deleteNode(root->right, p->id);
        }
    }
    return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    if(!myusers) return;
    else{
        printInOrder(myusers->left);
        // for(int i=0; i<myusers->numfren; i++){
        //     printf("%d ", myusers->friends[i]);
        // }
        // printf("\n");
        printf("%d %s\n", myusers->id, myusers->name);
        printInOrder(myusers->right);
    }
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                //printf("Hello");
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                //printf("\n");
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}