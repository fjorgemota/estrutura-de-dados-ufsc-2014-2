.PHONY: build-tests
.PHONY: clean-tests
.PHONY: run-tests
.PHONY: tests
SHELL := /bin/bash
BUILD_DIR := /tmp/estrutura-de-dados-ufsc-2014-2/build
FILES := `ls -1 | grep .cpp | sed 's/\.cpp//'`
test: build-tests run-tests clean-tests
build-tests:
	mkdir -p $(BUILD_DIR)
	for FILE in $(FILES); do\
		TEST_FILE="`echo $$FILE`Test";\
		g++ -o $(BUILD_DIR)/$$FILE tests/$$TEST_FILE.cpp -lgtest -lpthread -I.; \
	done;
run-tests:
	for TEST_EXEC in $(FILES); do\
		$(BUILD_DIR)/$$TEST_EXEC; \
		if [ "$$?" != "0" ]; then \
		    exit "$$?"; \
		fi; \
	done;
clean-tests:
	rm -Rf $(BUILD_DIR)