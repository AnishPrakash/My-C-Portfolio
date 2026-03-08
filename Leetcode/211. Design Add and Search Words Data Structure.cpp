typedef struct WordDictionary {
    struct WordDictionary* children[26];
    bool isEnd;
} WordDictionary;

WordDictionary* wordDictionaryCreate() {
    WordDictionary* node = (WordDictionary*)malloc(sizeof(WordDictionary));
    node-a>isEnd = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    WordDictionary* curr = obj;
    while (*word) {
        int idx = *word - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = wordDictionaryCreate();
        }
        curr = curr->children[idx];
        word++;
    }
    curr->isEnd = true;
}

bool searchHelper(WordDictionary* node, char* word) {
    if (!node) return false;
    if (*word == '\0') return node->isEnd;

    if (*word == '.') {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] && searchHelper(node->children[i], word + 1)) {
                return true;
            }
        }
        return false;
    } else {
        int idx = *word - 'a';
        return node->children[idx] && searchHelper(node->children[idx], word + 1);
    }
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchHelper(obj, word);
}

void wordDictionaryFree(WordDictionary* obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        wordDictionaryFree(obj->children[i]);
    }
    free(obj);
}