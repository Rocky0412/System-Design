#include <iostream>
#include <string>

using namespace std;

// =======================
// Subsystem 1
// =======================

class Light {
public:
    void OnLight() {
        cout << "Light On" << endl;
    }

    void OffLight() {
        cout << "Light Off" << endl;
    }
};


// =======================
// Subsystem 2
// =======================

class Screen {
public:
    void Down() {
        cout << "Screen Down" << endl;
    }

    void Up() {
        cout << "Screen Up" << endl;
    }
};


// =======================
// Subsystem 3
// =======================

class Projector {
public:
    void On() {
        cout << "Projector On" << endl;
    }

    void Off() {
        cout << "Projector Off" << endl;
    }

    void SetInput(string input) {
        cout << "Projector input set to " << input << endl;
    }
};


// =======================
// Subsystem 4
// =======================

class SoundSystem {
public:
    void On() {
        cout << "Sound System On" << endl;
    }

    void Off() {
        cout << "Sound System Off" << endl;
    }

    void SetVolume(int volume) {
        cout << "Volume set to " << volume << endl;
    }
};


// =======================
// Facade
// =======================

class FacadeClass {

private:
    Light light;
    Screen screen;
    Projector projector;
    SoundSystem soundSystem;

public:

    void WatchMovie() {

        cout << "\nStarting movie...\n";

        light.OffLight();
        screen.Down();

        projector.On();
        projector.SetInput("HDMI");

        soundSystem.On();
        soundSystem.SetVolume(50);

        cout << "Movie Started!\n";
    }

    void StopMovie() {

        cout << "\nStopping movie...\n";

        soundSystem.Off();
        projector.Off();

        screen.Up();
        light.OnLight();

        cout << "Movie Stopped!\n";
    }
};


// =======================
// Client
// =======================

int main() {

    FacadeClass homeTheater;

    // Client doesn't need to know
    // about Light, Screen, Projector, etc.

    homeTheater.WatchMovie();

    homeTheater.StopMovie();

    return 0;
}