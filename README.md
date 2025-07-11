# 📇 Address Book Application in C (CSV Integration)

A simple and functional terminal-based Address Book application developed in C, designed as part of the *Certified Embedded Professional Program* at **Emertxe Information Technologies, Bangalore**.

This project demonstrates real-world data management using C with persistent storage via CSV files — compatible with tools like Microsoft Excel for easy external access and sharing.

---

## 🔧 Features

- ➕ **Add Contact** – Store new contact details
- 🔍 **Search Contact** – Lookup by name, mobile number, or email
- ✏️ **Edit Contact** – Modify existing contact information
- ❌ **Delete Contact** – Remove contacts from the address book
- 📋 **List All Contacts** – Display all stored entries
- 📂 **CSV File Storage** – Saves data in `.csv` format viewable in Excel

---

## 💡 Highlights

- 📵 **Duplicate Detection** – Avoids duplicate mobile number entries
- 🛑 **Input Validation** – Checks for invalid inputs
- ✅ **Confirmation & Error Messages** – Feedback for all actions
- 🧱 **Modular Code Structure** – Functions separated for clarity and reuse
- 🧠 **Memory-Safe Design** – Uses dynamic memory and pointer logic carefully

---

## 📁 File Structure

```bash
.
├── main.c                # Entry point and menu logic
├── address_book.c        # Core logic for add/search/edit/delete/display
├── address_book.h        # Header file with struct and function declarations
├── contacts.csv          # Stores contact data in CSV format
├── Makefile              # Optional: Build automation (if applicable)
└── README.md             # Project overview and documentation
```

🧠 Concepts Covered
File Handling in C (fopen, fgets, fprintf, fscanf, etc.)

CSV Format Parsing and Integration

Dynamic Memory Allocation (malloc, realloc, free)

Structures and Pointers in C

Function Modularization and Clean Code Practices

Terminal-based Menu-Driven Interface

✅ How to Run
```
gcc main.c address_book.c -o addressbook
./addressbook
```

🧑‍💻 Author
Suhas
📚 Embedded Systems & C Developer
🔗 https://www.linkedin.com/in/suhas-a-b-6810b3317/

🏷️ Tags
#CProgramming #EmbeddedC #CSVIntegration #FileHandlingInC #SystemProgramming #TerminalApp #Emertxe #ModularDesign #PointersInC #TechPortfolio
