# Key Header logic

[![Build Status](https://travis-ci.org/jbussdieker/c-key_header_support.png?branch=master)](https://travis-ci.org/jbussdieker/c-key_header_support)

Simple library for supporting the various matchers defined in http://tools.ietf.org/html/draft-fielding-http-key-00

# Usage

## word_matcher

```c
int word_matcher(char *p, char *fv, int case_sensitive)
```
Match a whole word in the field list.

### Returns

* 1 for match
* 0 for no match

### Parameters

* p: The paramter part of the matcher.
* fv: String representing the field values.
* case_sensitive: 
  * 1 for case-sensitive
  * 0 for case-insensitive

## substring_matcher

```c
int substring_matcher(char *p, char *fv, int case_sensitive)
```
Match a substring within the field list.

### Returns

* 1 for match
* 0 for no match

### Parameters

* p: The paramter part of the matcher.
* fv: String representing the field values.
* case_sensitive: 
  * 1 for case-sensitive
  * 0 for case-insensitive

## beginning_substring_matcher

```c
int beginning_substring_matcher(char *p, char *fv, int case_sensitive)
```
Match a substring occuring at the beginning of any value within the field list.

### Returns

* 1 for match
* 0 for no match

### Parameters

* p: The paramter part of the matcher.
* fv: String representing the field values.
* case_sensitive: 
  * 1 for case-sensitive
  * 0 for case-insensitive
