// Template Method Design Pattern

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// Abstract Class
// ==========================================

class TemplateDesign {
public:

    // Template Method
    void Template(string path) {
        datproessing(path);
        modelTraining();
        evaluate();
        saveModel();
    }

protected:

    // Common step
    void dataload(string path) {
        cout << "Data loaded from " << path << endl;
    }

    // Common step
    void datproessing(string path) {
        dataload(path);
        cout << "Data Processing " << path << endl;
    }

    // Variable steps
    virtual void modelTraining() = 0;
    virtual void evaluate() = 0;
    virtual void saveModel() = 0;

public:
    virtual ~TemplateDesign() = default;
};

// ==========================================
// Concrete Class 1
// ==========================================

class NeuralNetwork : public TemplateDesign {

protected:

    void modelTraining() override {
        cout << "Neural Network Training" << endl;
    }

    void evaluate() override {
        cout << "Neural Network Evaluated Training Data" << endl;
    }

    void saveModel() override {
        cout << "Neural Network Model Saved" << endl;
    }
};

// ==========================================
// Concrete Class 2
// ==========================================

class DecisionTreeNetwork : public TemplateDesign {

protected:

    void modelTraining() override {
        cout << "Decision Tree Training" << endl;
    }

    void evaluate() override {
        cout << "Decision Tree Evaluated Training Data" << endl;
    }

    void saveModel() override {
        cout << "Decision Tree Model Saved" << endl;
    }
};

// ==========================================
// Client
// ==========================================

int main() {

    TemplateDesign* nn = new NeuralNetwork();

    nn->Template("/desktop/data.csv");

    cout << "========================================================"
         << endl;

    TemplateDesign* dt = new DecisionTreeNetwork();

    dt->Template("/desktop/data.csv");

    delete nn;
    delete dt;

    return 0;
}