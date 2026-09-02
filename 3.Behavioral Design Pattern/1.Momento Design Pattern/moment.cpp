#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Memento
class Memento {
private:
    string content;

public:
    Memento(string content) {
        this->content = content;
    }

    string getContent() {
        return content;
    }
};

// Originator
class Editor {
private:
    string content;

public:
    void write(string text) {
        content += text;
    }

    void show() {
        cout << "Current Content: " << content << endl;
    }

    // Save current state
    Memento save() {
        return Memento(content);
    }

    // Restore previous state
    void restore(Memento memento) {
        content = memento.getContent();
    }
};

// Caretaker
class History {
private:
    vector<Memento> history;

public:
    void save(Memento memento) {
        history.push_back(memento);
    }

    Memento undo() {
        Memento memento = history.back();
        history.pop_back();
        return memento;
    }

    bool canUndo() {
        return !history.empty();
    }
};

int main() {

    Editor editor;
    History history;

    // Initial state
    history.save(editor.save());

    editor.write("Hello ");
    history.save(editor.save());

    editor.write("World");
    history.save(editor.save());

    editor.show();

    // Undo
    if (history.canUndo()) {
        history.undo();       // remove current state
        editor.restore(history.undo());
    }

    editor.show();

    return 0;
}