# Befuge: Command line Befunge 93, 96, 97 and 98 interpreter and debugger

Befuge is a command-line utility for development with the esoteric
programming language [Befunge](https://esolangs.org/wiki/Befunge) and
its variants. Although befunge is just a bit useless, this tool was
created for people who see its real power and dare to use it.

## Features

Befuge has the following features:
 
 * Full Befunge-93, Befunge-96, Funge-97 and Funge-98 support

 * Settings for certain commonly changed or unspecified befunge 93
   behavior (e.g, integer size, extra instructions, grid size, divide by 0)

 * Syntax highlighting

 * Debug mode: visual grid, breakpoints, single-stepping

## Usage

To use Befuge, just download or install or obtain the program somehow.

Befuge is a command line program. To use it, type

```sh
befuge program.bf
```

This will run Befuge in Interpreter mode (which is the default), 
interpreting `program.bf` as Befunge-93 (which is the default). 
To go in debug mode (which has nicer features), use the `-D` option.

```sh
befuge -D program.bf
```

This will create a text UI where you can see the grid and run the program.
