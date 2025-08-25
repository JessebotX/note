package main

import (
	"fmt"
	"os"
)

func main() {
	fmt.Println("Hello, world!")
	fmt.Printf("%+v\n", os.Args)
}
