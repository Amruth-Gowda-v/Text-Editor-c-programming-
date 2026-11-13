# Mini Text Editor in C

A menu-driven console utility written in C for performing basic text-file operations.

## Features visible in the source

- Create a new text file
- Open and display a file
- Append text to a file
- Search for a word and report matching line numbers
- Replace a word
- Delete a selected line
- Count words in a file

## Requirements

- A C compiler such as GCC
- A terminal or command prompt

## Compile

```bash
gcc 1.C -o mini_text_editor
```

## Run

On Linux or macOS:

```bash
./mini_text_editor
```

On Windows:

```powershell
mini_text_editor.exe
```

## Usage

Run the program and select an operation from the menu. When appending text, the current implementation uses `:q` on a new line as the stop command.

## Concepts demonstrated

C strings, arrays, pointers, functions, file I/O, string searching, tokenisation, and temporary-file workflows.

## Notes

This is a learning project. The replace and delete operations rewrite files using a temporary file; test them with disposable sample files before using important documents.
