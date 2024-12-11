
## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [How It Works](#how-it-works)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Examples](#examples)
7. [Acknowledgments](#acknowledgments)

## Introduction

Minishell is a simplified Bash replica designed to provide a foundational understanding of shell functionality. By implementing system calls like `fork`, `execve`, and `pipe`, it emphasizes how shells interpret and execute user commands.

## Features

- Logical operators: `&&` and `||` for conditional command execution.
- Piping: Chain commands using `|`.
- Redirections: Support for `>`, `<`, and `>>`.
- Heredocs: Handle multiline input with `<<`.
- Signal handling: Gracefully manages `CTRL+C`, `CTRL+\\`, and `CTRL+D`.
- Environment variable expansion: Dynamically substitute variables like `$PATH` or `$HOME` during command execution as well as managing expansions inside heredocs.

## How It Works

Minishell parses user input, creates a linked list of commands, and executes them step-by-step:

1. **Lexing and Parsing**: User input is tokenized into commands and operators.
2. **Execution**:
   - Commands are executed in child processes using `fork` and `execve`.
   - Pipes are managed via `pipe()` for inter-process communication.
   - Logical operators determine whether subsequent commands are executed based on the success or failure of previous ones.
   - Redirections manipulate file descriptors to redirect input/output.
3. **Environment Variables**: Custom environment handling ensures commands execute in a controlled environment.
   - Dynamically expands variables like `$PATH` or `$USER` during execution.
4. **Error Handling**: Displays meaningful error messages for invalid commands or syntax.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Cremdemout1/Minishell.git
   cd Minishell
   ```
2. Compile the project:
   ```bash
   make
   ```
3. Run the shell:
   ```bash
   ./minishell
   ```

## Usage

Minishell provides an interactive shell environment where you can execute commands, combine them using logical operators and pipes, and utilize redirection and heredocs for more advanced functionality.

### Basic Commands
Run commands directly as you would in a standard shell:
```bash
ls -la
echo "Hello, Minishell!"
pwd
```

### Piping
Redirect the output of one command as the input to another:
```bash
ls -la | grep minishell
```

### Logical Operators
Control command execution flow with `&&` and `||`:
```bash
mkdir test && cd test || echo "Failed to create directory."
```

### Input/Output Redirection
Redirect output to a file, append output, or read input from a file:
```bash
echo "Testing redirection" > output.txt
cat < output.txt
ls >> log.txt
```

### Heredocs
Provide multi-line input directly to commands:
```bash
cat << EOF
Welcome to Minishell!
This is a heredoc example.
EOF
```

### Environment Variable Expansion
Use variables dynamically during command execution:
```bash
echo $PATH
echo "Hello, $USER!"
```

## Examples

### Example 1: Combining Pipes and Redirection
```bash
ls -la | grep minishell > results.txt
```
This command lists all files, filters results containing "minishell," and writes the output to `results.txt`.

### Example 2: Logical Operators
```bash
cat file.txt && echo "File exists." || echo "File does not exist."
```
If `file.txt` exists, its contents are printed, followed by "File exists." Otherwise, "File does not exist." is displayed.

### Example 3: Advanced Heredoc Usage
```bash
cat << EOF | grep shell
Welcome to Minishell
This shell supports heredocs
EOF
```
This command takes multi-line heredoc input and filters lines containing the word "shell."

### Example 4: Environment Variable Expansion
```bash
echo "Current path: $PWD"
export CUSTOM_VAR="Minishell"
echo "Using $CUSTOM_VAR for learning!"
```
Expand and manipulate environment variables dynamically during runtime.

## Acknowledgments

Minishell was collaboratively developed as part of the 42 curriculum by [BrunoBMFT](https://github.com/BrunoBMFT) and myself. This project reflects our commitment to mastering Unix system programming and building robust, efficient software. We thank the 42 community for their guidance and support throughout the journey.

