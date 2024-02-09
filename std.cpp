// luogu-judger-enable-o2
#include <string>
#include <iostream>

const int MAXN = 205;
const int MAXM = 1e5 + 5;
const int MAXQ = 1e4 + 5;

using std::cin;
using std::cout;
using std::string;

int Rand() {
   static int seed = 39444;
   return seed = (((seed ^ 810872ll) + 1433223ll) * 19260817ll) % 2147483647;
}

struct Node{
   int key, siz;
   string name;
   Node *child[2];
   Node(string name):name(name), key(Rand()), siz(1) {
       child[0] = child[1] = NULL;
   }
   Node():key(Rand()), siz(1) {
       child[0] = child[1] = NULL;
   }
};

Node *root = NULL;

//Node book[MAXN];

int n, m, q;

void Update(Node *now) {
   now->siz = 1;
   now->siz += now->child[0] ? now->child[0]->siz : 0;
   now->siz += now->child[1] ? now->child[1]->siz : 0;
}

void Split(Node *now, int k, Node *&t1, Node *&t2) {
   if (!now) {
       t1 = t2 = NULL; return;
   } 
   if (!k) {
       t1 = NULL; t2 = now; return;
   }
   if (k >= now->size) {
       t1 = now; t2 = NULL; return;
   }
   int ls = now->child[0] ? now->child[0]->size : 0;
   if (ls >= k) {
       Node *temp;
       Split(now->child[0], k, t1, temp);
       t2 = now; t2->child[0] = temp; 
       t2->Update(); return;
   } else {
       Node *temp;
       Split(now->child[1], k - ls - 1, temp, t2);
       t1 = now; t1->child[1] = temp;
       t1->Update(); return;
   }
}

Node *Merge(Node *a, Node *b) {
   if (!a) return b;
   if (!b) return a;
   if (a->key < b->key) {
       a->child[1] = Merge(a->child[1], b);
       Update(a);
       return a;
   } else {
       b->child[0] = Merge(a, b->child[0]);
       Update(b);
       return b;
   }
}

void Insert(Node *x, int k) {
   Node *t1, *t2;
   Split(root, k - 1, t1, t2);
   root = Merge(t1, Merge(x, t2));
}

string FindKth(int pos) {
   Node *lt, *tmp;
   Split(root, pos - 1, lt, tmp);
   Node *rt, *midt;
   Split(tmp, 1, midt, rt);
   string res = midt->name;
   root = Merge(lt, Merge(midt, rt));
   return res;
}

int main() {
   cin >> n;
   string temp;
//	for (int i = 1; i <= n; i++) cin >> (book + i)->name;
//	for (int i = 1; i <= n; i++) Insert(book + i, i);
   for (int i = 1; i <= n; i++) {
       cin >> temp;
       Insert(new Node(temp), i);
   }
   cin >> m;
   int pos;
   for (int i = 1; i <= m; i++) {
       cin >> temp >> pos; pos++;
       Insert(new Node(temp), pos);
   }
   cin >> q;
   for (int i = 1; i <= q; i++) {
       cin >> pos; pos++;
       cout << FindKth(pos) << '\n';
   }
   return 0;
}
