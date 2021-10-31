LinkList MaxP( LinkList L)
{
    if(L==NULL)
    {
        return NULL;
    }
    LinkList p=MaxP(L->next);
    int max=L->data;
    if(p&&p->data>max){
        return p;
    }
    return L;
}
