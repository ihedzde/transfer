#include <iostream>
#include "DOM/Engine.h"
#include "DOM/JetEngine.h"
#include "DOM/DieselEngine.h"

using namespace DOM;
int main() {
    Engine *jetEngine = new JetEngine();
    Engine *diselEngine = new DieselEngine();
    jetEngine->show();
    std::cout<< std::endl;
    diselEngine->show();
    delete jetEngine;
    delete diselEngine;
    return 0;
}
