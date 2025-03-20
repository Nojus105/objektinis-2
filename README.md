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

### Testing Times (vector)

1. **1k**: file create - 0.035 s, file read - 0.007 s, file sort - 0 s, file distribution - 0 s, print - 0.011 s, total - 0.054 s
2. **10k**: file create - 0.219 s, file read - 0.095 s, file sort - 0.017 s, file distribution - 0.004 s, print - 0.077 s, total - 0.412 s
3. **100k**: file create - 1.798 s, file read - 0.687 s, file sort - 0.138 s, file distribution - 0.021 s, print - 0.771 s, total - 3.415 s
4. **1m**: file create - 16.223 s, file read - 5.462 s, file sort - 1.597 s, file distribution - 0.220 s,, print - 7.575 s, total - 31.077 s
5. **10m**: file create - 167.577 s, file read - crash

### Testing Times (list)

1. **1k**: file read - 0.012 s, file sort - 0 s, file distribution - 0 s, print - 0.026 s, total - 0.039 s
2. **10k**: file read - 0.120 s, file sort - 0.013 s, file distribution - 0.006 s, print - 0.107 s, total - 0.247 s
3. **100k**: file read - 0.896 s, file sort - 0.114 s, file distribution - 0.025 s, print - 0.923 s, total - 1.957 s
4. **1m**: file read - 6.827 s, file sort - 1.373 s, file distribution - 0.240 s,, print - 9.042 s, total - 17.482 s
5. **10m**: file read - 85.4399 s, file sort - 19.862 s, file distribution - crash

### Testing Times (deque)

1. **1k**: file read - 0.011 s, file sort - 0 s, file distribution - 0.002 s, print - 0.029 s, total - 0.042 s
2. **10k**: file read - 0.122 s, file sort - 0.014 s, file distribution - 0.008 s, print - 0.097 s, total - 0.241 s
3. **100k**: file read - 0.872 s, file sort - 0.155 s, file distribution - 0.029 s, print - 0.919 s, total - 1.975 s
4. **1m**: file read - 6.814 s, file sort - 2.071 s, file distribution - 0.276 s,, print - 9.293 s, total - 18.454 s
5. **10m**: file read - 82.723 s, file sort - 29.637 s, file distribution - crash

### System Parameters
**CPU** i7-13650HX
**RAM** 24GB 4800MHz
**Storage** NVMe SSD