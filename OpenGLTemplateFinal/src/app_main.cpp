#include "App.h"

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv);

    app->run();
}
