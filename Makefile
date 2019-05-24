BUILD=build
MAIN=test
SILENT=false
ifeq ($(SILENT), true)
SILENCE=-silent
endif

.PHONY: all clean %
.PRECIOUS: %.man
all: $(MAIN).pdf $(MAIN).man.pdf

%.pdf: %.tex | $(BUILD)
	latexmk $(SILENCE) -pdf -outdir=$(BUILD) $<
	cp build/$@ $@

%.man: %.tex
	latex2man $< $@

%.man.pdf: %.man
	man -t $(abspath $<) | pstopdf -i -o $@

%: %.man
	man $(abspath $<)

build:
	@mkdir -p $(BUILD)

clean:
	@rm -rf $(BUILD) *.man *.pdf
