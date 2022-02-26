#include <stdio.h>


bool strcom(char firstarray[], char secondarray[])
{
    for (int i = 0; i < 7; i++)
    {
        if (firstarray[i] != secondarray[i]) return false;
    }
    return true;
}


int main()
{
    const int rows = 4;
    const int columns = 7;

    char keywords[rows][columns] = {
        "int",
        "float",
        "double",
        "char"
    };

    const char input[] = "test float double char";

    int r = 0;
    int element = 0;
    int word = 0;

    for (int i = 0; i < sizeof(input); i++)
    {
        if (input[i] == ' ') r++;
    }


    r++;
    char parsed[r][columns];

    // filling matrix | заполнение матрицы
    for (int i = 0; i < sizeof(input); i++)
    {
        if (input[i] == ' ')
        {
            if (element < columns)
            {
                for (; element < sizeof(keywords); element++) parsed[word][element] = '\0';
            }

            word++;
            element = 0;
        }
        else
        {
            parsed[word][element] = input[i];
            element++;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (strcom(parsed[i], keywords[j]) == true) printf("%s\n", parsed[i]);
        }
    }
}
