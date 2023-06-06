package main

import (
	"fmt"
	"os"
	"path/filepath"
)

type Config struct {
	NoteDirectory string `json:"note_directory"`
	Editor        string `json:"editor"`
}

var NoteConfigDirectoryEnvVar string = "NOTE_DIRECTORY"
var DefaultConfigContents []byte = []byte(`{
	"note_directory": "~/Documents/notes",
	"editor": "Notepad.exe"
}`)

func main() {
	if len(os.Args) < 2 {
		fmt.Fprintln(os.Stderr, "Error: invalid command. See command `help` for more information")
		os.Exit(1)
	}

	err := readFromConfig()
	if err != nil {
		fmt.Fprintln(os.Stderr, "Error:", err)
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

		note := InitNote(title, tags)
		fmt.Println(note.Title, note.Tags, note.FileName)
	} else {
		fmt.Fprintf(os.Stderr, "Error: invalid command %v. See command `help` for more information\n", command)
		os.Exit(1)
	}
}

func readFromConfig() error {
	var configFilePath string
	if os.Getenv(NoteConfigDirectoryEnvVar) == "" {
		xdgConfigHome, err := os.UserConfigDir()
		if err != nil {
			return err
		}

		configFilePath = filepath.Join(xdgConfigHome, "note", "config.json")
	} else {
		configFilePath = os.Getenv(NoteConfigDirectoryEnvVar)
	}

	configFileContents, err := os.ReadFile(configFilePath)
	if err != nil {
		configFileContents = DefaultConfigContents

		err := writeDefaultConfig(configFilePath)
		if err != nil {
			return err
		}
	}

	fmt.Print(string(configFileContents))

	return nil
}

func writeDefaultConfig(configFilePath string) (error) {
	configPathDir := filepath.Dir(configFilePath)

	err := os.MkdirAll(configPathDir, 0755)
	if err != nil {
		return err
	}

	writeErr := os.WriteFile(configFilePath, DefaultConfigContents, 0644)
	if writeErr != nil {
		return err
	}

	return nil
}
