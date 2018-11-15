#include "crow_all.h"
#include "c_router.h"

int main() {
  crow::SimpleApp app;
  c_router(app);
  app.port(18080).multithreaded().run();
}
