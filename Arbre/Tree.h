#include <iostream>
#include <queue>
using namespace std;

class Arb {
private:
    struct Tree {
        int value;
        Tree* left;
        Tree* right;
        Tree(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    void ajouterElement(Tree*& node, int val) {
        if (!node) {  
            node = new Tree(val);
        }
        else {
           
            queue<Tree*> file;
            file.push(node);

            while (!file.empty()) {
                Tree* temp = file.front();
                file.pop();

                if (!temp->left) {
                    temp->left = new Tree(val);
                    return;
                }
                else {
                    file.push(temp->left);
                }
                if (!temp->right) {
                    temp->right = new Tree(val);
                    return;
                }
                else {
                    file.push(temp->right);
                }
            }
        }
    }

    
    void parcoursProfondeur(Tree* node) const {
        if (node) {
            parcoursProfondeur(node->left);
            cout << node->value << " ";   
         
            parcoursProfondeur(node->right); 
        }
    }
    void parcoursLargeur(Tree* node) const {
        if (!node) return;

        queue<Tree*> file;
        file.push(node);

        while (!file.empty()) {
            Tree* temp = file.front();
            file.pop();

            cout << temp->value << " ";

            if (temp->left) file.push(temp->left);
            if (temp->right) file.push(temp->right);
        }
    }

    void parcoursPostfixe(Tree* node) const {
        if (node) {
            parcoursPostfixe(node->left);
            parcoursPostfixe(node->right);
            cout << node->value << " ";
        }
    }
    void parcoursPrefixe(Tree* node) const {
        if (node) {
            cout << node->value << " ";
            parcoursPrefixe(node->left);
            parcoursPrefixe(node->right);
        }
    }
public:
    Tree* root;

    Arb() : root(nullptr) {}

    void ajouter(int val) {
        ajouterElement(root, val);
    }

    void afficherProfondeur() const {
        cout << "Parcours en profondeur  : ";
        parcoursProfondeur(root);
        cout << endl;
    }
    void afficherLargeur() const {
        cout << "Parcours en Largeur : ";
        parcoursLargeur(root);
        cout << endl;
    }
    void afficherPostfixe() const {
        cout << "Parcours Postfixe : ";
        parcoursPostfixe(root);
        cout << endl;
    }
    void afficherPrefixe() const {
        cout << "Parcours Préfixe : ";
        parcoursPrefixe(root);
        cout << endl;
    }
};
