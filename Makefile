FILES=example first
BIN=bin
BUILD=build
TMPDIRS=$(BIN) $(BUILD)

.PHONY: all $(FILES)
.PRECIOUS: $(BUILD)/%.ll
all: $(FILES)

$(BUILD)/%.ll: %.c | $(BUILD)
	clang -emit-llvm -S $< -o $@

$(BUILD)/%.s: $(BUILD)/%.ll | $(BUILD)
	llc $< -o $@
$(BUILD)/%.s: %.ll | $(BUILD)
	llc $< -o $@

$(FILES): %: $(BIN)/%
$(BIN)/%: $(BUILD)/%.s | $(BIN)
	gcc $< -o $@

$(TMPDIRS):
	@mkdir -p $@

clean:
	rm -rf $(TMPDIRS)
