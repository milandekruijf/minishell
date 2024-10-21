<h1 align="center"><strong>Minishell</strong></h1>
<div align="center">Minishell is a collaborative team project developed as part of the curriculum at 42 School, aimed at creating a basic shell program in C. This project serves as a practical exercise in systems programming, enabling students to deepen their understanding of operating system concepts and the C programming language.</div>
<br />
<div align="center">
  <a href="AUTHORS.md">Authors</a>
  <span>·</span>
  <a href="https://42.fr">42</a>
  <span>·</span>
  <a href="https://www.codam.nl">Codam</a>
</div>

## Usage

### Prerequisites

Clone the repository to your local machine using the following command in the terminal.

```sh
git clone https://github.com/milandekruijf/minishell.git && cd minishell
```

### Compiling

In order to compile the Minishell program, run the following command in the project root directory.

```sh
make
```

### Running

After compiling, the executable `minishell` will be created in the `out` directory. Run the executable to start Minishell.

```sh
./out/minishell
```

### Testing

Run the tests

```sh
make test
```

## Features

Minishell is a lightweight shell program inspired by Bash, designed to provide essential shell functionalities. Below are the key features supported by Minishell.

### General

- Prompt Display: A user-friendly prompt that indicates readiness for commands.
- Command History: Navigate through previously executed commands using the up and down arrow keys.
- System Executables: Execute standard system commands like `ls`, `cat`, `grep`, etc.
- Local Executables: Run local executables from the current working directory.

### Builtin Commands

Minishell supports the following built-in commands:

- `echo`: Displays messages, with an option for no trailing newline (`-n`).
- `cd`: Changes the current directory using either relative or absolute paths.
- `pwd`: Outputs the current working directory (no options).
- `export`: Lists environment variables without options.
- `unset`: Removes environment variables without options.
- `env`: Displays the current environment variables without options or arguments.
- `exit`: Terminates Minishell, with an optional exit status.

### Input/Output Management

- Pipes (`|`): Redirects the output of one command to the input of another, enabling command chaining.
- Redirections:
  - `>`: Redirects output to a file (overwriting).
  - `>>`: Redirects output to a file (in append mode).
  - `<`: Redirects input from a file.
  - `<<`: Allows for here-document input, prompting the user for input until the specified delimiter is reached. This input is redirected to the command but does not update command history.

### Environment Variable Expansion

- Support for environment variable expansion, allowing variables like `$USER` or custom variables (e.g. `$MS_PROMPT`) to resolve to their corresponding values.
- The special variable `$?` returns the exit status of the most recently executed foreground pipeline.

### User Keyboard Signals

- User keyboard signals:
  - `Ctrl-C`: Cancels the current command and displays a new prompt.
  - `Ctrl-D`: Exits Minishell gracefully.
  - `Ctrl-\`: Has no effect in the Minishell environment.

### Limitations

Minishell does not support the following:

- Escape character (`\`)
- Command separators (`;`)
- Logical operators (`&&`, `||`)
- Wildcards (`*`)

## Acknowledgements

- [Acutest](https://github.com/mity/acutest): A minimal C unit testing framework used for testing individual functions.
- [42](https://42.fr): The educational institution that inspired and supported the development of this project.
- [Codam](https://www.codam.nl): The partner school of 42 in the Netherlands, where the project was developed.
