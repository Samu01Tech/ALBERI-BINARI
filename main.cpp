#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Tdato{
  int numero;
  //metodi
  Tdato(){
    numero = 0;
  }
  Tdato(int x){
    numero = x;
  }
  ~Tdato(){
    //
  }
  void stampa() const{
    cout << numero;
  }
} Tdato;

typedef struct Tnodo{
  Tdato dato;
  Tnodo* parent;
  Tnodo* left;
  Tnodo* right;
  Tnodo(){
    dato = Tdato();
    parent = NULL;
    left = NULL;
    right = NULL;
  }
  Tnodo(Tdato _dato, Tnodo*_parent, Tnodo* _left, Tnodo* _right){
    dato = _dato;
    parent = _parent;
    left = _left;
    right = _right;
  }
  ~Tnodo(){
    //
  }
  void stampa() const{
    dato.stampa();
  }
}Tnodo;

Tnodo* costruisci(Tdato d, Tnodo* sx, Tnodo* dx);
void visit(Tnodo* n);
void preorder(Tnodo* h, void visit(Tnodo*));
void inorder(Tnodo* h, void visit(Tnodo*));
void postorder(Tnodo* h, void visit(Tnodo*));
Tnodo* Tree_Min(Tnodo* t);
Tnodo* Tree_Max(Tnodo* t);
int contaNodi(Tnodo* h );
int height (Tnodo* h);
int path_length(Tnodo* n);
int path_length_recur(Tnodo* n, int h);

int main() {

}

Tnodo* costruisci(Tdato d, Tnodo* sx, Tnodo* dx){
  Tnodo* radice;
  radice = new Tnodo();
  radice->dato = d;
  radice->left = sx;
  radice->right = dx;
  return radice;
  // oppure // return new Nodo(d, sx, dx);
}

void visit(Tnodo* n){
  n->stampa();
}

void preorder(Tnodo* h, void visit(Tnodo*)) {
  if (h == NULL) return;
  visit(h);
  preorder(h->left, visit);
  preorder(h->right, visit);
}

void inorder(Tnodo* h, void visit(Tnodo*)) {
  if (h == NULL) return;
  inorder(h->left, visit);
  visit(h);
  inorder(h->right, visit);
}

void postorder(Tnodo* h, void visit(Tnodo*)) {
  if (h == NULL) return;
  postorder(h->left, visit);
  postorder(h->right, visit);
  visit(h);
}

Tnodo* Tree_Min(Tnodo* t) {
  // assumiamo t != NULL
  while(t->left != NULL)
  t = t->left;
  return t;
}

Tnodo* Tree_Max(Tnodo* t) {
// assumiamo t != NULL
while(t->right != NULL)
t = t->right;
return t;
}

int contaNodi(Tnodo* h ) {
  if (h == NULL) return 0;
  return contaNodi(h->left) + contaNodi(h->right) + 1;
}

int height (Tnodo* h) {
  if (h == NULL) { return -1; }
  int u = height(h->left);
  int v = height(h->right);
  if (u > v) return u+1;
  return v + 1;
}

int path_length(Tnodo* n) {
  return path_length_recur(n, 0);
}
int path_length_recur(Tnodo* n, int h) {
  if (n == NULL) { return 0;}
  int ll = path_length_recur(n->left, h+1);
  int lr = path_length_recur(n->right, h+1);
  return h + ll + lr;
}