
// HTMLGenerator.cpp
#include "HTMLGenerator.h"

// CLabel implementation
CLabel::CLabel(const std::string& text, const std::string& tag, const std::string& color)
    : text(text), tag(tag), color(color) {}

std::string CLabel::ToHTMLString() const {
    return "<" + tag + " style='color:" + color + "'>" + text + "</" + tag + ">";
}

// CImage implementation
CImage::CImage(const std::string& src) : src(src) {}

std::string CImage::ToHTMLString() const {
    return "<img src='" + src + "' alt='Image'>";
}

// CLink implementation
CLink::CLink(const std::string& url, const std::string& text)
    : url(url), text(text) {}

std::string CLink::ToHTMLString() const {
    return "<a href='" + url + "'>" + text + "</a>";
}

// CTable implementation
void CTable::AddRow(const std::vector<std::string>& row) {
    rows.push_back(row);
}

std::string CTable::ToHTMLString() const {
    std::string table = "<table>";
    for (const auto& row : rows) {
        table += "<tr>";
        for (const auto& cell : row) {
            table += "<td>" + cell + "</td>";
        }
        table += "</tr>";
    }
    table += "</table>";
    return table;
}

// CHTML implementation
void CHTML::AddHTML(CHTML* element) {
    elements.push_back(element);
}

std::string CHTML::ToHTMLString() const {
    std::string html;
    for (const auto& element : elements) {
        html += element->ToHTMLString() + "\n";
    }
    return html;
}

// CBody implementation
void CBody::AddHTML(CHTML* element) {
    elements.push_back(element);
}

std::string CBody::ToHTMLString() const {
    std::string body = "<body>\n";
    for (const auto& element : elements) {
        body += element->ToHTMLString();
    }
    body += "</body>";
    return body;
}
