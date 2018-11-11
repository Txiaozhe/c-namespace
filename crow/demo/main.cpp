#include "crow_all.h"

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
    return "hello world!";
  });

  CROW_ROUTE(app, "/health")([](){
    return "ok";
  });

  CROW_ROUTE(app, "/json")([](){
    crow::json::wvalue msg;
    msg["message"] = "hi, json";
    return msg;
  });

  CROW_ROUTE(app, "/json/parse")
  .methods("POST"_method)([](const crow::request& req){
    auto x = crow::json::load(req.body);
    if (!x) {
      return crow::response(400);
    }

    int sum = x["a"].i() + x["b"].i();
    std::ostringstream os;
    os << sum;
    return crow::response(os.str());
  });

  CROW_ROUTE(app, "/hello/<int>")([](int count){
    if (count > 100) {
      return crow::response(400);
    }

    std::ostringstream os;
    os << count << " bottle of beer!";
    return crow::response(os.str());
  });

  app.port(18080).multithreaded().run();
}
