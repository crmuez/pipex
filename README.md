# Pipex 🖥️🔗

**Pipex** is a command-line program implemented in Linux that simulates the behavior of a Unix pipe. This project is part of the curriculum at the 42 campus and was developed in a Linux environment.

## Description 📄

The `pipex` program allows you to redirect the output of one command to the input of another using pipes, mimicking the behavior of Unix pipes.

### Features ✨:
- **Pipe Simulation**: The program takes two or more commands, connects them via pipes, and executes the command sequence, passing the output of one command as input to the next.
- **File Redirection**: The program also supports file redirection, allowing commands to process data from an input file or write the result to an output file.

## Files 📂

- `pipex.c and prequel-pipex.c`: Main file containing the core logic of the program.
- `utils/`: Custom functions not available in the standard C library.
- `Makefile`: Build file to compile the project.

## Notes 📝

This project is a low-level implementation using concepts of process management and inter-process communication in a Linux environment. The use of pipes, redirection, and process management is fundamental to understanding how inter-process communication works in Unix.

## Contributions 🙌

This project was developed as part of the 42 campus curriculum and was done individually. No additional functionality (bonuses) was implemented.
