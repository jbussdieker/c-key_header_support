#include <stdio.h>
#include <string.h>

int cmp_func(const char *str1, const char *str2, int size, int case_sensitive) {
  if (case_sensitive == 1)
    return strncmp(str1, str2, size);
  else
    return strncasecmp(str1, str2, size);
}

int word_matcher(char *p, char *fv, int case_sensitive) {
    int read, size, offset = 0;
    const char *match;

    while (read = enum_fields(fv + offset, &match, &size)) {
	if (strlen(p) == size) {
	    if (cmp_func(match, p, size, case_sensitive) == 0) {
		return 1;
	    }
	}
	offset += read;
    }
    return 0;
}

#ifdef TESTS
int fancy = 0;

void print_special(const char *msg) {
    printf("\033[1;30m%s\033[00m", msg);
}

void print_literal(const char *msg) {
    printf("\033[1;31m%s\033[00m", msg);
}

int run_test(char *p, char *fv, int case_sensitive, int expect) {
    if (fancy)
	printf("[....] ");

    printf("Testing that ");
    print_special("\"");
    print_literal(p);
    print_special("\"");
    printf(" %s ", expect == 1 ? "matches" : "doesn't match");
    print_special("\"");
    print_literal(fv);
    print_special("\"");
    printf(" %s", case_sensitive == 0 ? "" : "(CASE SENSITIVE)");
    if (fancy)
	printf("\r");
    else
	printf("\n");

    if (word_matcher(p, fv, case_sensitive) != expect) {
	printf("[\033[0;31mFAIL\033[00m]\n");
	return 1;
    } else {
	printf("[\033[0;32mPASS\033[00m]\n");
	return 0;
    }
}

int main(int argc, char **argv) {
    int result = 0;

    fancy = argc == 2 ? 0 : 1;

    result |= run_test("foo", "foo", 0, 1);
    result |= run_test("foo", "Foo", 0, 1);
    result |= run_test("foo", "Foo", 1, 0);
    result |= run_test("foo", "foo,bar", 0, 1);
    result |= run_test("foo", "bar,foo,bar", 0, 1);
    result |= run_test("foo", "foobar", 0, 0);
    result |= run_test("\"foo,bar\"", "bar,\"foo,bar\",bar", 0, 1);

    return result;
}
#endif
