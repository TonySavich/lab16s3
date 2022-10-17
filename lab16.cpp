#include <iostream>
#include <stack>


struct tree {
    int znach;
    tree* l;
    tree* r;
    tree* p;
};



void obhod (tree* t)
{
    std::stack<tree*> s;
    s.push(NULL);
    tree* tt = t;
    do {
        if (tt != NULL) {
            s.push(tt);
            std::cout << tt->znach << '\n';
            tt = tt->l;
        }
        else {
            if (s.top() == NULL) break;
            tt = s.top();
            s.pop();
            tt = tt->r;
        }
    } while (true);
}

struct tree* addtr(struct tree* rt, std::string& s) {



    if (s[0] == '(' && s[1] != ',' && s.length() > 2) {
        s.erase(0, 1);
        rt->l = (struct tree*)malloc(sizeof(struct tree));
        rt->l->znach = (int)s[0] - 48;
        rt->l->l = rt->l->r = NULL;
        rt->l->p = rt;
        s.erase(0, 1);
        rt->l = addtr(rt->l, s);
    }



    if (s[0] == ',' && s.length() > 2) {

        s.erase(0, 1);
        if (rt->p != NULL) {
            rt->p->r = (struct tree*)malloc(sizeof(struct tree));
            rt->p->r->znach = (int)s[0] - 48;
            rt->p->r->l = rt->p->r->r = NULL;
            rt->p->r->p = rt->p;
            s.erase(0, 1);
            rt->p->r = addtr(rt->p->r, s);
        }
        else {
            rt->r = (struct tree*)malloc(sizeof(struct tree));
            rt->r->znach = (int)s[0] - 48;
            rt->r->l = rt->r->r = NULL;
            rt->r->p = rt;
            s.erase(0, 1);
            rt->r = addtr(rt->r, s);
        }

    }
    if ((s[0] == ')' || s[0] == '(' && s[1] == ',') && s.length() > 2) {
        s.erase(0, 1);
        if (rt->p != NULL) {
            rt->p = addtr(rt->p, s);
        }
        else {
            rt = addtr(rt, s);
        }
    }


    return rt;
}





int main()
 {
    std::string tx;
    std::cin >> tx;
    struct tree* root;
    root = NULL;



    root = (struct tree*)malloc(sizeof(struct tree));
    root->znach = (int)tx[0] - 48;
    root->l = root->r = root->p = NULL;



    if (tx.length() > 1) {
        tx.erase(0, 1);

    }

    if (tx.length() > 1) {
        root = addtr(root, tx);
    }


    std::cout << std::endl;
    obhod(root);
}
