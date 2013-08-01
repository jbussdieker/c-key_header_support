# Key Header logic

[![Build Status](https://travis-ci.org/jbussdieker/c-key_header_support.png?branch=master)](https://travis-ci.org/jbussdieker/c-key_header_support)

Simple library for supporting the various matchers defined in http://tools.ietf.org/html/draft-fielding-http-key-00

# Usage

```c
word_matcher("foo", "foo,bar", 0);
substring_matcher("oobar", "foobar", 0);
beginning_substring_matcher("foo", "foobar", 0);
```
