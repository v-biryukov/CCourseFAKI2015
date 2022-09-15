void printBytes(std::string* ps)
{
    for (unsigned char* p = (unsigned char*)ps; p - (unsigned char*)ps < sizeof(std::string); ++p)
    {
        cout << std::hex << std::setw(3) << (int)*p << std::dec << " ";
    }
    cout << endl;

    for (unsigned char* p = (unsigned char*)ps; p - (unsigned char*)ps < sizeof(std::string); ++p)
    {
        cout << std::setw(3) << (int)*p << std::dec << " ";
    }
    cout << endl;

    for (unsigned char* p = (unsigned char*)ps; p - (unsigned char*)ps < sizeof(std::string); ++p)
    {
        cout << std::setw(3) << *p << "  ";
    }
    cout << endl;
}