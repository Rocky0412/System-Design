#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// =========================
// Flyweight
// =========================
class TreeType {
private:
    string name;
    string color;
    string texture;

public:
    TreeType(string name, string color, string texture) {
        this->name = name;
        this->color = color;
        this->texture = texture;
    }

    void display(int x, int y) {
        cout << "Tree : " << name
             << ", Color : " << color
             << ", Texture : " << texture
             << ", Position : (" << x << ", " << y << ")"
             << endl;
    }
};

// =========================
// Flyweight Factory
// =========================
class TreeFactory {
private:
    unordered_map<string, TreeType*> cache;

public:
    TreeType* getTreeType(string name,
                          string color,
                          string texture) {

        string key = name + color + texture;

        // Create only if this TreeType doesn't already exist
        if (cache.find(key) == cache.end()) {

            cout << "Creating Flyweight : "
                 << name << endl;

            cache[key] = new TreeType(
                name,
                color,
                texture
            );
        }

        // Return existing/shared object
        return cache[key];
    }
};

// =========================
// Context
// =========================
class Tree {
private:
    int x;
    int y;

    TreeType* type;

public:
    Tree(int x, int y, TreeType* type) {
        this->x = x;
        this->y = y;
        this->type = type;
    }

    void draw() {
        type->display(x, y);
    }
};

// =========================
// Client
// =========================
int main() {

    TreeFactory factory;

    vector<Tree> forest;

    // Same TreeType requested multiple times
    TreeType* mango = factory.getTreeType(
        "Mango",
        "Green",
        "Texture1"
    );

    TreeType* mango2 = factory.getTreeType(
        "Mango",
        "Green",
        "Texture1"
    );

    // Different TreeType
    TreeType* apple = factory.getTreeType(
        "Apple",
        "Red",
        "Texture2"
    );

    forest.push_back(Tree(10, 20, mango));
    forest.push_back(Tree(30, 40, mango));
    forest.push_back(Tree(50, 60, mango));

    forest.push_back(Tree(70, 80, apple));

    for (auto& tree : forest) {
        tree.draw();
    }

    cout << "\nMango Address  : " << mango << endl;
    cout << "Mango2 Address : " << mango2 << endl;
    cout << "Apple Address  : " << apple << endl;

    return 0;
}