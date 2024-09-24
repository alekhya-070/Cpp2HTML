// HTMLGenerator.h
#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <string>
#include <vector>

// Base class for HTML elements
class CHTMLElement {
public:
    virtual std::string ToHTMLString() const = 0; // Pure virtual function
    virtual ~CHTML() = default; // Virtual destructor
};

// Class for HTML Document
class CHTML {
public:
    void AddHTML(CHTML* element);
    std::string ToHTMLString() const;

private:
    std::vector<CHTML*> elements; // Store HTML elements
};

// Class for Body
class CBody : public CHTMLElement {
public:
    void AddHTML(CHTML* element);
    std::string ToHTMLString() const override;

private:
    std::vector<CHTML*> elements;
};

// Class for Label
class CLabel : public CHTMLElement {
public:
    CLabel(const std::string& text, const std::string& tag = "p", const std::string& color = "black");
    std::string ToHTMLString() const override;

private:
    std::string text;
    std::string tag;
    std::string color;
};

// Class for Image
class CImage : public CHTMLElement {
public:
    CImage(const std::string& src);
    std::string ToHTMLString() const override;

private:
    std::string src;
};

// Class for Link
class CLink : public CHTMLElement {
public:
    CLink(const std::string& url, const std::string& text);
    std::string ToHTMLString() const override;

private:
    std::string url;
    std::string text;
};

// Class for Table
class CTable : public CHTMLElement {
public:
    void AddRow(const std::vector<std::string>& row);
    std::string ToHTMLString() const override;

private:
    std::vector<std::vector<std::string>> rows;
};

#endif // HTML_GENERATOR_H
