# Makefile for befuge

# Color codes
RESET := \033[0m
GREEN := \033[0;1;32m
WHITE := \033[0;1m

# Variables
NAME := befuge
HDRDIR := include
SRCDIR := src
OBJDIR := obj
BINDIR := bin
HDRS := $(wildcard $(HDRDIR)/$(NAME)/*/*.h)
SRCS := $(wildcard $(SRCDIR)/*/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TARGET := $(BINDIR)/$(NAME)
CC := gcc
CFLAGS := -Wall -Wextra -I$(HDRDIR)/

# Phony targets
.PHONY: all build clean
all: build
build: $(TARGET)
clean:
	@echo "$(WHITE)Cleaning...$(RESET)"
	rm -rf $(OBJDIR)/ $(BINDIR)/
	@echo

# Rules
$(TARGET): $(OBJS)
	@echo "$(WHITE)Building target $(GREEN)$@$(WHITE)...$(RESET)"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	@echo "$(WHITE)Building object $(GREEN)$@$(WHITE) from $(GREEN)$<$(WHITE)...$(RESET)"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo
