// direct hashing

void directHashing(int hashTable[], int key, int tableSize) {
    int index = key % tableSize;
    hashTable[index] = key;
}

// linear probing

void linearProbing(int hashTable[], int key, int tableSize) {
    int index = 0;
    index = ((key % tableSize) + i) % tableSize;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            break;
        }
    }
}

void quadraticProbing(int hashTable[], int key, int tableSize) {
    int index = 0;
    index = ((key % tableSize) + (i*i)) % tableSize;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[index] == -1) {
            hashTable[index] = key;
            break;
        }
    }
}

void hash1(int key, int tableSize) {
    return key % tableSize;
}

void hash2(int key, int primeNum) {
    return primeNum - (key % primeNum);
}

void doubleHashing(int hashTable[], int key, int tableSize) {
    int index = 0;
    
    for (int i = 0; i < tableSize; i++) {
        index = ((hash1(key,tableSize)) + (i*hash2(key,5))) % tableSize;
        if hashTable[index] == -1 {
            hashTable[index] = key;
            break;
        }
    }
}

void separateChaining(node* hashTable[], int val) {
    int index = val % 10;
    node *tmp = new node(val);

    if (hashTable[index] == nullptr) {
        hashTable[index] = tmp;
    } else {
        node *curr = hashTable[index];
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = tmp;
    }
}