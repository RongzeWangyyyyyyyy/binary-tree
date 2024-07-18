CFLAGS += -std=gnu11 -g
EXES = BinaryTree

all:	$(EXES)
clean:
	-rm -f $(EXES)

BinaryTree: BinaryTree.c
	BinaryTree
# don't treat all and clean as file targets
.PHONY: all clean