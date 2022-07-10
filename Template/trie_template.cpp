//2-1-20
#include<bits/stdc++.h>
using namespace std;

struct node
{

    bool endmark;
    node *next[27];

    node()
    {
        endmark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }


}*root;

void insert(string str)
{
    int len = str.size();
    node *curr=root;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'a' ;
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }

    curr->endmark = 1;
}

bool search(string str)
{
    int len =str.size();
    node *curr = root;

    for(int i=0; i<len; i++)
    {
        int id = str[i]-'a';
        if(curr->next[id] == NULL)
            return false;
        curr=curr->next[id];
    }

    return curr->endmark;
}

void del(node *curr)
{
    for(int i=0; i<26; i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }

    del(curr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    printf("Enter number of words : ");
    root = new node();
    int num_word;
    cin>>num_word;

    while()
    {
        string str;
        cin>>str;
        insert(str);
    }

    printf("Enter number of query : ");

    int query;
    cin>>query;

    while(query--)
    {
        string str;
        cin>>str;

        if(search(str))
            puts("found");
        else
            puts("not found");
    }
     del(root);

    return 0;
}
