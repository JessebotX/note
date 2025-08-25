package opts

type Context struct {
	Commands []string
	Rest     []string
}

func Parse(args []string, cli any) (Context, error) {
	return Context{}, nil
}
