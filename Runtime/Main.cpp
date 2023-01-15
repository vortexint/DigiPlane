#include "./Runtime.hpp"

int main(int argc, char** argv) {
    Digiplane::ApplicationContext* app = new Digiplane::ApplicationContext();
    //app->run();
    delete app;
    return 0;
}