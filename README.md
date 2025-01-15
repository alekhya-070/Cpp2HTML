# cppTOhtml
## HTMLGenerator Library

**HTMLGenerator** is a C++ library for creating HTML documents programmatically. It provides classes for various HTML elements such as labels, images, links, tables, and more, allowing you to generate structured HTML content directly in C++.

---

## Features

- **Labels:** Create styled text elements with customizable colors and tags.
- **Images:** Embed images with source URLs and alt texts.
- **Links:** Add hyperlinks with text and destination URLs.
- **Tables:** Build tables with dynamic rows and cells.
- **Document Structure:** Combine multiple elements into structured HTML documents.

---

## Installation

### Clone the Repository

```bash
git clone https://github.com/yourusername/HTMLGenerator.git
cd HTMLGenerator

```
Usage
Include the Library in Your Project
Add the HTMLGenerator.h and HTMLGenerator.cpp files to your project, or link the compiled library.
Include the header file in your code:
cpp
Copy code
#include "HTMLGenerator.h"

Directory Structure
bash
Copy code
HTMLGenerator/
├── CMakeLists.txt         # Build configuration
├── HTMLGenerator.h        # Library header
├── HTMLGenerator.cpp      # Library implementation
└── README.md              # Documentation

Building a Test Program
To build the example program:
Create a new C++ file (e.g., test.cpp) with your code.
Compile using the HTMLGenerator library:
bash
```
g++ -std=c++17 test.cpp HTMLGenerator.cpp -o test
./test
```
License
This project is licensed under the MIT License.

Contributions
Contributions are welcome! Please fork the repository, make your changes, and open a pull request.

Contact
For questions or suggestions, feel free to reach out at thealekhya070@gmail.com.

Future Enhancements
Add support for more HTML elements like forms, lists, and divs.
Enable CSS styling for more customization.
Add unit tests for improved reliability.

Thank you for using HTMLGenerator!
