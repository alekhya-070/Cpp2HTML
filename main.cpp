#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // Include this header for std::stringstream
#include <list>

using namespace std;

class CHTML
{
protected:
    list<CHTML *> InnerHTMLList;

public:
    void AddHTML(CHTML *HTMLObj);
    virtual string ToHTMLString();
};

void CHTML::AddHTML(CHTML *HTMLObj)
{
    InnerHTMLList.push_back(HTMLObj);
}

string CHTML::ToHTMLString()
{
    string strInnerHTML;
    for (CHTML *InnerHTMLItem : InnerHTMLList)
    {
        strInnerHTML += InnerHTMLItem->ToHTMLString();
    }
    return strInnerHTML;
}

class CBody : public CHTML
{
public:
    string ToHTMLString() override;
};

string CBody::ToHTMLString()
{
    return "<body>" + CHTML::ToHTMLString() + "</body>";
}

class CLabel : public CHTML
{
public:
    string LabelContent;
    string Size;
    string Color;

    CLabel(string content, string size = "h1", string color = "black")
        : LabelContent(content), Size(size), Color(color) {}

    string ToHTMLString() override
    {
        string labelHTML = "<font color='" + Color + "'>";
        if (Size == "h1")
            labelHTML += "<h1>" + LabelContent + "</h1>";
        else if (Size == "h2")
            labelHTML += "<h2>" + LabelContent + "</h2>";
        else if (Size == "h3")
            labelHTML += "<h3>" + LabelContent + "</h3>";
        else if (Size == "h4")
            labelHTML += "<h4>" + LabelContent + "</h4>";
        else if (Size == "h5")
            labelHTML += "<h5>" + LabelContent + "</h5>";
        else if (Size == "h6")
            labelHTML += "<h6>" + LabelContent + "</h6>";
        labelHTML += "</font>";
        return labelHTML;
    }
};

class CImage : public CHTML
{
public:
    string Path;

    CImage(string path) : Path(path) {}

    string ToHTMLString() override
    {
        return "<img src=\"" + Path + "\">";
    }
};

class CLink : public CHTML
{
public:
    string Url;
    string UrlText;

    CLink(string url, string urlText) : Url(url), UrlText(urlText) {}

    string ToHTMLString() override
    {
        return "<a href=\"" + Url + "\">" + UrlText + "</a>";
    }
};

class CTable : public CHTML
{
private:
    vector<vector<string>> rows;

public:
    void AddRow(const vector<string> &row)
    {
        rows.push_back(row);
    }

    string ToHTMLString() override
    {
        string strInnerHTML = "<table border=\"1\">\n";
        for (const auto &row : rows)
        {
            strInnerHTML += "  <tr>\n";
            for (const auto &cell : row)
            {
                strInnerHTML += "    <td>" + cell + "</td>\n";
            }
            strInnerHTML += "  </tr>\n";
        }
        strInnerHTML += "</table>";
        return strInnerHTML;
    }
};

class CForm : public CHTML
{
public:
    string Action;
    string Method;

    CForm(string action = "", string method = "GET")
        : Action(action), Method(method) {}

    string ToHTMLString() override
    {
        string strInnerHTML = "<form action=\"" + Action + "\" method=\"" + Method + "\">\n";
        strInnerHTML += CHTML::ToHTMLString();
        strInnerHTML += "</form>";
        return strInnerHTML;
    }
};

class CInput : public CHTML
{
public:
    string Type;
    string Name;
    string Value;
    string Placeholder;

    CInput(string type, string name, string value, string placeholder)
        : Type(type), Name(name), Value(value), Placeholder(placeholder) {}

    string ToHTMLString() override
    {
        return "<input type=\"" + Type + "\" name=\"" + Name + "\" value=\"" + Value + "\" placeholder=\"" + Placeholder + "\">";
    }
};

class CButton : public CHTML
{
public:
    string Type;
    string Text;

    CButton(string type, string text) : Type(type), Text(text) {}

    string ToHTMLString() override
    {
        return "<button type=\"" + Type + "\">" + Text + "</button>";
    }
};

int main()
{
    ofstream fout;
    string desktopPath = "C:\\Users\\nagaa\\Desktop\\generatedPage.html"; // Change this path accordingly

    CHTML *myHTML = new CHTML();
    CBody *myBody = new CBody();

    // User input for label
    string labelContent;
    cout << "Enter label content: ";
    getline(cin, labelContent);
    CLabel *myLabel = new CLabel(labelContent, "h1", "red");

    // User input for image path
    string imagePath;
    cout << "Enter image path: ";
    getline(cin, imagePath);
    CImage *myImage = new CImage(imagePath);

    // User input for link
    string url, urlText;
    cout << "Enter URL: ";
    getline(cin, url);
    cout << "Enter link text: ";
    getline(cin, urlText);
    CLink *myLink = new CLink(url, urlText);

    // Create a table
    CTable *myTable = new CTable();
    int rowsCount;
    cout << "Enter number of rows for the table: ";
    cin >> rowsCount;
    cin.ignore(); // Ignore the newline character after the integer input

    for (int i = 0; i < rowsCount; i++)
    {
        vector<string> row;
        string cell;
        cout << "Enter cells for row " << (i + 1) << " (separated by space): ";
        getline(cin, cell);
        stringstream ss(cell);
        string cellValue;
        while (ss >> cellValue)
        {
            row.push_back(cellValue);
        }
        myTable->AddRow(row);
    }

    // Create a form
    CForm *myForm = new CForm("submit.php", "POST");
    CInput *input1 = new CInput("text", "username", "", "Enter your username");
    CInput *input2 = new CInput("password", "password", "", "Enter your password");
    CButton *submitButton = new CButton("submit", "Submit");

    myForm->AddHTML(input1);
    myForm->AddHTML(input2);
    myForm->AddHTML(submitButton);

    // Add components to body
    myBody->AddHTML(myLink);
    myBody->AddHTML(myImage);
    myBody->AddHTML(myLabel);
    myBody->AddHTML(myTable);
    myBody->AddHTML(myForm);

    myHTML->AddHTML(myBody);

    // Generate HTML string
    string htmlContent = "<html>\n" + myHTML->ToHTMLString() + "\n</html>";

    // Write to file
    fout.open(desktopPath);
    fout << htmlContent;
    fout.close();

    cout << "HTML file generated at: " << desktopPath << endl;

    // Cleanup
    delete myHTML;
    delete myBody;
    delete myLabel;
    delete myImage;
    delete myLink;
    delete myTable;
    delete myForm;
    delete input1;
    delete input2;
    delete submitButton;

    return 0;
}
