#ifndef LANGUAGE_CLASSIFIER_H
#define LANGUAGE_CLASSIFIER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "collections.h"
#include "language_features.h"
#include "logistic_regression.h"
#include "tokens.h"
#include "string_utils.h"
#include "trie.h"

#define LANGUAGE_CLASSIFIER_FILENAME "language_classifier.dat"
#define LANGUAGE_CLASSIFIER_COUNTRY_FILENAME "language_classifier_country.dat"

typedef struct language_classifier {
    size_t num_labels;
    size_t num_features;
    trie_t *features;
    cstring_array *labels;
    matrix_t *weights;
} language_classifier_t;


typedef struct language_classifier_response {
    size_t num_languages;
    char **languages;
    double *probs;
} language_classifier_response_t;

// General usage

language_classifier_t *language_classifier_new(void);
language_classifier_t *get_language_classifier(void);
language_classifier_t *get_language_classifier_country(void);

language_classifier_response_t *classify_languages(char *address, char *country);

void language_classifier_destroy(language_classifier_t *self);

// I/O methods

language_classifier_t *language_classifier_load(char *path);
bool language_classifier_save(language_classifier_t *self, char *output_dir);

// Module setup/teardown

bool language_classifier_module_setup(char *dir);
void language_classifier_module_teardown(void);


#endif