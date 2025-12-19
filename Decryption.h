inline uint64_t DecryptUWorld(uint64_t encrypted) {
    return _rotl64(encrypted, 56) - 603662288ULL;
}
