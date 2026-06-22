// ------------ DIRECT HASHING -------------------

void directHashing(int hashTable[], int key, int tableSize) {
    int index = key % tableSize;
    hashTable[index] = key;
}

// ------------ LINEAR HASHING -------------------


void linearHashing(int hashTable[], int key, int tableSize) {
    int index = 0;
    for (int i = 0; i < tableSize; i++) {
        index = ((key % tableSize) + i) % tableSize;
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            break;
        }
    }
}

// ------------ QUADRATIC PROBING -------------------


void quadraticProbing(int hashTable[], int key, int tableSize) {
    int index = 0;
    for (int i = 0; i < tableSize; i++) {
        key = ((key % tableSize) + (i * i)) % tableSize;
        if (hashTable[index] = -1) {
            hashTable[index] = key;
            break;
        }
    }
}

// ------------ DOUBLE HASHING -------------------

int hash1(int key, int tableSize) {
    return key % tableSize;
}

int hash2(int key, int primeNum) {
    return (primeNum - (key % primeNum));
}

void doubleHashing(int hashTable[], int key, int tableSize) {
    int index = 0;
    for (int i = 0; i < tableSize; i++) {
        index = (hash1(key, tableSize) + (i * hash2(key, 7))) % tableSize;
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            break;
        }
    }
}

// ------------ SEPARATE CHAINING -------------------


void separateChaining(node *hashTable[], int val) {
    int index = val % 10;
    node *temp = new node(val);

    if (hashTable[index] == nullptr) {
        hashTable[index] = temp;
    } else {
        node *curr = hashTable[index];
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}