    auto GetNamePoolChunk = [](int index) -> uint64_t
    {
        const uint32_t chunkIndex = index >> 16;
        const uint16_t nameEntryIndex = static_cast<uint16_t>(index);
        const uintptr_t gnames_addr = base_address + OFFSETS::GNAMES;
 
        uintptr_t chunk_ptr_address = gnames_addr + ((uint64_t)chunkIndex + 0xDF2) * 8;
        uint64_t chunkPtr = read64(chunk_ptr_address);
        uint64_t namePoolChunk = chunkPtr + (2 * nameEntryIndex);
 
        return namePoolChunk;
    };
    auto GetLength = [](uint16_t header) -> int32_t
    {
        return (header >> 1) & 0x3FF ^ 0x8Fu;
    };
 
if ((header & 0x7FE) == 0x11E)
    {
        decryptedIndex = DecryptIndex(read<int32_t>(NamePoolChunk + 6));
        if (decryptedIndex == -1)
            return {};
 
        NamePoolChunk = GetNamePoolChunk(decryptedIndex);
        if (!NamePoolChunk)
            return {};
 
        header = read<uint16_t>(NamePoolChunk);
    }
 
 
void sdk::FName::DecryptFNameAW(char *buffer, const int length, uint16_t header)
{
    std::vector<uint8_t> temp(buffer, buffer + length);
    {
        uint32_t len = static_cast<uint32_t>(length);
 
        int32_t key2 = length;
        for (uint32_t i = 0; i < len; ++i)
        {
            char key = 0x78 * key2;
            key2 = 0xFFFFDD78 * key2 - 28583984;
            *(_BYTE *)(buffer + i) = key + ~temp[i] - 127;
        }
    }
    buffer[length] = '\0';
}
 
int32_t sdk::FName::DecryptIndex(int32_t index)
{
    if (index == 0)
    {
        return 0;
    }
 
    int v3 = ((index - 1) ^ 0xF54D6F37) + 1;
    int v4 = 0xAB290C9;
    if (v3)
        v4 = v3;
 
    return static_cast<int32_t>(v4);
}
