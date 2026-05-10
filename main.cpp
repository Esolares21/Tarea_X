#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

struct Student {
    int student_id;
    string full_name;
    string career;
    int semester;
    int skill_score;

    Student(int id = 0, string name = "", string car = "", int sem = 0, int score = 0)
        : student_id(id), full_name(name), career(car), semester(sem), skill_score(score) {}
};

struct Node {
    Student data;
    Node *left;
    Node *right;
    int height;

    Node(Student s) : data(s), left(nullptr), right(nullptr), height(1) {}
};

class AVL {
private:
    Node* root;
    int nodeCount;

    int height(Node* n) { return n ? n->height : 0; }

    int getBalance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, Student s) {
        if (!node) {
            nodeCount++;
            return new Node(s);
        }

        if (s.skill_score < node->data.skill_score) {
            node->left = insert(node->left, s);
        } else if (s.skill_score > node->data.skill_score) {
            node->right = insert(node->right, s);
        } else {
            if (s.student_id < node->data.student_id)
                node->left = insert(node->left, s);
            else
                node->right = insert(node->right, s);
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);


        if (balance > 1 && getBalance(node->left) >= 0) return rightRotate(node);
        if (balance < -1 && getBalance(node->right) <= 0) return leftRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = leftRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void inOrder(Node* n, int &rank) {
        if (n) {
            inOrder(n->right, rank);
            cout << rank++ << ". " << n->data.full_name << " | Score: " << n->data.skill_score
                 << " | ID: " << n->data.student_id << endl;
            inOrder(n->left, rank);
        }
    }

public:
    AVL() : root(nullptr), nodeCount(0) {}

    void insert(Student s) { root = insert(root, s); }

    void displayRanking() {
        int rank = 1;
        cout << "\n--- RANKING ACADEMICO ---" << endl;
        if (!root) cout << "No hay datos aun." << endl;
        else inOrder(root, rank);
    }

    void searchByScore(int score) {
        Node* curr = root;
        while (curr) {
            if (curr->data.skill_score == score) {
                cout << "\nEstudiante encontrado: " << curr->data.full_name << endl;
                cout << "Carrera: " << curr->data.career << " | Semestre: " << curr->data.semester << endl;
                return;
            }
            curr = (score < curr->data.skill_score) ? curr->left : curr->right;
        }
        cout << "\nNo se encontro ningun estudiante con ese puntaje." << endl;
    }

    void displayStats() {
        cout << "\n--- ESTADISTICAS AVL ---" << endl;
        cout << "Altura del arbol: " << height(root) << endl;
        cout << "Factor de balance raiz: " << getBalance(root) << endl;
        cout << "Total de nodos: " << nodeCount << endl;
    }
};


void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


int main() {
    AVL tree;
    int option = 0;

    while (option != 5) {
        cout << "\n==========================================" << endl;
        cout << "  ERIX ALEJANDRO SOLARES FLORES" << endl;
        cout << "  CARNET: 9941-20-23978" << endl;
        cout << "==========================================" << endl;
        cout << "1. Insertar estudiante" << endl;
        cout << "2. Mostrar ranking academico" << endl;
        cout << "3. Buscar por skill score" << endl;
        cout << "4. Mostrar estadisticas AVL" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";

        if (!(cin >> option)) {
            cout << "Error: Por favor ingrese un numero valido." << endl;
            clearBuffer();
            continue;
        }

        switch (option) {
            case 1: {
                int id, sem, score;
                string name, car;
                cout << "ID: "; cin >> id; clearBuffer();
                cout << "Nombre completo: "; getline(cin, name);
                cout << "Carrera: "; getline(cin, car);
                cout << "Semestre: "; cin >> sem;
                cout << "Skill Score: "; cin >> score;
                tree.insert(Student(id, name, car, sem, score));
                cout << "\nRegistrado exitosamente." << endl;
                break;
            }
            case 2: tree.displayRanking(); break;
            case 3: {
                int s;
                cout << "Ingrese score a buscar: "; cin >> s;
                tree.searchByScore(s);
                break;
            }
            case 4: tree.displayStats(); break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no reconocida." << endl;
        }
    }
    return 0;
}