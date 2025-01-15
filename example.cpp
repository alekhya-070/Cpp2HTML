#include "HTMLGenerator.h"
#include <iostream>
#include <memory>

int main() {
    using namespace HTMLGenerator;

    auto body = std::make_shared<CBody>();
    body->AddHTML(std::make_shared<CLabel>("Hello, World!", "h1", "blue"));
    body->AddHTML(std::make_shared<CImage>("image.jpg"));
    body->AddHTML(std::make_shared<CLink>("https://example.com", "Click Here"));

    auto table = std::make_shared<CTable>();
    table->AddRow({"Name", "Age"});
    table->AddRow({"Alice", "25"});
    table->AddRow({"Bob", "30"});
    body->AddHTML(table);

    CHTML htmlDocument;
    htmlDocument.AddHTML(body);

    std::cout << htmlDocument.ToHTMLString() << std::endl;

    return 0;
}
