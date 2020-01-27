#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

#define pow2(n) (1 << (n))
using namespace std;

struct avl {
    int value;
    struct avl *l;
    struct avl *r;
} *root;

class avlTree {
    public:
        int height(avl*);
        int difference(avl*);
        avl* rrRotate(avl*);
        avl* llRotate(avl*);
        avl* lrRotate(avl*);
        avl* rlRotate(avl*);
        avl* balance(avl*);
        avl* insert(avl*, int);
        void show(avl*, int);
        void inOrder(avl*);
        void preOrder(avl*);
        void postOrder(avl*);
        avlTree() {
            root = NULL;
        }

};

int avlTree::height(avl *t) {
    int h = 0;
    if (t != NULL) {
        int lHeight = height(t->l);
        int rHeight = height(t->r);
        int maxHeight = max(lHeight, rHeight);
        h = maxHeight + 1;
    }
    return h;
}

int avlTree::difference(avl *t) {
    int lHeight = height(t->l);
    int rHeight = height(t->r);
    int bFactor = lHeight - rHeight;
    return bFactor;
}

avl *avlTree::rrRotate(avl *parent) {
    avl* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout << "Right-Right Rotation";
    return t;
}

avl *avlTree::llRotate(avl *parent) {
    avl* t;
    t = parent->l;
    parent->l = t->r;
    t->l = parent;
    cout << "Left-Left Rotation";
    return t;
}

avl *avlTree::lrRotate(avl *parent) {
    avl* t;
    t = parent->l;
    parent->l = rrRotate(t);
    cout << "Left-Right Rotation";
    return llRotate(parent);
}

avl *avlTree::rlRotate(avl *parent) {
    avl* t;
    t = parent->r;
    parent->r = llRotate(t);
    cout << "Right-Left Rotation";
    return rrRotate(parent);
}

avl *avlTree::balance(avl *t) {
    int bal_factor = difference(t);
    if(bal_factor > 1) {
        if(difference(t->l) > 0)
            t = llRotate(t);
        else
            t = lrRotate(t);
    } else if(bal_factor < -1) {
        if(difference(t->r) > 0)
            t = rlRotate(t);
        else
            t = rrRotate(t);
    }
    return t;
}

avl *avlTree::insert(avl *root, int v) {
    if(root == NULL) {
        root = new avl;
        root->value = v;
        root->l = NULL;
        root->r = NULL;
        return root;
    } else if(v < root->value) {
        root->l = insert(root->l, v);
        root = balance(root);
    } else if(v >= root->value) {
        root->r = insert(root->r, v);
        root = balance(root);
    }
    return root;
}

void avlTree::show(avl *p, int l) {
    int i;
    if (p != NULL) {
        show(p->r, l + 1);
        cout << " ";
        if(p == root)
            cout << "Root -> ";
        for(i = 0; i < l && p!= root; i++)
            cout << " ";
            cout << p->value;
            show(p->l, l + 1);
    }
}

/**
 * InOrder traversal method
 *          A
 *       B    C
 * Output: B, A, C
 * @param t - tree
 */
void avlTree::inOrder(avl *t) {
    if(t == NULL)
        return;
    inOrder(t->l);
    cout << t->value << " ";
    inOrder(t->r);
}

/**
 * PreOrder traversal method
 *          A
 *       B    C
 * Output: A, B, C
 * @param t - tree
 */
void avlTree::preOrder(avl *t) {
    if(t == NULL)
        return;
    cout << t->value << " ";
    preOrder(t->l);
    preOrder(t->r);
}

/**
 * PostOrder traversal method
 *          A
 *       B    C
 * Output: B, C, A
 * @param t - tree
 */
void avlTree::postOrder(avl *t) {
    if(t == NULL)
        return;
    postOrder(t->l);
    postOrder(t->r);
    cout << t->value << " ";
}

int main() {
    int c, i;
    avlTree avl;

    while(1) {
        cout << "1.Insert Element into the tree" << endl;
        cout << "2.show Balanced AVL Tree" << endl;
        cout << "3.InOrder traversal" << endl;
        cout << "4.PreOrder traversal" << endl;
        cout << "5.PostOrder traversal" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> i;
                root = avl.insert(root, i);
                break;
            case 2:
                if (root == NULL) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.show(root, 1);
                cout<<endl;
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                avl.inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                avl.preOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                avl.postOrder(root);
                cout << endl;
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
}