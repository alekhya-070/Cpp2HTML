// main.cpp
#include <iostream>
#include <fstream>
#include "HTMLGenerator.h" // Include the HTML generator header

int main() {
    // Create an HTML document
    CHTML myHTML;
    CBody myBody;

    // Create and customize HTML elements
    CLabel myLabel("Welcome to My Website!", "h1", "blue");
    CImage myImage("path/to/image.jpg");
    CLink myLink("https://www.example.com", "Visit Example");
    CTable myTable;
    myTable.AddRow({"Header 1", "Header 2"});
    myTable.AddRow({"Row 1 Col 1", "Row 1 Col 2"});

    // Add elements to the body
    myBody.AddHTML(&myLabel);
    myBody.AddHTML(&myImage);
    myBody.AddHTML(&myLink);
    myBody.AddHTML(&myTable);

    // Add body to HTML document
    myHTML.AddHTML(&myBody);

    // Write HTML to file
    std::ofstream fout("output.html");
    fout << "<html>\n" << myHTML.ToHTMLString() << "\n</html>";
    fout.close();

    std::cout << "HTML file created successfully!" << std::endl;

    return 0;
}
