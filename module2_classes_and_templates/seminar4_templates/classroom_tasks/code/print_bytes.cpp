
template <typename T>
void printBytes(const T& el)
{
    const unsigned char* p = reinterpret_cast<const unsigned char*>(&el);
    
    for (size_t i = 0; i < sizeof(T); ++i)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(p[i]) << " ";
    std::cout << "\n";
}

