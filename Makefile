GOEXE = go
GOFMTEXE = gofmt
GOFMTFLAGS = -s -w -l
GOFMTTARGET = **/*.go
GOLINTEXE = staticcheck
GOLINTFLAGS =
GOLINTTARGET = **/*.go

all: build

build:
	$(GOEXE) build

fmt: format
format:
	$(GOFMTEXE) $(GOFMTFLAGS) $(GOFMTTARGET)

check: lint
vet: lint
lint:
	$(GOLINTEXE) $(GOLINTFLAGS) $(GOLINTTARGET)

clean: clean-testdata clean-bin

clean-testdata:
	@# ...

clean-bin:
	rm -f mknote mknote.exe
