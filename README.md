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

### Calculation Modes

1. **Average (Vidurkis)**: Calculates the final grade based on the average of the grades.
2. **Median (Mediana)**: Calculates the final grade based on the median of the grades.

## Example

When you run the program, you will be prompted to choose an input mode:
