# lidwoord
A simple CLI tool to return the article (lidwoord) for a Dutch word.

This tool uses the website https://www.welklidwoord.nl to pull its information.
I am in no way affiliated with them.

This has only be tested on macOS.

## Instructions
**Command**
`$ ./lidwoord paard`

**Output**
```
het paard

Source: https://www.welklidwoord.nl/paard
```


## Requirements
This tool uses the `curl` and `pcre` libraries.

## Compiling
You can use the `make install` command or `make test` command to run it.
