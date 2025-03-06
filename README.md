# Student Grades Management System

This project is a simple C++ application that allows users to manage student grades. The application provides three modes for inputting student data: manual input, semi-random generation, and fully random generation. It also allows users to calculate the final grades based on either the average or median of the grades.

## Files

- `header.h`: Contains the necessary includes and using declarations.
- `functions.cpp`: Contains the implementation of the `Manual`, `Semi`, and `Auto` functions for managing student data.
- `functions1.cpp`: Contains an alternative implementation of the `Manual`, `Semi`, and `Auto` functions using dynamic arrays.
- `masyvas.cpp`: Main program file that uses the implementation from `functions1.cpp`.
- `vektorius.cpp`: Main program file that uses the implementation from `functions.cpp`.
- `.vscode/settings.json`: VS Code settings for file associations.
- `.vscode/tasks.json`: VS Code tasks for building the project.
- `.gitignore`: Specifies files and directories to be ignored by Git.

## Usage

### Building the Project

To build the project, you can use the provided VS Code tasks. Open the command palette (Ctrl+Shift+P) and select `Tasks: Run Build Task`.

### Running the Program

After building the project, you can run the executable files (`masyvas.exe` or `vektorius.exe`) from the terminal or directly from the file explorer.

### Input Modes

1. **Manual Input**: Allows the user to manually input student data.
2. **Semi-Random Generation**: Generates student data with random grades.
3. **Fully Random Generation**: Generates student data with random names and grades.
4. **Read from file**: Read data from user's selected file.

### Output Modes

1. **Console**: Prints results in console.
2. **File**: Prints results in file.

### Calculation Modes

1. **Average (Vidurkis)**: Calculates the final grade based on the average of the grades.
2. **Median (Mediana)**: Calculates the final grade based on the median of the grades.

### Sorting Modes

User can choose to sort by name, surname or final grade.

### Testing Times

1. **1k**: file create - 0.035 s, file read - 0.007 s, file distribution - 0.001 s, print - 0.011 s, total - 0.054 s
2. **10k**: file create - 0.219 s, file read - 0.095 s, file distribution - 0.004 s, print - 0.077 s, total - 0.395 s
3. **100k**: file create - 1.798 s, file read - 0.687 s, file distribution - 0.021 s, print - 0.771 s, total - 3.277 s
4. **1m**: file create - 16.223 s, file read - 5.462, file distribution - 0.220 s,, print - 7.575 s, total - 29.480 s
5. **10m**: file create - 167.577 s, file read - error, will be fixed...