package main

import (
	"fmt"
	"os"

	"github.com/JessebotX/mknote/opts"
)

type NewCommand struct {
	Init    InitCommand
	TestInt int
}

type InitCommand struct {
	TestInt int
}

var cli struct {
	New     NewCommand
	TestInt int
}

func main() {
	fmt.Println("Hello, world!")
	fmt.Printf("%+v\n", os.Args)

	ctx, err := opts.Parse(os.Args, &cli)
	if err != nil {
		errExit(2, err.Error())
	}
	_ = ctx
	fmt.Println("Goodbye, World!")
}

func errExit(code int, format string, a ...any) {
	fmt.Fprintf(os.Stderr, "error: "+format+"\n", a...)
	os.Exit(code)
}
