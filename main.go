package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintln(os.Stderr, "Error: invalid command. See command `help` for more information")
		os.Exit(1)
	}

	command := os.Args[1]
	options := os.Args[2:]

	if command == "new" {
		title := "DEFAULT TITLE"
		if len(options) >= 1 {
			title = options[0]
		}

		tags := make([]string, 0)
		if len(options) >= 2 {
			tags = options[1:]
		}

		note := NewNote(title, tags)
		fmt.Println(note.Title, note.Tags, note.FileName)
	} else {
		fmt.Fprintf(os.Stderr, "Error: invalid command %v. See command `help` for more information\n", command)
		os.Exit(1)
	}
}

