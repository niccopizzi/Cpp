#include <iostream>
#include <fstream>
#include <string>

int sed(char *filename, char *s1, char *s2)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     newFilename;
    std::string     line;

    infile.open(filename);
    if (infile.fail())
    {
        std::cout << "Failed to open the file to read\n";
        return (1);
    }
    newFilename = filename;
    newFilename += ".replace";
    outfile.open(newFilename.c_str(), std::ofstream::trunc);
    if (outfile.fail())
    {
        std::cout << "Failed to open thenew file\n";
        infile.close();
        return (2);
    }
    while (getline(infile, line))
    {
        if (!line.compare(s1))
            line = s2;
        outfile << line;
        if (!infile.eof())
            outfile<<"\n";
    }
    outfile.close();
    infile.close();
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid usage, please insert\n";
        std::cout << "1) <filename>\n";
        std::cout << "2) <string to replace>\n";
        std::cout << "3) <string to insert>\n";
        return (1);
    }

    if (!argv[1][0] || !argv[2][0] || !argv[3][0])
    {
        std::cout << "Error, paramaters cannot be empty\n";
        return (2);
    }
    return (sed(argv[1], argv[2], argv[3]));
}
