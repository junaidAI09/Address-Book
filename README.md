# Address Book

A menu-driven Address Book application developed in C to manage contact information.

## Overview

This project provides a simple way to organize contact details such as names, phone numbers, and email addresses. It uses structured programming and file handling concepts in C.

## Features

- Contact information management
- Store name, phone number, and email address
- Display all saved contacts in a structured directory format
- File handling for contact data storage
- Menu-driven interface

## Technologies Used

- Programming Language: C
- Concepts: Structures, Functions, Arrays, Pointers, File Handling
- Standard: C11
- Compiler: GCC

## Compilation

Compile the project using:

```bash
gcc -Wall -Wextra -std=c11 main.c contact.c file.c populate.c -o addressbook
```

## Usage

Run the application:

```bash
./addressbook
```

Follow the menu options to interact with the Address Book.

## Project Structure

- `main.c` – Main program
- `contact.c`, `contact.h` – Contact management functions
- `file.c`, `file.h` – File handling operations
- `populate.c`, `populate.h` – Contact population functions
- `contacts.txt` – Contact data file

## Author

Junaid Gadagkar
